#include "ProxyStubsValidator.h"

#include "ExpectedValues.h"

namespace WPEFramework {
namespace Plugin {

SERVICE_REGISTRATION(ProxyStubsValidator, 1, 0);

/* virtual */ const string ProxyStubsValidator::Initialize(PluginHost::IShell* service)
{
    /*Assume that everything is OK*/
    string message = _T("");

    ASSERT(service != nullptr);
    ASSERT(_service == nullptr);
    ASSERT(_proxyStubsValidatorImp == nullptr);

    _service = service;
    _skipURL = static_cast<uint8_t>(_service->WebPrefix().length());
    _service->Register(&_notification);

    _proxyStubsValidatorImp
        = _service->Root<Exchange::IProxyStubsValidator>(_pid, ImplWaitTime, _T("ProxyStubsValidatorImp"));

    if ((_proxyStubsValidatorImp == nullptr) && (_service == nullptr))
    {
        ProcessTermination(_pid);
        _service = nullptr;
        _proxyStubsValidatorImp = nullptr;
        _service->Unregister(&_notification);

        TRACE(Trace::Fatal, (_T("*** ProxyStubsValidator could not be instantiated ***")))
        message = _T("ProxyStubsValidator could not be instantiated.");
    }

    return message;
}

/* virtual */ void ProxyStubsValidator::Deinitialize(PluginHost::IShell* service)
{
    ASSERT(_service == service);
    ASSERT(_proxyStubsValidatorImp != nullptr);
    ASSERT(_pid);

    TRACE(Trace::Information, (_T("*** OutOfProcess Plugin is properly destructed. PID: %d ***"), _pid))

    ProcessTermination(_pid);
    _proxyStubsValidatorImp = nullptr;
    _service->Unregister(&_notification);
    _service = nullptr;
}

/* virtual */ string ProxyStubsValidator::Information() const
{
    // No additional info to report.
    return ((_T("The purpose of this plugin is provide ability to validate proxy/stubs generation mechanism.")));
}

/* virtual */ void ProxyStubsValidator::Inbound(Web::Request& request)
{
    return;
}

/* virtual */ Core::ProxyType<Web::Response> ProxyStubsValidator::Process(const Web::Request& request)
{
    ASSERT(_skipURL <= request.Path.length());
    Core::ProxyType<Web::Response> result(PluginHost::Factories::Instance().Response());
    result->ErrorCode = Web::STATUS_BAD_REQUEST;
    result->Message = (_T("Method is not supported"));

    if ((request.Verb == Web::Request::HTTP_POST) || (request.Verb == Web::Request::HTTP_PUT))
    {
        Core::TextSegmentIterator index(
            Core::TextFragment(request.Path, _skipURL, request.Path.length() - _skipURL), false, '/');

        index.Next();
        index.Next();

        if (index.Current().Text() == _T("Execute") && (!index.Next()))
        {
            result->ErrorCode = Web::STATUS_OK;
            result->Message = Execute();
        }
    }

    return result;
}

void ProxyStubsValidator::ProcessTermination(uint32_t pid)
{
    RPC::IRemoteProcess* process(_service->RemoteProcess(pid));
    if (process != nullptr)
    {
        process->Terminate();
        process->Release();
    }
}

void ProxyStubsValidator::Activated(RPC::IRemoteProcess* /*process*/)
{
    return;
}

void ProxyStubsValidator::Deactivated(RPC::IRemoteProcess* process)
{
    if (_pid == process->Id())
    {
        ASSERT(_service != nullptr);
        PluginHost::WorkerPool::Instance().Submit(
            PluginHost::IShell::Job::Create(_service, PluginHost::IShell::DEACTIVATED, PluginHost::IShell::FAILURE));
    }
}

string ProxyStubsValidator::Execute(void)
{
    // ToDo: should be moved to other thread?
    string result = _T("");

    TestReturnByValue();
    TestReturnByConstValue();
    TestPassByValue();
    TestPassByConstValue();
    TestPassByReference();
    TestPassByConstReference();

    TRACE(Trace::Information, (_T("Pass: %d, Fail: %d, Total: %d"), _passCount, _failCount, _totalCount));

    return result = _T("Execute OK!");
}

void ProxyStubsValidator::TestReturnByValue()
{
    ASSERT(_proxyStubsValidatorImp != nullptr)
    TestResult<uint8_t>("ReturnByValue<uint8_t>", _proxyStubsValidatorImp->returnByValueUint8t(), Expected::Uint8t);
    TestResult<uint16_t>("ReturnByValue<uint16_t>", _proxyStubsValidatorImp->returnByValueUint16t(), Expected::Uint16t);
    TestResult<uint32_t>("ReturnByValue<uint32_t>", _proxyStubsValidatorImp->returnByValueUint32t(), Expected::Uint32t);
    TestResult<uint64_t>("ReturnByValue<uint64_t>", _proxyStubsValidatorImp->returnByValueUint64t(), Expected::Uint64t);
    TestResult<int8_t>("ReturnByValue<int8_t>", _proxyStubsValidatorImp->returnByValueInt8t(), Expected::Int8t);
    TestResult<int16_t>("ReturnByValue<int16_t>", _proxyStubsValidatorImp->returnByValueInt16t(), Expected::Int16t);
    TestResult<int32_t>("ReturnByValue<int32_t>", _proxyStubsValidatorImp->returnByValueInt32t(), Expected::Int32t);
    TestResult<int64_t>("ReturnByValue<int64_t>", _proxyStubsValidatorImp->returnByValueInt64t(), Expected::Int64t);
    TestResult<short>("ReturnByValue<short>", _proxyStubsValidatorImp->returnByValueShort(), Expected::Short);
    TestResult<short int>("ReturnByValue<short int>", _proxyStubsValidatorImp->returnByValueShortInt(), Expected::ShortInt);
    TestResult<signed short>("ReturnByValue<signed short>", _proxyStubsValidatorImp->returnByValueSignedShort(), Expected::SignedShort);
    TestResult<signed short int>("ReturnByValue<signed short int>", _proxyStubsValidatorImp->returnByValueSignedShortInt(), Expected::SignedShortInt);
    TestResult<unsigned short>("ReturnByValue<unsigned short>", _proxyStubsValidatorImp->returnByValueUnsignedShort(), Expected::UnsignedShort);
    TestResult<unsigned short int>("ReturnByValue<unsigned short int>", _proxyStubsValidatorImp->returnByValueUnsignedShortInt(), Expected::UnsignedShortInt);
    TestResult<int>("ReturnByValue<int>", _proxyStubsValidatorImp->returnByValueInt(), Expected::Int);
    TestResult<signed>("ReturnByValue<signed>", _proxyStubsValidatorImp->returnByValueSigned(), Expected::Signed);
    TestResult<signed int>("ReturnByValue<signed int>", _proxyStubsValidatorImp->returnByValueSignedInt(), Expected::SignedInt);
    TestResult<unsigned>("ReturnByValue<unsigned>", _proxyStubsValidatorImp->returnByValueUnsigned(), Expected::Unsigned);
    TestResult<unsigned int>("ReturnByValue<unsigned int>", _proxyStubsValidatorImp->returnByValueUnsignedInt(), Expected::UnsignedInt);
    TestResult<long>("ReturnByValue<long>", _proxyStubsValidatorImp->returnByValueLong(), Expected::Long);
    TestResult<long int>("ReturnByValue<long int>", _proxyStubsValidatorImp->returnByValueLongInt(), Expected::LongInt);
    TestResult<signed long>("ReturnByValue<signed long>", _proxyStubsValidatorImp->returnByValueSignedLong(), Expected::SignedLong);
    TestResult<signed long int>("ReturnByValue<signed long int>", _proxyStubsValidatorImp->returnByValueSignedLongInt(), Expected::SignedLongInt);
    TestResult<unsigned long>("ReturnByValue<unsigned long>", _proxyStubsValidatorImp->returnByValueUnsignedLong(), Expected::UnsignedLong);
    TestResult<unsigned long int>("ReturnByValue<unsigned long int>", _proxyStubsValidatorImp->returnByValueUnsignedLongInt(), Expected::UnsignedLongInt);
    TestResult<long long>("ReturnByValue<long long>", _proxyStubsValidatorImp->returnByValueLongLong(), Expected::LongLong);
    TestResult<long long int>("ReturnByValue<long long int>", _proxyStubsValidatorImp->returnByValueLongLongInt(), Expected::LongLongInt);
    TestResult<signed long long>("ReturnByValue<signed long long>", _proxyStubsValidatorImp->returnByValueSignedLongLong(), Expected::SignedLongLong);
    TestResult<signed long long int>("ReturnByValue<signed long long int>", _proxyStubsValidatorImp->returnByValueSignedLongLongInt(), Expected::SignedLongLongInt);
    TestResult<unsigned long long>("ReturnByValue<unsigned long long>", _proxyStubsValidatorImp->returnByValueUnsignedLongLong(), Expected::UnsignedLongLong);
    TestResult<unsigned long long int>("ReturnByValue<unsigned long long int>", _proxyStubsValidatorImp->returnByValueUnsignedLongLongInt(), Expected::UnsignedLongLongInt);
    TestResult<signed char>("ReturnByValue<signed char>", _proxyStubsValidatorImp->returnByValueSignedChar(), Expected::SignedChar);
    TestResult<unsigned char>("ReturnByValue<unsigned char>", _proxyStubsValidatorImp->returnByValueUnsignedChar(), Expected::UnsignedChar);
    TestResult<char>("ReturnByValue<char>", _proxyStubsValidatorImp->returnByValueChar(), Expected::Char);
    TestResult<float>("ReturnByValue<float>", _proxyStubsValidatorImp->returnByValueFloat(), Expected::Float);
    TestResult<double>("ReturnByValue<double>", _proxyStubsValidatorImp->returnByValueDouble(), Expected::Double);
    TestResult<long double>("ReturnByValue<long double>", _proxyStubsValidatorImp->returnByValueLongDouble(), Expected::LongDouble);
    TestResult<bool>("ReturnByValue<bool>", _proxyStubsValidatorImp->returnByValueBool(), Expected::Bool);
}

void ProxyStubsValidator::TestReturnByConstValue()
{
    ASSERT(_proxyStubsValidatorImp != nullptr)
    TestResult<uint8_t>("ReturnByConstValue<uint8_t>", _proxyStubsValidatorImp->returnByConstValueUint8t(), Expected::Uint8t);
    TestResult<uint16_t>("ReturnByConstValue<uint16_t>", _proxyStubsValidatorImp->returnByConstValueUint16t(), Expected::Uint16t);
    TestResult<uint32_t>("ReturnByConstValue<uint32_t>", _proxyStubsValidatorImp->returnByConstValueUint32t(), Expected::Uint32t);
    TestResult<uint64_t>("ReturnByConstValue<uint64_t>", _proxyStubsValidatorImp->returnByConstValueUint64t(), Expected::Uint64t);
    TestResult<int8_t>("ReturnByConstValue<int8_t>", _proxyStubsValidatorImp->returnByConstValueInt8t(), Expected::Int8t);
    TestResult<int16_t>("ReturnByConstValue<int16_t>", _proxyStubsValidatorImp->returnByConstValueInt16t(), Expected::Int16t);
    TestResult<int32_t>("ReturnByConstValue<int32_t>", _proxyStubsValidatorImp->returnByConstValueInt32t(), Expected::Int32t);
    TestResult<int64_t>("ReturnByConstValue<int64_t>", _proxyStubsValidatorImp->returnByConstValueInt64t(), Expected::Int64t);
    TestResult<short>("ReturnByConstValue<short>", _proxyStubsValidatorImp->returnByConstValueShort(), Expected::Short);
    TestResult<short int>("ReturnByConstValue<short int>", _proxyStubsValidatorImp->returnByConstValueShortInt(), Expected::ShortInt);
    TestResult<signed short>("ReturnByConstValue<signed short>", _proxyStubsValidatorImp->returnByConstValueSignedShort(), Expected::SignedShort);
    TestResult<signed short int>("ReturnByConstValue<signed short int>", _proxyStubsValidatorImp->returnByConstValueSignedShortInt(), Expected::SignedShortInt);
    TestResult<unsigned short>("ReturnByConstValue<unsigned short>", _proxyStubsValidatorImp->returnByConstValueUnsignedShort(), Expected::UnsignedShort);
    TestResult<unsigned short int>("ReturnByConstValue<unsigned short int>", _proxyStubsValidatorImp->returnByConstValueUnsignedShortInt(), Expected::UnsignedShortInt);
    TestResult<int>("ReturnByConstValue<int>", _proxyStubsValidatorImp->returnByConstValueInt(), Expected::Int);
    TestResult<signed>("ReturnByConstValue<signed>", _proxyStubsValidatorImp->returnByConstValueSigned(), Expected::Signed);
    TestResult<signed int>("ReturnByConstValue<signed int>", _proxyStubsValidatorImp->returnByConstValueSignedInt(), Expected::SignedInt);
    TestResult<unsigned>("ReturnByConstValue<unsigned>", _proxyStubsValidatorImp->returnByConstValueUnsigned(), Expected::Unsigned);
    TestResult<unsigned int>("ReturnByConstValue<unsigned int>", _proxyStubsValidatorImp->returnByConstValueUnsignedInt(), Expected::UnsignedInt);
    TestResult<long>("ReturnByConstValue<long>", _proxyStubsValidatorImp->returnByConstValueLong(), Expected::Long);
    TestResult<long int>("ReturnByConstValue<long int>", _proxyStubsValidatorImp->returnByConstValueLongInt(), Expected::LongInt);
    TestResult<signed long>("ReturnByConstValue<signed long>", _proxyStubsValidatorImp->returnByConstValueSignedLong(), Expected::SignedLong);
    TestResult<signed long int>("ReturnByConstValue<signed long int>", _proxyStubsValidatorImp->returnByConstValueSignedLongInt(), Expected::SignedLongInt);
    TestResult<unsigned long>("ReturnByConstValue<unsigned long>", _proxyStubsValidatorImp->returnByConstValueUnsignedLong(), Expected::UnsignedLong);
    TestResult<unsigned long int>("ReturnByConstValue<unsigned long int>", _proxyStubsValidatorImp->returnByConstValueUnsignedLongInt(), Expected::UnsignedLongInt);
    TestResult<long long>("ReturnByConstValue<long long>", _proxyStubsValidatorImp->returnByConstValueLongLong(), Expected::LongLong);
    TestResult<long long int>("ReturnByConstValue<long long int>", _proxyStubsValidatorImp->returnByConstValueLongLongInt(), Expected::LongLongInt);
    TestResult<signed long long>("ReturnByConstValue<signed long long>", _proxyStubsValidatorImp->returnByConstValueSignedLongLong(), Expected::SignedLongLong);
    TestResult<signed long long int>("ReturnByConstValue<signed long long int>", _proxyStubsValidatorImp->returnByConstValueSignedLongLongInt(), Expected::SignedLongLongInt);
    TestResult<unsigned long long>("ReturnByConstValue<unsigned long long>", _proxyStubsValidatorImp->returnByConstValueUnsignedLongLong(), Expected::UnsignedLongLong);
    TestResult<unsigned long long int>("ReturnByConstValue<unsigned long long int>", _proxyStubsValidatorImp->returnByConstValueUnsignedLongLongInt(), Expected::UnsignedLongLongInt);
    TestResult<signed char>("ReturnByConstValue<signed char>", _proxyStubsValidatorImp->returnByConstValueSignedChar(), Expected::SignedChar);
    TestResult<unsigned char>("ReturnByConstValue<unsigned char>", _proxyStubsValidatorImp->returnByConstValueUnsignedChar(), Expected::UnsignedChar);
    TestResult<char>("ReturnByConstValue<char>", _proxyStubsValidatorImp->returnByConstValueChar(), Expected::Char);
    TestResult<float>("ReturnByConstValue<float>", _proxyStubsValidatorImp->returnByConstValueFloat(), Expected::Float);
    TestResult<double>("ReturnByConstValue<double>", _proxyStubsValidatorImp->returnByConstValueDouble(), Expected::Double);
    TestResult<long double>("ReturnByConstValue<long double>", _proxyStubsValidatorImp->returnByConstValueLongDouble(), Expected::LongDouble);
    TestResult<bool>("ReturnByConstValue<bool>", _proxyStubsValidatorImp->returnByConstValueBool(), Expected::Bool);
}

void ProxyStubsValidator::TestPassByValue()
{
    ASSERT(_proxyStubsValidatorImp != nullptr)
    TestResult("PassByValue<unsigned int (with bit precision)>", _proxyStubsValidatorImp->passByValueUIntStrict(Expected::Uint8t, Expected::Uint16t, Expected::Uint32t, Expected::Uint64t));
    TestResult("PassByValue<int (with bit precision)>", _proxyStubsValidatorImp->passByValueIntStrict(Expected::Int8t, Expected::Int16t, Expected::Int32t, Expected::Int64t));
    TestResult("PassByValue<short int>", _proxyStubsValidatorImp->passByValueShortInt(Expected::Short, Expected::ShortInt, Expected::SignedShort, Expected::SignedShortInt));
    TestResult("PassByValue<unsigned short int>", _proxyStubsValidatorImp->passByValueUnsignedShortInt(Expected::UnsignedShort, Expected::UnsignedShortInt));
    TestResult("PassByValue<int>", _proxyStubsValidatorImp->passByValueInt(Expected::Int, Expected::Signed, Expected::SignedInt));
    TestResult("PassByValue<unsigned int>", _proxyStubsValidatorImp->passByValueUnsignedInt(Expected::Unsigned, Expected::UnsignedInt));
    TestResult("PassByValue<long int>", _proxyStubsValidatorImp->passByValueLongInt(Expected::Long, Expected::LongInt, Expected::SignedLong, Expected::SignedLongInt));
    TestResult("PassByValue<unsigned long int>", _proxyStubsValidatorImp->passByValueUnsignedLongInt(Expected::UnsignedLong, Expected::UnsignedLongInt));
    TestResult("PassByValue<long long int>", _proxyStubsValidatorImp->passByValueLongLongInt(Expected::LongLong, Expected::LongLongInt, Expected::SignedLongLong, Expected::SignedLongLongInt));
    TestResult("PassByValue<unsigned long long int>", _proxyStubsValidatorImp->passByValueUnsignedLongLongInt(Expected::UnsignedLongLong, Expected::UnsignedLongLongInt));
    TestResult("PassByValue<char>", _proxyStubsValidatorImp->passByValueChar(Expected::Char, Expected::SignedChar, Expected::UnsignedChar));
    TestResult("PassByValue<string>", _proxyStubsValidatorImp->passByValueString(Expected::String));
    TestResult("PassByValue<float>", _proxyStubsValidatorImp->passByValueFloat(Expected::Float, Expected::Double, Expected::LongDouble));
    TestResult("PassByValue<bool>", _proxyStubsValidatorImp->passByValueBool(Expected::Bool));
}

void ProxyStubsValidator::TestPassByConstValue()
{
    ASSERT(_proxyStubsValidatorImp != nullptr)
    TestResult("PassByConstValue<unsigned int (with bit precision)>", _proxyStubsValidatorImp->passByConstValueUIntStrict(Expected::Uint8t, Expected::Uint16t, Expected::Uint32t, Expected::Uint64t));
    TestResult("PassByConstValue<int (with bit precision)>", _proxyStubsValidatorImp->passByConstValueIntStrict(Expected::Int8t, Expected::Int16t, Expected::Int32t, Expected::Int64t));
    TestResult("PassByConstValue<short int>", _proxyStubsValidatorImp->passByConstValueShortInt(Expected::Short, Expected::ShortInt, Expected::SignedShort, Expected::SignedShortInt));
    TestResult("PassByConstValue<unsigned short int>", _proxyStubsValidatorImp->passByConstValueUnsignedShortInt(Expected::UnsignedShort, Expected::UnsignedShortInt));
    TestResult("PassByConstValue<int>", _proxyStubsValidatorImp->passByConstValueInt(Expected::Int, Expected::Signed, Expected::SignedInt));
    TestResult("PassByConstValue<unsigned int>", _proxyStubsValidatorImp->passByConstValueUnsignedInt(Expected::Unsigned, Expected::UnsignedInt));
    TestResult("PassByConstValue<long int>", _proxyStubsValidatorImp->passByConstValueLongInt(Expected::Long, Expected::LongInt, Expected::SignedLong, Expected::SignedLongInt));
    TestResult("PassByConstValue<unsigned long int>", _proxyStubsValidatorImp->passByConstValueUnsignedLongInt(Expected::UnsignedLong, Expected::UnsignedLongInt));
    TestResult("PassByConstValue<long long int>", _proxyStubsValidatorImp->passByConstValueLongLongInt(Expected::LongLong, Expected::LongLongInt, Expected::SignedLongLong, Expected::SignedLongLongInt));
    TestResult("PassByConstValue<unsigned long long int>", _proxyStubsValidatorImp->passByConstValueUnsignedLongLongInt(Expected::UnsignedLongLong, Expected::UnsignedLongLongInt));
    TestResult("PassByConstValue<char>", _proxyStubsValidatorImp->passByConstValueChar(Expected::Char, Expected::SignedChar, Expected::UnsignedChar));
    TestResult("PassByConstValue<string>", _proxyStubsValidatorImp->passByConstValueString(Expected::String));
    TestResult("PassByConstValue<float>", _proxyStubsValidatorImp->passByConstValueFloat(Expected::Float, Expected::Double, Expected::LongDouble));
    TestResult("PassByConstValue<bool>", _proxyStubsValidatorImp->passByConstValueBool(Expected::Bool));
}

void ProxyStubsValidator::TestPassByConstReference()
{
    ASSERT(_proxyStubsValidatorImp != nullptr)
    TestResult("PassByConstReference<unsigned int (with bit precision)>", _proxyStubsValidatorImp->passByConstReferenceUIntStrict(Expected::Uint8t, Expected::Uint16t, Expected::Uint32t, Expected::Uint64t));
    TestResult("PassByConstReference<int (with bit precision)>", _proxyStubsValidatorImp->passByConstReferenceIntStrict(Expected::Int8t, Expected::Int16t, Expected::Int32t, Expected::Int64t));
    TestResult("PassByConstReference<short int>", _proxyStubsValidatorImp->passByConstReferenceShortInt(Expected::Short, Expected::ShortInt, Expected::SignedShort, Expected::SignedShortInt));
    TestResult("PassByConstReference<unsigned short int>", _proxyStubsValidatorImp->passByConstReferenceUnsignedShortInt(Expected::UnsignedShort, Expected::UnsignedShortInt));
    TestResult("PassByConstReference<int>", _proxyStubsValidatorImp->passByConstReferenceInt(Expected::Int, Expected::Signed, Expected::SignedInt));
    TestResult("PassByConstReference<unsigned int>", _proxyStubsValidatorImp->passByConstReferenceUnsignedInt(Expected::Unsigned, Expected::UnsignedInt));
    TestResult("PassByConstReference<long int>", _proxyStubsValidatorImp->passByConstReferenceLongInt(Expected::Long, Expected::LongInt, Expected::SignedLong, Expected::SignedLongInt));
    TestResult("PassByConstReference<unsigned long int>", _proxyStubsValidatorImp->passByConstReferenceUnsignedLongInt(Expected::UnsignedLong, Expected::UnsignedLongInt));
    TestResult("PassByConstReference<long long int>", _proxyStubsValidatorImp->passByConstReferenceLongLongInt(Expected::LongLong, Expected::LongLongInt, Expected::SignedLongLong, Expected::SignedLongLongInt));
    TestResult("PassByConstReference<unsigned long long int>", _proxyStubsValidatorImp->passByConstReferenceUnsignedLongLongInt(Expected::UnsignedLongLong, Expected::UnsignedLongLongInt));
    TestResult("PassByConstReference<char>", _proxyStubsValidatorImp->passByConstReferenceChar(Expected::Char, Expected::SignedChar, Expected::UnsignedChar));
    TestResult("PassByConstReference<string>", _proxyStubsValidatorImp->passByConstReferenceString(Expected::String));
    TestResult("PassByConstReference<float>", _proxyStubsValidatorImp->passByConstReferenceFloat(Expected::Float, Expected::Double, Expected::LongDouble));
    TestResult("PassByConstReference<bool>", _proxyStubsValidatorImp->passByConstReferenceBool(Expected::Bool));
}

void ProxyStubsValidator::TestPassByReference()
{
    ASSERT(_proxyStubsValidatorImp != nullptr)
    {
        uint8_t v1;
        uint16_t v2;
        uint32_t v3;
        uint64_t v4;
        _proxyStubsValidatorImp->passByReferenceUIntStrict(v1, v2, v3, v4);

        TestResult<uint8_t>("PassByReference<uint8_t>", v1, Expected::Uint8t);
        TestResult<uint16_t>("PassByReference<uint16_t>", v2, Expected::Uint16t);
        TestResult<uint32_t>("PassByReference<uint32_t>", v3, Expected::Uint32t);
        TestResult<uint64_t>("PassByReference<uint64_t>", v4, Expected::Uint64t);
    }
    {
        int8_t v1;
        int16_t v2;
        int32_t v3;
        int64_t v4;
        _proxyStubsValidatorImp->passByReferenceIntStrict(v1, v2, v3, v4);

        TestResult<int8_t>("PassByReference<int8_t>", v1, Expected::Int8t);
        TestResult<int16_t>("PassByReference<int16_t>", v2, Expected::Int16t);
        TestResult<int32_t>("PassByReference<int32_t>", v3, Expected::Int32t);
        TestResult<int64_t>("PassByReference<int64_t>", v4, Expected::Int64t);
    }
    {
        short v1;
        short int v2;
        signed short v3;
        signed short int v4;
        _proxyStubsValidatorImp->passByReferenceShortInt(v1, v2, v3, v4);

        TestResult<short>("PassByReference<short>", v1, Expected::Short);
        TestResult<short int>("PassByReference<short int>", v2, Expected::ShortInt);
        TestResult<signed short>("PassByReference<signed short>", v3, Expected::SignedShort);
        TestResult<signed short int>("PassByReference<signed short int>", v4, Expected::SignedShortInt);
    }
    {
        unsigned short v1;
        unsigned short int v2;
        _proxyStubsValidatorImp->passByReferenceUnsignedShortInt(v1, v2);

        TestResult<unsigned short>("PassByReference<unsigned short>", v1, Expected::UnsignedShort);
        TestResult<unsigned short int>("PassByReference<unsigned short int>", v2, Expected::UnsignedShortInt);
    }
    {
        int v1;
        signed v2;
        signed int v3;
        _proxyStubsValidatorImp->passByReferenceInt(v1, v2, v3);

        TestResult<int>("PassByReference<int>", v1, Expected::Int);
        TestResult<signed>("PassByReference<signed>", v2, Expected::Signed);
        TestResult<signed int>("PassByReference<signed int>", v3, Expected::SignedInt);
    }
    {
        unsigned v1;
        unsigned int v2;
        _proxyStubsValidatorImp->passByReferenceUnsignedInt(v1, v2);

        TestResult<unsigned>("PassByReference<unsigned>", v1, Expected::Unsigned);
        TestResult<unsigned int>("PassByReference<unsigned int>", v2, Expected::UnsignedInt);
    }
    {
        long v1;
        long int v2;
        signed long v3;
        signed long int v4;
        _proxyStubsValidatorImp->passByReferenceLongInt(v1, v2, v3, v4);

        TestResult<long>("PassByReference<long>", v1, Expected::Long);
        TestResult<long int>("PassByReference<long int>", v2, Expected::LongInt);
        TestResult<signed long>("PassByReference<signed long>", v3, Expected::SignedLong);
        TestResult<signed long int>("PassByReference<signed long int>", v4, Expected::SignedLongInt);
    }
    {
        unsigned long v1;
        unsigned long int v2;
        _proxyStubsValidatorImp->passByReferenceUnsignedLongInt(v1, v2);

        TestResult<unsigned long>("PassByReference<unsigned long>", v1, Expected::UnsignedLong);
        TestResult<unsigned long int>("PassByReference<unsigned long int>", v2, Expected::UnsignedLongInt);
    }
    {
        long long v1;
        long long int v2;
        signed long long v3;
        signed long long int v4;
        _proxyStubsValidatorImp->passByReferenceLongLongInt(v1, v2, v3, v4);

        TestResult<long long>("PassByReference<long long>", v1, Expected::LongLong);
        TestResult<long long int>("PassByReference<long long int>", v2, Expected::LongLongInt);
        TestResult<signed long long>("PassByReference<signed long long>", v3, Expected::SignedLongLong);
        TestResult<signed long long int>("PassByReference<signed long long int>", v4, Expected::SignedLongLongInt);
    }
    {
        unsigned long long v1;
        unsigned long long int v2;
        _proxyStubsValidatorImp->passByReferenceUnsignedLongLongInt(v1, v2);

        TestResult<unsigned long long>("PassByReference<unsigned long long>", v1, Expected::UnsignedLongLong);
        TestResult<unsigned long long int>("PassByReference<unsigned long long int>", v2, Expected::UnsignedLongLongInt);
    }
    {
        char v1;
        signed char v2;
        unsigned char v3;
        _proxyStubsValidatorImp->passByReferenceChar(v1, v2, v3);

        TestResult<char>("PassByReference<char>", v1, Expected::Char);
        TestResult<signed char>("PassByReference<signed char>", v2, Expected::SignedChar);
        TestResult<unsigned char>("PassByReference<unsigned char>", v3, Expected::UnsignedChar);
    }
    {
        string v1;
        _proxyStubsValidatorImp->passByReferenceString(v1);

        TestResult<string>("PassByReference<string>", v1, Expected::String);
    }
    {
        float v1;
        double v2;
        long double v3;
        _proxyStubsValidatorImp->passByReferenceFloat(v1, v2, v3);

        TestResult<float>("PassByReference<float>", v1, Expected::Float);
        TestResult<double>("PassByReference<double>", v2, Expected::Double);
        TestResult<long double>("PassByReference<long double>", v3, Expected::LongDouble);
    }
    {
        bool v1;
        _proxyStubsValidatorImp->passByReferenceBool(v1);

        TestResult<bool>("PassByReference<bool>", v1, Expected::Bool);
    }
}

template<typename T>
void ProxyStubsValidator::TestResult(const string& name, T returned, T expected){
    if(returned == expected)
    {
        _passCount++;
        TRACE(Trace::Information, (_T("%s: PASS"), name.c_str()));
    } else {
        _failCount++;
        TRACE(Trace::Information, (_T("%s: FAIL"), name.c_str()));
    }
    _totalCount++;
}

void ProxyStubsValidator::TestResult(const string& name, bool result)
{
    if(result)
    {
        _passCount++;
        TRACE(Trace::Information, (_T("%s: PASS"), name.c_str()));
    } else {
        _failCount++;
        TRACE(Trace::Information, (_T("%s: FAIL"), name.c_str()));
    }
    _totalCount++;
}

} // namespace Plugin
} // namespace WPEFramework

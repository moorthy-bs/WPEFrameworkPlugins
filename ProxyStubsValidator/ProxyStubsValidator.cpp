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
    string result = _T("");

    ASSERT(_proxyStubsValidatorImp != nullptr)
    // Start return by value tests
    TestReturnByValue<uint8_t>("uint8_t", _proxyStubsValidatorImp->returnByValueUint8t(), Expected::Uint8t);
    TestReturnByValue<uint16_t>("uint16_t", _proxyStubsValidatorImp->returnByValueUint16t(), Expected::Uint16t);
    TestReturnByValue<uint32_t>("uint32_t", _proxyStubsValidatorImp->returnByValueUint32t(), Expected::Uint32t);
    TestReturnByValue<uint64_t>("uint64_t", _proxyStubsValidatorImp->returnByValueUint64t(), Expected::Uint64t);

    TestReturnByValue<int8_t>("int8_t", _proxyStubsValidatorImp->returnByValueInt8t(), Expected::Int8t);
    TestReturnByValue<int16_t>("int16_t", _proxyStubsValidatorImp->returnByValueInt16t(), Expected::Int16t);
    TestReturnByValue<int32_t>("int32_t", _proxyStubsValidatorImp->returnByValueInt32t(), Expected::Int32t);
    TestReturnByValue<int64_t>("int64_t", _proxyStubsValidatorImp->returnByValueInt64t(), Expected::Int64t);

    TestReturnByValue<short>("short", _proxyStubsValidatorImp->returnByValueShort(), Expected::Short);
    TestReturnByValue<short int>("short int", _proxyStubsValidatorImp->returnByValueShortInt(), Expected::ShortInt);
    TestReturnByValue<signed short>("signed short", _proxyStubsValidatorImp->returnByValueSignedShort(), Expected::SignedShort);
    TestReturnByValue<signed short int>("signed short int", _proxyStubsValidatorImp->returnByValueSignedShortInt(), Expected::SignedShortInt);

    TestReturnByValue<unsigned short>("unsigned short", _proxyStubsValidatorImp->returnByValueUnsignedShort(), Expected::UnsignedShort);
    TestReturnByValue<unsigned short int>("unsigned short int", _proxyStubsValidatorImp->returnByValueUnsignedShortInt(), Expected::UnsignedShortInt);

    TestReturnByValue<int>("int", _proxyStubsValidatorImp->returnByValueInt(), Expected::Int);
    TestReturnByValue<signed>("signed", _proxyStubsValidatorImp->returnByValueSigned(), Expected::Signed);
    TestReturnByValue<signed int>("signed int", _proxyStubsValidatorImp->returnByValueSignedInt(), Expected::SignedInt);

    TestReturnByValue<unsigned>("unsigned", _proxyStubsValidatorImp->returnByValueUnsigned(), Expected::Unsigned);
    TestReturnByValue<unsigned int>("unsigned int", _proxyStubsValidatorImp->returnByValueUnsignedInt(), Expected::UnsignedInt);

    TestReturnByValue<long>("long", _proxyStubsValidatorImp->returnByValueLong(), Expected::Long);
    TestReturnByValue<long int>("long int", _proxyStubsValidatorImp->returnByValueLongInt(), Expected::LongInt);
    TestReturnByValue<signed long>("signed long", _proxyStubsValidatorImp->returnByValueSignedLong(), Expected::SignedLong);
    TestReturnByValue<signed long int>("signed long int", _proxyStubsValidatorImp->returnByValueSignedLongInt(), Expected::SignedLongInt);

    TestReturnByValue<unsigned long>("unsigned long", _proxyStubsValidatorImp->returnByValueUnsignedLong(), Expected::UnsignedLong);
    TestReturnByValue<unsigned long int>("unsigned long int", _proxyStubsValidatorImp->returnByValueUnsignedLongInt(), Expected::UnsignedLongInt);

    TestReturnByValue<long long>("long long", _proxyStubsValidatorImp->returnByValueLongLong(), Expected::LongLong);
    TestReturnByValue<long long int>("long long int", _proxyStubsValidatorImp->returnByValueLongLongInt(), Expected::LongLongInt);
    TestReturnByValue<signed long long>("signed long long", _proxyStubsValidatorImp->returnByValueSignedLongLong(), Expected::SignedLongLong);
    TestReturnByValue<signed long long int>("signed long long int", _proxyStubsValidatorImp->returnByValueSignedLongLongInt(), Expected::SignedLongLongInt);

    TestReturnByValue<unsigned long long>("unsigned long long", _proxyStubsValidatorImp->returnByValueUnsignedLongLong(), Expected::UnsignedLongLong);
    TestReturnByValue<unsigned long long int>("unsigned long long int", _proxyStubsValidatorImp->returnByValueUnsignedLongLongInt(), Expected::UnsignedLongLongInt);

    TestReturnByValue<signed char>("signed char", _proxyStubsValidatorImp->returnByValueSignedChar(), Expected::SignedChar);
    TestReturnByValue<unsigned char>("unsigned char", _proxyStubsValidatorImp->returnByValueUnsignedChar(), Expected::UnsignedChar);
    TestReturnByValue<char>("char", _proxyStubsValidatorImp->returnByValueChar(), Expected::Char);

    TestReturnByValue<float>("float", _proxyStubsValidatorImp->returnByValueFloat(), Expected::Float);
    TestReturnByValue<double>("double", _proxyStubsValidatorImp->returnByValueDouble(), Expected::Double);
    TestReturnByValue<long double>("long double", _proxyStubsValidatorImp->returnByValueLongDouble(), Expected::LongDouble);

    // Start return by const value tests
    TestReturnByConstValue<uint8_t>("uint8_t", _proxyStubsValidatorImp->returnByConstValueUint8t(), Expected::Uint8t);
    TestReturnByConstValue<uint16_t>("uint16_t", _proxyStubsValidatorImp->returnByConstValueUint16t(), Expected::Uint16t);
    TestReturnByConstValue<uint32_t>("uint32_t", _proxyStubsValidatorImp->returnByConstValueUint32t(), Expected::Uint32t);
    TestReturnByConstValue<uint64_t>("uint64_t", _proxyStubsValidatorImp->returnByConstValueUint64t(), Expected::Uint64t);

    TestReturnByConstValue<int8_t>("int8_t", _proxyStubsValidatorImp->returnByConstValueInt8t(), Expected::Int8t);
    TestReturnByConstValue<int16_t>("int16_t", _proxyStubsValidatorImp->returnByConstValueInt16t(), Expected::Int16t);
    TestReturnByConstValue<int32_t>("int32_t", _proxyStubsValidatorImp->returnByConstValueInt32t(), Expected::Int32t);
    TestReturnByConstValue<int64_t>("int64_t", _proxyStubsValidatorImp->returnByConstValueInt64t(), Expected::Int64t);

    TestReturnByConstValue<short>("short", _proxyStubsValidatorImp->returnByConstValueShort(), Expected::Short);
    TestReturnByConstValue<short int>("short int", _proxyStubsValidatorImp->returnByConstValueShortInt(), Expected::ShortInt);
    TestReturnByConstValue<signed short>("signed short", _proxyStubsValidatorImp->returnByConstValueSignedShort(), Expected::SignedShort);
    TestReturnByConstValue<signed short int>("signed short int", _proxyStubsValidatorImp->returnByConstValueSignedShortInt(), Expected::SignedShortInt);

    TestReturnByConstValue<unsigned short>("unsigned short", _proxyStubsValidatorImp->returnByConstValueUnsignedShort(), Expected::UnsignedShort);
    TestReturnByConstValue<unsigned short int>("unsigned short int", _proxyStubsValidatorImp->returnByConstValueUnsignedShortInt(), Expected::UnsignedShortInt);

    TestReturnByConstValue<int>("int", _proxyStubsValidatorImp->returnByConstValueInt(), Expected::Int);
    TestReturnByConstValue<signed>("signed", _proxyStubsValidatorImp->returnByConstValueSigned(), Expected::Signed);
    TestReturnByConstValue<signed int>("signed int", _proxyStubsValidatorImp->returnByConstValueSignedInt(), Expected::SignedInt);

    TestReturnByConstValue<unsigned>("unsigned", _proxyStubsValidatorImp->returnByConstValueUnsigned(), Expected::Unsigned);
    TestReturnByConstValue<unsigned int>("unsigned int", _proxyStubsValidatorImp->returnByConstValueUnsignedInt(), Expected::UnsignedInt);

    TestReturnByConstValue<long>("long", _proxyStubsValidatorImp->returnByConstValueLong(), Expected::Long);
    TestReturnByConstValue<long int>("long int", _proxyStubsValidatorImp->returnByConstValueLongInt(), Expected::LongInt);
    TestReturnByConstValue<signed long>("signed long", _proxyStubsValidatorImp->returnByConstValueSignedLong(), Expected::SignedLong);
    TestReturnByConstValue<signed long int>("signed long int", _proxyStubsValidatorImp->returnByConstValueSignedLongInt(), Expected::SignedLongInt);

    TestReturnByConstValue<unsigned long>("unsigned long", _proxyStubsValidatorImp->returnByConstValueUnsignedLong(), Expected::UnsignedLong);
    TestReturnByConstValue<unsigned long int>("unsigned long int", _proxyStubsValidatorImp->returnByConstValueUnsignedLongInt(), Expected::UnsignedLongInt);

    TestReturnByConstValue<long long>("long long", _proxyStubsValidatorImp->returnByConstValueLongLong(), Expected::LongLong);
    TestReturnByConstValue<long long int>("long long int", _proxyStubsValidatorImp->returnByConstValueLongLongInt(), Expected::LongLongInt);
    TestReturnByConstValue<signed long long>("signed long long", _proxyStubsValidatorImp->returnByConstValueSignedLongLong(), Expected::SignedLongLong);
    TestReturnByConstValue<signed long long int>("signed long long int", _proxyStubsValidatorImp->returnByConstValueSignedLongLongInt(), Expected::SignedLongLongInt);

    TestReturnByConstValue<unsigned long long>("unsigned long long", _proxyStubsValidatorImp->returnByConstValueUnsignedLongLong(), Expected::UnsignedLongLong);
    TestReturnByConstValue<unsigned long long int>("unsigned long long int", _proxyStubsValidatorImp->returnByConstValueUnsignedLongLongInt(), Expected::UnsignedLongLongInt);

    TestReturnByConstValue<signed char>("signed char", _proxyStubsValidatorImp->returnByConstValueSignedChar(), Expected::SignedChar);
    TestReturnByConstValue<unsigned char>("unsigned char", _proxyStubsValidatorImp->returnByConstValueUnsignedChar(), Expected::UnsignedChar);
    TestReturnByConstValue<char>("char", _proxyStubsValidatorImp->returnByConstValueChar(), Expected::Char);

    TestReturnByConstValue<float>("float", _proxyStubsValidatorImp->returnByConstValueFloat(), Expected::Float);
    TestReturnByConstValue<double>("double", _proxyStubsValidatorImp->returnByConstValueDouble(), Expected::Double);
    TestReturnByConstValue<long double>("long double", _proxyStubsValidatorImp->returnByConstValueLongDouble(), Expected::LongDouble);

    // Start pass by value tests
    TestPassByValue("unsigned int (with bit precision)", _proxyStubsValidatorImp->passByValueUIntStrict(Expected::Uint8t, Expected::Uint16t, Expected::Uint32t, Expected::Uint64t));
    TestPassByValue("int (with bit precision)", _proxyStubsValidatorImp->passByValueIntStrict(Expected::Int8t, Expected::Int16t, Expected::Int32t, Expected::Int64t));
    TestPassByValue("short int", _proxyStubsValidatorImp->passByValueShortInt(Expected::Short, Expected::ShortInt, Expected::SignedShort, Expected::SignedShortInt));
    TestPassByValue("unsigned short int", _proxyStubsValidatorImp->passByValueUnsignedShortInt(Expected::UnsignedShort, Expected::UnsignedShortInt));
    TestPassByValue("int", _proxyStubsValidatorImp->passByValueInt(Expected::Int, Expected::Signed, Expected::SignedInt));
    TestPassByValue("unsigned int", _proxyStubsValidatorImp->passByValueUnsignedInt(Expected::Unsigned, Expected::UnsignedInt));
    TestPassByValue("long int", _proxyStubsValidatorImp->passByValueLongInt(Expected::Long, Expected::LongInt, Expected::SignedLong, Expected::SignedLongInt));
    TestPassByValue("unsigned long int", _proxyStubsValidatorImp->passByValueUnsignedLongInt(Expected::UnsignedLong, Expected::UnsignedLongInt));
    TestPassByValue("long long int", _proxyStubsValidatorImp->passByValueLongLongInt(Expected::LongLong, Expected::LongLongInt, Expected::SignedLongLong, Expected::SignedLongLongInt));
    TestPassByValue("unsigned long long int", _proxyStubsValidatorImp->passByValueUnsignedLongLongInt(Expected::UnsignedLongLong, Expected::UnsignedLongLongInt));
    TestPassByValue("char", _proxyStubsValidatorImp->passByValueChar(Expected::Char, Expected::SignedChar, Expected::UnsignedChar));
    TestPassByValue("string", _proxyStubsValidatorImp->passByValueString(Expected::String));
    TestPassByValue("float", _proxyStubsValidatorImp->passByValueFloat(Expected::Float, Expected::Double, Expected::LongDouble));

    // Start pass by const value tests
    TestPassByConstValue("unsigned int (with bit precision)", _proxyStubsValidatorImp->passByConstValueUIntStrict(Expected::Uint8t, Expected::Uint16t, Expected::Uint32t, Expected::Uint64t));
    TestPassByConstValue("int (with bit precision)", _proxyStubsValidatorImp->passByConstValueIntStrict(Expected::Int8t, Expected::Int16t, Expected::Int32t, Expected::Int64t));
    TestPassByConstValue("short int", _proxyStubsValidatorImp->passByConstValueShortInt(Expected::Short, Expected::ShortInt, Expected::SignedShort, Expected::SignedShortInt));
    TestPassByConstValue("unsigned short int", _proxyStubsValidatorImp->passByConstValueUnsignedShortInt(Expected::UnsignedShort, Expected::UnsignedShortInt));
    TestPassByConstValue("int", _proxyStubsValidatorImp->passByConstValueInt(Expected::Int, Expected::Signed, Expected::SignedInt));
    TestPassByConstValue("unsigned int", _proxyStubsValidatorImp->passByConstValueUnsignedInt(Expected::Unsigned, Expected::UnsignedInt));
    TestPassByConstValue("long int", _proxyStubsValidatorImp->passByConstValueLongInt(Expected::Long, Expected::LongInt, Expected::SignedLong, Expected::SignedLongInt));
    TestPassByConstValue("unsigned long int", _proxyStubsValidatorImp->passByConstValueUnsignedLongInt(Expected::UnsignedLong, Expected::UnsignedLongInt));
    TestPassByConstValue("long long int", _proxyStubsValidatorImp->passByConstValueLongLongInt(Expected::LongLong, Expected::LongLongInt, Expected::SignedLongLong, Expected::SignedLongLongInt));
    TestPassByConstValue("unsigned long long int", _proxyStubsValidatorImp->passByConstValueUnsignedLongLongInt(Expected::UnsignedLongLong, Expected::UnsignedLongLongInt));
    TestPassByConstValue("char", _proxyStubsValidatorImp->passByConstValueChar(Expected::Char, Expected::SignedChar, Expected::UnsignedChar));
    TestPassByConstValue("string", _proxyStubsValidatorImp->passByConstValueString(Expected::String));
    TestPassByConstValue("float", _proxyStubsValidatorImp->passByConstValueFloat(Expected::Float, Expected::Double, Expected::LongDouble));

    // Start pass by reference
    {
        uint8_t v1;
        uint16_t v2;
        uint32_t v3;
        uint64_t v4;
        _proxyStubsValidatorImp->passByReferenceUIntStrict(v1, v2, v3, v4);

        TestPassByReference<uint8_t>("uint8_t", v1, Expected::Uint8t);
        TestPassByReference<uint16_t>("uint16_t", v2, Expected::Uint16t);
        TestPassByReference<uint32_t>("uint32_t", v3, Expected::Uint32t);
        TestPassByReference<uint64_t>("uint64_t", v4, Expected::Uint64t);
    }
    {
        int8_t v1;
        int16_t v2;
        int32_t v3;
        int64_t v4;
        _proxyStubsValidatorImp->passByReferenceIntStrict(v1, v2, v3, v4);

        TestPassByReference<int8_t>("int8_t", v1, Expected::Int8t);
        TestPassByReference<int16_t>("int16_t", v2, Expected::Int16t);
        TestPassByReference<int32_t>("int32_t", v3, Expected::Int32t);
        TestPassByReference<int64_t>("int64_t", v4, Expected::Int64t);
    }
    {
        short v1;
        short int v2;
        signed short v3;
        signed short int v4;
        _proxyStubsValidatorImp->passByReferenceShortInt(v1, v2, v3, v4);

        TestPassByReference<short>("short", v1, Expected::Short);
        TestPassByReference<short int>("short int", v2, Expected::ShortInt);
        TestPassByReference<signed short>("signed short", v3, Expected::SignedShort);
        TestPassByReference<signed short int>("signed short int", v4, Expected::SignedShortInt);
    }
    {
        unsigned short v1;
        unsigned short int v2;
        _proxyStubsValidatorImp->passByReferenceUnsignedShortInt(v1, v2);

        TestPassByReference<unsigned short>("unsigned short", v1, Expected::UnsignedShort);
        TestPassByReference<unsigned short int>("unsigned short int", v2, Expected::UnsignedShortInt);
    }
    {
        int v1;
        signed v2;
        signed int v3;
        _proxyStubsValidatorImp->passByReferenceInt(v1, v2, v3);

        TestPassByReference<int>("int", v1, Expected::Int);
        TestPassByReference<signed>("signed", v2, Expected::Signed);
        TestPassByReference<signed int>("signed int", v3, Expected::SignedInt);
    }
    {
        unsigned v1;
        unsigned int v2;
        _proxyStubsValidatorImp->passByReferenceUnsignedInt(v1, v2);

        TestPassByReference<unsigned>("unsigned", v1, Expected::Unsigned);
        TestPassByReference<unsigned int>("unsigned int", v2, Expected::UnsignedInt);
    }
    {
        long v1;
        long int v2;
        signed long v3;
        signed long int v4;
        _proxyStubsValidatorImp->passByReferenceLongInt(v1, v2, v3, v4);

        TestPassByReference<long>("long", v1, Expected::Long);
        TestPassByReference<long int>("long int", v2, Expected::LongInt);
        TestPassByReference<signed long>("signed long", v3, Expected::SignedLong);
        TestPassByReference<signed long int>("signed long int", v4, Expected::SignedLongInt);
    }
    {
        unsigned long v1;
        unsigned long int v2;
        _proxyStubsValidatorImp->passByReferenceUnsignedLongInt(v1, v2);

        TestPassByReference<unsigned long>("unsigned long", v1, Expected::UnsignedLong);
        TestPassByReference<unsigned long int>("unsigned long int", v2, Expected::UnsignedLongInt);
    }
    {
        long long v1;
        long long int v2;
        signed long long v3;
        signed long long int v4;
        _proxyStubsValidatorImp->passByReferenceLongLongInt(v1, v2, v3, v4);

        TestPassByReference<long long>("long long", v1, Expected::LongLong);
        TestPassByReference<long long int>("long long int", v2, Expected::LongLongInt);
        TestPassByReference<signed long long>("signed long long", v3, Expected::SignedLongLong);
        TestPassByReference<signed long long int>("signed long long int", v4, Expected::SignedLongLongInt);
    }
    {
        unsigned long long v1;
        unsigned long long int v2;
        _proxyStubsValidatorImp->passByReferenceUnsignedLongLongInt(v1, v2);

        TestPassByReference<unsigned long long>("unsigned long long", v1, Expected::UnsignedLongLong);
        TestPassByReference<unsigned long long int>("unsigned long long int", v2, Expected::UnsignedLongLongInt);
    }
    {
        char v1;
        signed char v2;
        unsigned char v3;
        _proxyStubsValidatorImp->passByReferenceChar(v1, v2, v3);

        TestPassByReference<char>("char", v1, Expected::Char);
        TestPassByReference<signed char>("signed char", v2, Expected::SignedChar);
        TestPassByReference<unsigned char>("unsigned char", v3, Expected::UnsignedChar);
    }
    {
        string v1;
        _proxyStubsValidatorImp->passByReferenceString(v1);

        TestPassByReference<string>("string", v1, Expected::String);
    }
    {
        float v1;
        double v2;
        long double v3;
        _proxyStubsValidatorImp->passByReferenceFloat(v1, v2, v3);

        TestPassByReference<float>("float", v1, Expected::Float);
        TestPassByReference<double>("double", v2, Expected::Double);
        TestPassByReference<long double>("long double", v3, Expected::LongDouble);
    }

    TRACE(Trace::Information, (_T("Pass: %d, Fail: %d, Total: %d"), _passCount, _failCount, _totalCount));
    return result = _T("Execute OK!");
}

template<typename T>
void ProxyStubsValidator::TestReturnByValue(const string& name, T returned, T expected){
    if(returned == expected)
    {
        _passCount++;
        TRACE(Trace::Information, (_T("ReturnByValue<%s>: PASS"), name.c_str()));
    } else {
        _failCount++;
        TRACE(Trace::Information, (_T("ReturnByValue<%s>: FAIL"), name.c_str()));
    }
    _totalCount++;
}

template<typename T>
void ProxyStubsValidator::TestReturnByConstValue(const string& name, T returned, T expected){
    if(returned == expected)
    {
        _passCount++;
        TRACE(Trace::Information, (_T("ReturnByConstValue<%s>: PASS"), name.c_str()));
    } else {
        _failCount++;
        TRACE(Trace::Information, (_T("ReturnByConstValue<%s>: FAIL"), name.c_str()));
    }
    _totalCount++;
}

void ProxyStubsValidator::TestPassByValue(const string& name, bool result)
{
    if(result)
    {
        _passCount++;
        TRACE(Trace::Information, (_T("TestPassByValue<%s>: PASS"), name.c_str()));
    } else {
        _failCount++;
        TRACE(Trace::Information, (_T("TestPassByValue<%s>: FAIL"), name.c_str()));
    }
    _totalCount++;
}

void ProxyStubsValidator::TestPassByConstValue(const string& name, bool result)
{
    if(result)
    {
        _passCount++;
        TRACE(Trace::Information, (_T("TestPassByConstValue<%s>: PASS"), name.c_str()));
    } else {
        _failCount++;
        TRACE(Trace::Information, (_T("TestPassByConstValue<%s>: FAIL"), name.c_str()));
    }
    _totalCount++;
}

template<typename T>
void ProxyStubsValidator::TestPassByReference(const string& name, T returned, T expected)
{
    if(returned == expected)
    {
        _passCount++;
        TRACE(Trace::Information, (_T("PassByReference<%s>: PASS"), name.c_str()));
    } else {
        _failCount++;
        TRACE(Trace::Information, (_T("PassByReference<%s>: FAIL"), name.c_str()));
    }
    _totalCount++;
}
} // namespace Plugin
} // namespace WPEFramework

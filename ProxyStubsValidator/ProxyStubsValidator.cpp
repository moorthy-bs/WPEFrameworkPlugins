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
} // namespace Plugin
} // namespace WPEFramework

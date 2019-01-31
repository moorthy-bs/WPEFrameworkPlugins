#include "ProxyStubsValidator.h"

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

} // namespace Plugin
} // namespace WPEFramework

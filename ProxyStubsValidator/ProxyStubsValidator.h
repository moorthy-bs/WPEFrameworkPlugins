#pragma once

#include "Module.h"

#include <interfaces/IProxyStubsValidator.h>

namespace WPEFramework {
namespace Plugin {

class ProxyStubsValidator
    : public PluginHost::IPlugin
    , public PluginHost::IWeb {
public:
    // maximum wait time for process to be spawned
    static constexpr uint32_t ImplWaitTime = 1000;

private:
    class Notification : public RPC::IRemoteProcess::INotification {
    private:
        Notification() = delete;
        Notification(const Notification&) = delete;

    public:
        explicit Notification(ProxyStubsValidator* parent)
            : _parent(*parent)
        {
            ASSERT(parent != nullptr);
        }
        virtual ~Notification() {}

    public:
        virtual void Activated(RPC::IRemoteProcess* process) { _parent.Activated(process); }

        virtual void Deactivated(RPC::IRemoteProcess* process) { _parent.Deactivated(process); }

        BEGIN_INTERFACE_MAP(Notification)
        INTERFACE_ENTRY(RPC::IRemoteProcess::INotification)
        END_INTERFACE_MAP

    private:
        ProxyStubsValidator& _parent;
    };

public:
    ProxyStubsValidator()
        : _service(nullptr)
        , _notification(this)
        , _proxyStubsValidatorImp(nullptr)
        , _skipURL(0)
        , _pid(0)
    {
    }

    virtual ~ProxyStubsValidator() {}

    BEGIN_INTERFACE_MAP(ProxyStubsValidator)
    INTERFACE_ENTRY(PluginHost::IPlugin)
    INTERFACE_ENTRY(PluginHost::IWeb)
    INTERFACE_AGGREGATE(Exchange::IProxyStubsValidator, _proxyStubsValidatorImp)
    END_INTERFACE_MAP

    //   IPlugin methods
    // -------------------------------------------------------------------------------------------------------
    virtual const string Initialize(PluginHost::IShell* service) override;
    virtual void Deinitialize(PluginHost::IShell* service) override;
    virtual string Information() const override;

    //  IWeb methods
    // -------------------------------------------------------------------------------------------------------
    virtual void Inbound(Web::Request& request);
    virtual Core::ProxyType<Web::Response> Process(const Web::Request& request);

private:
    ProxyStubsValidator(const ProxyStubsValidator&) = delete;
    ProxyStubsValidator& operator=(const ProxyStubsValidator&) = delete;

    void Activated(RPC::IRemoteProcess* process);
    void Deactivated(RPC::IRemoteProcess* process);
    void ProcessTermination(uint32_t pid);

private:
    string Execute(void);

    PluginHost::IShell* _service;
    Core::Sink<Notification> _notification;
    Exchange::IProxyStubsValidator* _proxyStubsValidatorImp;
    uint8_t _skipURL;
    uint32_t _pid;
};

} // namespace Plugin
} // namespace WPEFramework

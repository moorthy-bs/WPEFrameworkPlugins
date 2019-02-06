#pragma once

#include "Module.h"

#include <interfaces/IProxyStubsValidator.h>
#include "TestOutput.h"

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

    class Result {
        // ToDo: maybe lock with mutex
    private:
        Result(const Result&) = default;
        Result& operator=(const Result&) = default;

    public:
        Result()
            : _passCount(0)
            , _failCount(0)
            , _totalCount(0)
        {
        }

    public:
        inline uint8_t Pass()
        {
            _passCount++;
            _totalCount++;
        }

        inline uint8_t Fail()
        {
            _failCount++;
            _totalCount++;
        }

        inline uint8_t PassCount() const { return _passCount; }
        inline uint8_t FailCount() const { return _failCount; }
        inline uint8_t TotalCount() const { return _totalCount; }
        inline void Status() const
        {
            TRACE(TestOutput, (_T("Status: Pass=%d/%d, Fail=%d/%d"), _passCount, _totalCount, _failCount, _totalCount));
        }

    private:
        uint32_t _passCount;
        uint32_t _failCount;
        uint32_t _totalCount;
    };

public:
    class TestResults : public Core::JSON::Container {
    private:
        TestResults(const TestResults&) = delete;
        TestResults& operator=(const TestResults&) = delete;

    public:
        TestResults()
            : Core::JSON::Container()
            , TotalCount()
            , FailCount()
            , PassCount()
        {
            Add(_T("passCount"), &PassCount);
            Add(_T("failCount"), &FailCount);
            Add(_T("totalCount"), &TotalCount);
        }

        ~TestResults() = default;

    public:
        Core::JSON::DecUInt32 PassCount;
        Core::JSON::DecUInt32 FailCount;
        Core::JSON::DecUInt32 TotalCount;
    };

public:
    ProxyStubsValidator()
        : _service(nullptr)
        , _notification(this)
        , _proxyStubsValidatorImp(nullptr)
        , _skipURL(0)
        , _pid(0)
        , _result()
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

public:
    void Execute(void);

private:
    void TestReturnByValue();
    void TestReturnByConstValue();
    void TestPassByValue();
    void TestPassByConstValue();
    void TestPassByConstReference();
    void TestPassByReference();
    void TestPointerToInterface();

    template<typename T> void TestResult(const string& msg, T returned, T expected);
    void TestResult(const string& msg, bool result);

    // ToDo: move somewhere else
    bool CompareStructure(const Exchange::IProxyStubsValidator::Structure& lhs, const Exchange::IProxyStubsValidator::Structure& rhs) const;


    PluginHost::IShell* _service;
    Core::Sink<Notification> _notification;
    Exchange::IProxyStubsValidator* _proxyStubsValidatorImp;
    uint8_t _skipURL;
    uint32_t _pid;
    Result _result;

};

} // namespace Plugin
} // namespace WPEFramework

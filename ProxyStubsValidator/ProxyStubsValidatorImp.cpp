#include "Module.h"

#include <interfaces/IProxyStubsValidator.h>

namespace WPEFramework {

class ProxyStubsValidatorImp : public Exchange::IProxyStubsValidator {
private:
    ProxyStubsValidatorImp(const ProxyStubsValidatorImp&) = delete;
    ProxyStubsValidatorImp& operator=(const ProxyStubsValidatorImp&) = delete;

public:
    ProxyStubsValidatorImp() {}

    virtual ~ProxyStubsValidatorImp() {}

    //  IProxyStubsValidator methods
    // -------------------------------------------------------------------------------------------------------
    virtual void dummyAction() override { TRACE(Trace::Fatal, (_T("******************** WORKS"))); }

    BEGIN_INTERFACE_MAP(ProxyStubsValidatorImp)
    INTERFACE_ENTRY(Exchange::IProxyStubsValidator)
    END_INTERFACE_MAP

private:
};

SERVICE_REGISTRATION(ProxyStubsValidatorImp, 1, 0);

} // namespace WPEFramework

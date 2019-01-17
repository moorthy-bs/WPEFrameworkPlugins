#include "BluetoothControl.h"

namespace WPEFramework {

#define ADAPTER_INDEX                   0X00
#define ENABLE_MODE                     0x01

namespace Plugin {

    SERVICE_REGISTRATION(BluetoothControl, 1, 0);

    static Core::ProxyPoolType<Web::JSONBodyType<BluetoothControl::Device::JSON> > jsonResponseFactoryDevice(1);
    static Core::ProxyPoolType<Web::JSONBodyType<BluetoothControl::Status> > jsonResponseFactoryStatus(1);

    /* virtual */ const string BluetoothControl::Initialize(PluginHost::IShell* service)
    {
        string result;

        ASSERT(_service == nullptr);
        ASSERT(_driver == nullptr);

        _service = service;
        _skipURL = _service->WebPrefix().length();
        Config config;
        config.FromString(_service->ConfigLine());
        _driver = Bluetooth::Driver::Instance(_service->ConfigLine());

        // First see if we can bring up the Driver....
        if (_driver == nullptr) {
            result = _T("Could not load the Bluetooth Driver.");
        }
        else {
            _interface = Bluetooth::Driver::Interface(config.Interface.Value());
         
            if (_interface.IsValid() == false) {
                result = _T("Could not bring up the interface.");
            }
            else {
                Bluetooth::SynchronousSocket channel (Core::NodeId(HCI_DEV_NONE, HCI_CHANNEL_CONTROL), 128);

                if (channel.Open(Core::infinite) != Core::ERROR_NONE) {
                    result = _T("Could not open a management Bleutooth connection.");
                }
                else {
                    Bluetooth::ManagementFrame mgmtFrame(ADAPTER_INDEX);
                    struct mgmt_mode modeFlags;
                    modeFlags.val = htobs(ENABLE_MODE);

                    if (channel.Send(mgmtFrame.Set(MGMT_OP_SET_POWERED, modeFlags), 1000) != Core::ERROR_NONE) {
                        result = "Failed to power on bluetooth adaptor";
                    }
                    // Enable Bondable on adaptor.
                    else if (channel.Send(mgmtFrame.Set(MGMT_OP_SET_BONDABLE, modeFlags), 1000) != Core::ERROR_NONE) {
                        result = "Failed to enable Bondable";
                    }
                    // Enable Simple Secure Simple Pairing.
                    else if (channel.Send(mgmtFrame.Set(MGMT_OP_SET_SSP, modeFlags), 1000) != Core::ERROR_NONE) {
                        result = "Failed to enable Simple Secure Simple Pairing";
                    }
                    // Enable Low Energy
                    else if (channel.Send(mgmtFrame.Set(MGMT_OP_SET_LE, modeFlags), 1000) != Core::ERROR_NONE) {
                        result = "Failed to enable Low Energy";
                    }    
                    // Enable Secure Connections
                    else if (channel.Send(mgmtFrame.Set(MGMT_OP_SET_SECURE_CONN, modeFlags), 1000) != Core::ERROR_NONE) {
                        result = "Failed to enable Secure Connections";
                    }
                    else if (_interface.Up() == false) {
                        result = "Failed to bring up the Bluetooth interface";
                    }
                    else if (_btAddress.Default() == false) {
                        result = "Could not get the Bluetooth address";
                    }
                    else {
                        _hciSocket.LocalNode(_btAddress.NodeId());

                        if (_hciSocket.Open(100) != Core::ERROR_NONE) {
                            result = "Could not open the HCI control channel";
                        }
                    }
                }                
            }
        }

        if ( (_driver != nullptr) && (result.empty() == false) ) {
            _interface.Down();
            delete _driver;
            _driver = nullptr;
        }
        return result;
    }

    /*virtual*/ void BluetoothControl::Deinitialize(PluginHost::IShell* service)
    {
        ASSERT(_service == service);
        ASSERT(_driver != nullptr);

        // Deinitialize what we initialized..
        _service = nullptr;

        if (_driver != nullptr) {
            // We bring the interface up, so we should bring it down as well..
            _interface.Down();
            delete _driver;
            _driver = nullptr;
        }
    }

    /* virtual */ string BluetoothControl::Information() const
    {
        // No additional info to report.
        return (nullptr);
    }

    /* virtual */ void BluetoothControl::Inbound(WPEFramework::Web::Request& request)
    {
        Core::TextSegmentIterator index(Core::TextFragment(request.Path, _skipURL, static_cast<uint32_t>(request.Path.length() - _skipURL)), false, '/');
        // By default, we are in front of any element, jump onto the first element, which is if, there is something an empty slot.
        index.Next();

        if ((request.Verb == Web::Request::HTTP_PUT) || (request.Verb == Web::Request::HTTP_POST)) {
            if ((index.IsValid() == true) && (index.Next() && index.IsValid())) {
                if ((index.Remainder() == _T("Pair")) || (index.Remainder() == _T("Connect")) || (index.Remainder() == _T("Disconnect")))
                   request.Body(jsonResponseFactoryDevice.Element());
            }
        }
    }

    /* virtual */ Core::ProxyType<Web::Response> BluetoothControl::Process(const WPEFramework::Web::Request& request)
    {
        ASSERT(_skipURL <= request.Path.length());

        TRACE(Trace::Information, (string(_T("Received BluetoothControl request"))));

        Core::ProxyType<Web::Response> result;
        Core::TextSegmentIterator index(Core::TextFragment(request.Path, _skipURL, request.Path.length() - _skipURL), false, '/');

        // By default, we are in front of any element, jump onto the first element, which is if, there is something an empty slot.
        index.Next();

        if (request.Verb == Web::Request::HTTP_GET) {

            result = GetMethod(index);
        } else if (request.Verb == Web::Request::HTTP_PUT) {

            result = PutMethod(index, request);
        } else if (request.Verb == Web::Request::HTTP_POST) {

            result = PostMethod(index, request);
        } else if (request.Verb == Web::Request::HTTP_DELETE) {

            result = DeleteMethod(index);
        }

        return result;
    }

    Core::ProxyType<Web::Response> BluetoothControl::GetMethod(Core::TextSegmentIterator& index)
    {
        Core::ProxyType<Web::Response> result(PluginHost::Factories::Instance().Response());
        result->ErrorCode = Web::STATUS_BAD_REQUEST;
        result->Message = _T("Unsupported GET request.");

        if (index.IsValid() == true) {
            if (index.Next() && index.IsValid()) {
                TRACE(Trace::Information, (string(__FUNCTION__)));
                if (index.Remainder() == _T("DiscoveredDevices")) {

                    TRACE(Trace::Information, (string(__FUNCTION__)));
                    Core::ProxyType<Web::JSONBodyType<Status> > response(jsonResponseFactoryStatus.Element());

                    std::string discoveredDevices;
                    if (discoveredDevices.size() > 0) {
                        response->DeviceList.FromString(discoveredDevices);

                        result->ErrorCode = Web::STATUS_OK;
                        result->Message = _T("Discovered devices.");
                        result->Body(response);
                    } else {
                        result->ErrorCode = Web::STATUS_NO_CONTENT;
                        result->Message = _T("Unable to display Discovered devices.");
                    }
                } else if (index.Remainder() == _T("PairedDevices")) {

                    TRACE(Trace::Information, (string(__FUNCTION__)));
                    Core::ProxyType<Web::JSONBodyType<Status> > response(jsonResponseFactoryStatus.Element());

                    std::string pairedDevices;
                    if (pairedDevices.size() > 0) {
                        response->DeviceList.FromString(pairedDevices);

                        result->ErrorCode = Web::STATUS_OK;
                        result->Message = _T("Paired devices.");
                        result->Body(response);
                    } else {
                        result->ErrorCode = Web::STATUS_NO_CONTENT;
                        result->Message = _T("Unable to display Paired devices.");
                    }
                }
            }
        } else {
            Core::ProxyType<Web::JSONBodyType<Status> > response(jsonResponseFactoryStatus.Element());

            result->ErrorCode = Web::STATUS_OK;
            result->Message = _T("Current status.");

            response->Scanning = IsScanning();
            std::string connectedDevices;
            if (connectedDevices.size() > 0)
                response->DeviceList.FromString(connectedDevices);

            result->Body(response);
        }

        return result;
    }

    Core::ProxyType<Web::Response> BluetoothControl::PutMethod(Core::TextSegmentIterator& index, const Web::Request& request)
    {
        Core::ProxyType<Web::Response> result(PluginHost::Factories::Instance().Response());
        result->ErrorCode = Web::STATUS_BAD_REQUEST;
        result->Message = _T("Unsupported PUT request.");

        if (index.IsValid() == true) {
            if (index.Next()) {
                TRACE(Trace::Information, (string(__FUNCTION__)));

                if (index.Remainder() == _T("Scan")) {
                    if (Scan(true) == Core::ERROR_NONE) {
                        result->ErrorCode = Web::STATUS_OK;
                        result->Message = _T("Scan started.");
                    } else {
                        result->ErrorCode = Web::STATUS_BAD_REQUEST;
                        result->Message = _T("Unable to start Scan.");
                    }
                } else if (index.Remainder() == _T("StopScan")) {
                    if (Scan(false) == Core::ERROR_NONE) {
                        result->ErrorCode = Web::STATUS_OK;
                        result->Message = _T("Scan stopped.");
                    } else {
                        result->ErrorCode = Web::STATUS_BAD_REQUEST;
                        result->Message = _T("Unable to stop Scan.");
                    }
                } else if ((index.Remainder() == _T("Pair")) && (request.HasBody())) {
                    Core::ProxyType<const Device::JSON> deviceInfo (request.Body<const Device::JSON>());
                    if (Pair(deviceInfo->Address)) {
                        result->ErrorCode = Web::STATUS_OK;
                        result->Message = _T("Paired device.");
                    } else {
                        result->ErrorCode = Web::STATUS_BAD_REQUEST;
                        result->Message = _T("Unable to Pair device.");
                    }
                } else if ((index.Remainder() == _T("Connect")) && (request.HasBody())) {
                    Core::ProxyType<const Device::JSON> deviceInfo (request.Body<const Device::JSON>());
                    if (Connect(deviceInfo->Address)) {
                        result->ErrorCode = Web::STATUS_OK;
                        result->Message = _T("Connected device.");
                    } else {
                        result->ErrorCode = Web::STATUS_BAD_REQUEST;
                        result->Message = _T("Unable to Connect device.");
                    }
                } else if ((index.Remainder() == _T("Disconnect")) && (request.HasBody())) {
                    Core::ProxyType<const Device::JSON> deviceInfo (request.Body<const Device::JSON>());
                    if (Disconnect(deviceInfo->Address)) {
                        result->ErrorCode = Web::STATUS_OK;
                        result->Message = _T("Disconnected device.");
                    } else {
                        result->ErrorCode = Web::STATUS_BAD_REQUEST;
                        result->Message = _T("Unable to Disconnect device.");
                    }
                }
            }
        }

        return result;
    }

    Core::ProxyType<Web::Response> BluetoothControl::PostMethod(Core::TextSegmentIterator& index, const Web::Request& request)
    {
        Core::ProxyType<Web::Response> result(PluginHost::Factories::Instance().Response());
        result->ErrorCode = Web::STATUS_BAD_REQUEST;
        result->Message = _T("Unsupported POST request.");

        return result;
    }

    Core::ProxyType<Web::Response> BluetoothControl::DeleteMethod(Core::TextSegmentIterator& index)
    {
        Core::ProxyType<Web::Response> result(PluginHost::Factories::Instance().Response());
        result->ErrorCode = Web::STATUS_BAD_REQUEST;
        result->Message = _T("Unsupported DELETE request.");

        return result;
    }


    //  IBluetooth methods
    // -------------------------------------------------------------------------------------------------------
    /* virtual */ bool BluetoothControl::IsScanning() const {
        return (_hciSocket.IsScanning());
    }
    /* virtual */ uint32_t BluetoothControl::Register(IBluetooth::INotification* notification) {
        _adminLock.Lock();

        // Make sure a sink is not registered multiple times.
        ASSERT(std::find(_observers.begin(), _observers.end(), sink) == _observers.end());

        _observers.push_back(notification);
        notification->AddRef();

        // Allright iterate over all devices, so thay get announced by the observer..
        for ( std::list<Device*>::iterator index = _devices.begin(), end = _devices.end(); index != end; ++index ) {
            notification->Update(*index);
        }

        _adminLock.Unlock();
    }
    /* virtual */ uint32_t BluetoothControl::Unregister(IBluetooth::INotification* notification) {
        _adminLock.Lock();

        std::list<IBluetooth::INotification*>::iterator index(std::find(_observers.begin(), _observers.end(), notification));

        // Make sure you do not unregister something you did not register !!!
        ASSERT(index != _observers.end());

        if (index != _observers.end()) {
            (*index)->Release();
            _observers.erase(index);
        }

        _adminLock.Unlock();
    }
    /* virtual */ bool BluetoothControl::Scan(const bool enable) {
        if ((_hciSocket.IsScanning() == false) && (enable == true)) {

            TRACE(Trace::Information, ("Start Bluetooth Scan"));

            // Clearing previously discovered devices.
            RemoveDevices ([] (Device* device) -> bool { if ((device->IsPaired() == false) && (device->IsConnected() == false)) device->Clear(); return(false); });

            _hciSocket.StartScan(0x10, 0x10);

        } 
        else if ((_hciSocket.IsScanning() == true) && (enable == false)) {

            TRACE(Trace::Information, ("Stop Bluetooth Scan"));

            _hciSocket.StopScan();
        }

        return (_hciSocket.IsScanning() == enable);
    }
    /* virtual */ bool BluetoothControl::Pair(const string& ) {
    }
    /* virtual */ bool BluetoothControl::Connect(const string&) {
    }
    /* virtual */ bool BluetoothControl::Disconnect(const string&) {
    }

    void BluetoothControl::DiscoveredDevice(const Bluetooth::Address& address, const string& shortName, const string& longName) {

        _adminLock.Lock();

        std::list<Device*>::iterator index = _devices.begin();

        while ( (index != _devices.end()) && (*(*index) != address) ) { index++; }

        if (index != _devices.end()) {
            (*index)->Update(shortName,longName);
        }
        else {
            _devices.push_back(Core::Service<Device>::Create<Device>(address, shortName, longName));
        }

        _adminLock.Unlock();
    }

    void BluetoothControl::RemoveDevices(std::function<bool(Device*)> filter) {

        _adminLock.Lock();

        for ( std::list<Device*>::iterator index = _devices.begin(), end = _devices.end(); index != end; ++index ) {
            // call the function passed into findMatchingAddresses and see if it matches
            if ( filter ( *index ) == true )
            {
                (*index)->Release();
                index = _devices.erase(index);
            }
        }

        _adminLock.Unlock();
    }
}
}
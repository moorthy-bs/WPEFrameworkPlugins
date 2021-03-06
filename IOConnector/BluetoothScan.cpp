#include <interfaces/IPower.h>

#include "Handler.h"
#include "TimedInput.h"

namespace WPEFramework {

namespace Plugin {

    class BluetoothScan : public IHandler {
    private:
        BluetoothScan();
        BluetoothScan(const PowerDown&);
        BluetoothScan& operator=(const PowerDown&);

        class Config : public Core::JSON::Container {
        private:
            Config(const Config& copy) = delete;
            Config& operator=(const Config& RHS) = delete;

        public:
            Config()
                : Callsign()
                , State()
            {
                Add(_T("callsign"), &Callsign);
                Add(_T("longpress"), &LongPress);
            }
            virtual ~Config()
            {
            }

        public:
            Core::JSON::String Callsign;
            Core::JSON::DecUInt8 LongPress;
        };

    public:
        BluetoothScan(PluginHost::IShell* service, const string& configuration)
            : _service(service)
            , _state()
            , _marker1(0)
        {
            Config config;
            config.FromString(configuration);
            _callsign = config.Callsign.Value();
            _marker2 = config.LongPress.Value() * 1000;
        }
        virtual ~BluetoothScan()
        {
        }

    public:
        void Interval(const uint32_t start, const uint32_t end) override {
            _marker2 = start + (_marker2 - _ marker1);
            _marker1 = start;
            _state.Clear();
            _state.Add(_marker1);
            if (_marker2 < end) {
                _state.Add(_marker2);
            }
            _state.Add(end);
        }
        void Trigger(GPIO::Pin& pin) override
        {
            uint32_t marker;

            ASSERT(_service != nullptr);

            if (_state.Analyse(pin.Set(), marker) == true) {
                if ((marker == _marker1) || (marker == _marker2)) {
                    Exchange::IBluetoothControl* handler(_service->QueryInterfaceByCallsign<Exchange::IBluetoothControl>(_callsign));

                    if (handler != nullptr) {

                        handler->Scan();
                        handler->Release();
                    }
                }
            }
        }

    private:
        PluginHost::IShell* _service;
        string _callsign;
        TimedInput _state;
        uint32_t _marker1;
        uint32_t _marker2;
    };

    static HandlerAdministrator::Entry<BluetoothScan> handler;

} // namespace Plugin
} // namespace WPEFramework

#include "Module.h"

#include <interfaces/IProxyStubsValidator.h>

namespace WPEFramework {

class ProxyStubsValidatorImp : public Exchange::IProxyStubsValidator {
private:
    ProxyStubsValidatorImp(const ProxyStubsValidatorImp&) = delete;
    ProxyStubsValidatorImp& operator=(const ProxyStubsValidatorImp&) = delete;

public:
    // int with specific bit number
    static const uint8_t ExpectedUint8t = 1;
    static const uint32_t ExpectedUint32t = 1;
    static const uint64_t ExpectedUint64t = 1;
    static const int8_t ExpectedInt8t = 1;
    static const int32_t ExpectedInt32t = 1;
    static const int64_t ExpectedInt64t = 1;
    // short int
    static const short ExpectedShort = 1;
    static const short int ExpectedShortInt = 1;
    static const signed short ExpectedSignedShort = 1;
    static const signed short int ExpectedSignedShortInt = 1;
    // unsigned short int
    static const unsigned short ExpectedUnsignedShort = 1;
    static const unsigned short int ExpectedUnsignedShortInt = 1;
    // int
    static const int ExpectedInt = 1;
    static const signed ExpectedSigned = 1;
    static const signed int ExpectedSignedInt = 1;
    // unsigned int
    static const unsigned ExpectedUnsigned = 1;
    static const unsigned int ExpectedUnsignedInt = 1;
    // long int
    static const long ExpectedLong = 1;
    static const long int ExpectedLongInt = 1;
    static const signed long ExpectedSignedLong = 1;
    static const signed long int ExpectedSignedLongInt = 1;
    // unsigned long int
    static const unsigned long ExpectedUnsignedLong = 1;
    static const unsigned long int ExpectedUnsignedLongInt = 1;
    // long long int
    static const long long ExpectedLongLong = 1;
    static const long long int ExpectedLongLongInt = 1;
    static const signed long long ExpectedSignedLongLong = 1;
    static const signed long long int ExpectedSignedLongLongInt = 1;
    // unsigned long long int
    static const unsigned long long ExpectedUnsignedLongLong = 1;
    static const unsigned long long int ExpectedUnsignedLongLongInt = 1;
    // char
    static const signed char ExpectedSignedChar = 1;
    static const unsigned char ExpectedUnsignedChar = 1;
    static const char ExpectedChar = 1;
    // ToDo: fix/delete
    // static const wchar_t ExpectedWchart = 1;
    // string
    static const string ExpectedString = {"string"};
    // floating point
    static const float ExpectedFloat = 1;
    static const double ExpectedDouble = 1;
    static const long double ExpectedLongDouble = 1;

public:
    ProxyStubsValidatorImp() {}

    virtual ~ProxyStubsValidatorImp() {}

    //  IProxyStubsValidator methods
    // -------------------------------------------------------------------------------------------------------
    //
    // return by value
    //
    // int with specific bit number
    virtual uint8_t returnByValueUint8t() override{ return ExpectedUint8t;}
    virtual uint32_t returnByValueUint32t() override{ return ExpectedUint32t;}
    virtual uint64_t returnByValueUint64t() override{ return ExpectedUint64t;}
    virtual int8_t returnByValueInt8t() override{ return ExpectedInt8t;}
    virtual int32_t returnByValueInt32t() override{ return ExpectedInt32t;}
    virtual int64_t returnByValueInt64t() override{ return ExpectedInt64t;}
    // short int
    virtual short returnByValueShort() override{ return ExpectedShort;}
    virtual short int returnByValueShortInt() override{ return ExpectedShortInt;}
    virtual signed short returnByValueSignedShort() override{ return ExpectedSignedShort;}
    virtual signed short int returnByValueSignedShortInt() override{ return ExpectedSignedShortInt;}
    // unsigned short int
    virtual unsigned short returnByValueUnsignedShort() override{ return ExpectedUnsignedShort;}
    virtual unsigned short int returnByValueUnsignedShortInt() override{ return ExpectedUnsignedShortInt;}
    // int
    virtual int returnByValueInt() override{ return ExpectedInt;}
    virtual signed returnByValueSigned() override{ return ExpectedSigned;}
    virtual signed int returnByValueSignedInt() override{ return ExpectedSignedInt;}
    // unsigned int
    virtual unsigned returnByValueUnsigned() override{ return ExpectedUnsigned;}
    virtual unsigned int returnByValueUnsignedInt() override{ return ExpectedUnsignedInt;}
    // long int
    virtual long returnByValueLong() override{ return ExpectedLong;}
    virtual long int returnByValueLongInt() override{ return ExpectedLongInt;}
    virtual signed long returnByValueSignedLong() override{ return ExpectedSignedLong;}
    virtual signed long int returnByValueSignedLongInt() override{ return ExpectedSignedLongInt;}
    // unsigned long int
    virtual unsigned long returnByValueUnsignedLong() override{ return ExpectedUnsignedLong;}
    virtual unsigned long int returnByValueUnsignedLongInt() override{ return ExpectedUnsignedLongInt;}
    // long long int
    virtual long long returnByValueLongLong() override{ return ExpectedLongLong;}
    virtual long long int returnByValueLongLongInt() override{ return ExpectedLongLongInt;}
    virtual signed long long returnByValueSignedLongLong() override{ return ExpectedSignedLongLong;}
    virtual signed long long int returnByValueSignedLongLongInt() override{ return ExpectedSignedLongLongInt;}
    // unsigned long long int
    virtual unsigned long long returnByValueUnsignedLongLong() override{ return ExpectedUnsignedLongLong;}
    virtual unsigned long long int returnByValueUnsignedLongLongInt() override{ return ExpectedUnsignedLongLongInt;}
    // char
    virtual signed char returnByValueSignedChar() override{ return ExpectedSignedChar;}
    virtual unsigned char returnByValueUnsignedChar() override{ return ExpectedUnsignedChar;}
    virtual char returnByValueChar() override{ return ExpectedChar;}
    // ToDo: fix/delete
    // virtual wchar_t returnByValueWchart() override{ return ExpectedWchart;}
    // string
    virtual string returnByValueString() override{ return ExpectedString;}
    // floating point
    virtual float returnByValueFloat() override{ return ExpectedFloat;}
    virtual double returnByValueDouble() override{ return ExpectedDouble;}
    virtual long double returnByValueLongDouble() override{ return ExpectedLongDouble;}

    //
    // return by const value
    //
    // int with specific bit number
    virtual const uint8_t returnByConstValueUint8t(){
        const uint8_t value = ExpectedUint8t;
        return value;
    }
    virtual const uint32_t returnByConstValueUint32t(){
        const uint32_t value = ExpectedUint32t;
        return value;
    }
    virtual const uint64_t returnByConstValueUint64t(){
        const uint64_t value = ExpectedUint64t;
        return value;
    }
    virtual const int8_t returnByConstValueInt8t(){
        const int8_t value = ExpectedInt8t;
        return value;
    }
    virtual const int32_t returnByConstValueInt32t(){
        const int32_t value = ExpectedInt32t;
        return value;
    }
    virtual const int64_t returnByConstValueInt64t(){
        const int64_t value = ExpectedInt64t;
        return value;
    }
    // short int
    virtual const short returnByConstValueShort(){
        const short value = ExpectedShort;
        return value;
    }
    virtual const short int returnByConstValueShortInt(){
        const int value = ExpectedShortInt;
        return value;
    }
    virtual const signed short returnByConstValueSignedShort(){
        const signed short value = ExpectedSignedShort;
        return value;
    }
    virtual const signed short int returnByConstValueSignedShortInt(){
        const  signed short int value = ExpectedSignedShortInt;
        return value;
    }
    // unsigned short int
    virtual const unsigned short returnByConstValueUnsignedShort(){
        const unsigned short value = ExpectedUnsignedShort;
        return value;
    }
    virtual const unsigned short int returnByConstValueUnsignedShortInt(){
        const unsigned short int value= ExpectedUnsignedShortInt;
        return value;
    }
    // int
    virtual const int returnByConstValueInt(){
        const int  value = ExpectedInt;
        return value;
    }
    virtual const signed returnByConstValueSigned(){
        const signed value = ExpectedSigned;
        return value;
    }
    virtual const signed int returnByConstValueSignedInt(){
        const signed int value = ExpectedSignedInt;
        return value;
    }
    // unsigned int
    virtual const unsigned returnByConstValueUnsigned(){
        const unsigned value = ExpectedUnsigned;
        return value;
    }
    virtual const unsigned int returnByConstValueUnsignedInt(){
        const unsigned int value = ExpectedUnsignedInt;
        return value;
    }
    // long int
    virtual const long returnByConstValueLong(){
        const long value = ExpectedLong;
        return value;
    }
    virtual const long int returnByConstValueLongInt(){
        const long int value = ExpectedLongInt;
        return value;
    }
    virtual const signed long returnByConstValueSignedLong(){
        const signed long value = ExpectedSignedLong;
        return value;
    }
    virtual const signed long int returnByConstValueSignedLongInt(){
        const signed long int value = ExpectedSignedLongInt;
        return value;
    }
    // unsigned long int
    virtual const unsigned long returnByConstValueUnsignedLong(){
        const unsigned long value = ExpectedUnsignedLong;
        return value;
    }
    virtual const unsigned long int returnByConstValueUnsignedLongInt(){
        const unsigned long int value =  ExpectedUnsignedLongInt;
        return value;
    }
    // long long int
    virtual const long long returnByConstValueLongLong(){
        const long long value = ExpectedLongLong;
        return value;
    }
    virtual const long long int returnByConstValueLongLongInt(){
        const long long int value = ExpectedLongLongInt;
        return value;
    }
    virtual const signed long long returnByConstValueSignedLongLong(){
        const signed long long value = ExpectedSignedLongLong;
        return value;
    }
    virtual const signed long long int returnByConstValueSignedLongLongInt(){
        const signed long long int value = ExpectedSignedLongLongInt;
        return value;
    }
    // unsigned long long int
    virtual const unsigned long long returnByConstValueUnsignedLongLong(){
        const unsigned long long value = ExpectedUnsignedLongLong;
        return value;
    }
    virtual const unsigned long long int returnByConstValueUnsignedLongLongInt(){
        const unsigned long long int value = ExpectedUnsignedLongLongInt;
        return value;
    }
    // char
    virtual const signed char returnByConstValueSignedChar(){
        const signed char value = ExpectedSignedChar;
        return value;
    }
    virtual const unsigned char returnByConstValueUnsignedChar(){
        const unsigned char value = ExpectedUnsignedChar;
        return value;
    }
    virtual const char returnByConstValueChar(){
        const char value = ExpectedChar;
        return value;
    }
    // ToDo: fix/delete
    // virtual const wchar_t returnByConstValueWchart(){
    //     const wchar_t value = ExpectedWchart;
    //     return value;
    // }
    // string
    virtual const string returnByConstValueString(){
        const string value = ExpectedString;
        return value;
    }
    // floating point
    virtual const float returnByConstValueFloat(){
        const float value = ExpectedFloat;
        return value;
    }
    virtual const double returnByConstValueDouble(){
        const double value = ExpectedDouble;
        return value;
    }
    virtual const long double returnByConstValueLongDouble(){
        const long double value = ExpectedLongDouble;
        return value;
    }

    BEGIN_INTERFACE_MAP(ProxyStubsValidatorImp)
    INTERFACE_ENTRY(Exchange::IProxyStubsValidator)
    END_INTERFACE_MAP
};

SERVICE_REGISTRATION(ProxyStubsValidatorImp, 1, 0);

} // namespace WPEFramework

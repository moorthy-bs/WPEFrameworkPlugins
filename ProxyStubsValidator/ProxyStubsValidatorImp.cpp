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
    static const uint16_t ExpectedUint16t = 1;
    static const uint32_t ExpectedUint32t = 1;
    static const uint64_t ExpectedUint64t = 1;
    static const int8_t ExpectedInt8t = 1;
    static const int16_t ExpectedInt16t = 1;
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

    // ****************************************************************************************************************
    // return by value
    // ****************************************************************************************************************
    // int with specific bit number
    virtual uint8_t returnByValueUint8t() override{ return ExpectedUint8t;}
    virtual uint16_t returnByValueUint16t() override{ return ExpectedUint16t;}
    virtual uint32_t returnByValueUint32t() override{ return ExpectedUint32t;}
    virtual uint64_t returnByValueUint64t() override{ return ExpectedUint64t;}
    virtual int8_t returnByValueInt8t() override{ return ExpectedInt8t;}
    virtual int16_t returnByValueInt16t() override{ return ExpectedInt16t;}
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
    // string
    virtual string returnByValueString() override{ return ExpectedString;}
    // floating point
    virtual float returnByValueFloat() override{ return ExpectedFloat;}
    virtual double returnByValueDouble() override{ return ExpectedDouble;}
    virtual long double returnByValueLongDouble() override{ return ExpectedLongDouble;}

    // ****************************************************************************************************************
    // return by const value
    // ****************************************************************************************************************
    // int with specific bit number
    virtual const uint8_t returnByConstValueUint8t() override{
        const uint8_t value = ExpectedUint8t;
        return value;
    }
    virtual const uint16_t returnByConstValueUint16t() override{
        const uint16_t value = ExpectedUint16t;
        return value;
    }
    virtual const uint32_t returnByConstValueUint32t() override{
        const uint32_t value = ExpectedUint32t;
        return value;
    }
    virtual const uint64_t returnByConstValueUint64t() override{
        const uint64_t value = ExpectedUint64t;
        return value;
    }
    virtual const int8_t returnByConstValueInt8t() override{
        const int8_t value = ExpectedInt8t;
        return value;
    }
    virtual const int16_t returnByConstValueInt16t() override{
        const int16_t value = ExpectedInt16t;
        return value;
    }
    virtual const int32_t returnByConstValueInt32t() override{
        const int32_t value = ExpectedInt32t;
        return value;
    }
    virtual const int64_t returnByConstValueInt64t() override{
        const int64_t value = ExpectedInt64t;
        return value;
    }
    // short int
    virtual const short returnByConstValueShort() override{
        const short value = ExpectedShort;
        return value;
    }
    virtual const short int returnByConstValueShortInt() override{
        const int value = ExpectedShortInt;
        return value;
    }
    virtual const signed short returnByConstValueSignedShort() override{
        const signed short value = ExpectedSignedShort;
        return value;
    }
    virtual const signed short int returnByConstValueSignedShortInt() override{
        const  signed short int value = ExpectedSignedShortInt;
        return value;
    }
    // unsigned short int
    virtual const unsigned short returnByConstValueUnsignedShort() override{
        const unsigned short value = ExpectedUnsignedShort;
        return value;
    }
    virtual const unsigned short int returnByConstValueUnsignedShortInt() override{
        const unsigned short int value= ExpectedUnsignedShortInt;
        return value;
    }
    // int
    virtual const int returnByConstValueInt() override{
        const int  value = ExpectedInt;
        return value;
    }
    virtual const signed returnByConstValueSigned() override{
        const signed value = ExpectedSigned;
        return value;
    }
    virtual const signed int returnByConstValueSignedInt() override{
        const signed int value = ExpectedSignedInt;
        return value;
    }
    // unsigned int
    virtual const unsigned returnByConstValueUnsigned() override{
        const unsigned value = ExpectedUnsigned;
        return value;
    }
    virtual const unsigned int returnByConstValueUnsignedInt() override{
        const unsigned int value = ExpectedUnsignedInt;
        return value;
    }
    // long int
    virtual const long returnByConstValueLong() override{
        const long value = ExpectedLong;
        return value;
    }
    virtual const long int returnByConstValueLongInt() override{
        const long int value = ExpectedLongInt;
        return value;
    }
    virtual const signed long returnByConstValueSignedLong() override{
        const signed long value = ExpectedSignedLong;
        return value;
    }
    virtual const signed long int returnByConstValueSignedLongInt() override{
        const signed long int value = ExpectedSignedLongInt;
        return value;
    }
    // unsigned long int
    virtual const unsigned long returnByConstValueUnsignedLong() override{
        const unsigned long value = ExpectedUnsignedLong;
        return value;
    }
    virtual const unsigned long int returnByConstValueUnsignedLongInt() override{
        const unsigned long int value =  ExpectedUnsignedLongInt;
        return value;
    }
    // long long int
    virtual const long long returnByConstValueLongLong() override{
        const long long value = ExpectedLongLong;
        return value;
    }
    virtual const long long int returnByConstValueLongLongInt() override{
        const long long int value = ExpectedLongLongInt;
        return value;
    }
    virtual const signed long long returnByConstValueSignedLongLong() override{
        const signed long long value = ExpectedSignedLongLong;
        return value;
    }
    virtual const signed long long int returnByConstValueSignedLongLongInt() override{
        const signed long long int value = ExpectedSignedLongLongInt;
        return value;
    }
    // unsigned long long int
    virtual const unsigned long long returnByConstValueUnsignedLongLong() override{
        const unsigned long long value = ExpectedUnsignedLongLong;
        return value;
    }
    virtual const unsigned long long int returnByConstValueUnsignedLongLongInt() override{
        const unsigned long long int value = ExpectedUnsignedLongLongInt;
        return value;
    }
    // char
    virtual const signed char returnByConstValueSignedChar() override{
        const signed char value = ExpectedSignedChar;
        return value;
    }
    virtual const unsigned char returnByConstValueUnsignedChar() override{
        const unsigned char value = ExpectedUnsignedChar;
        return value;
    }
    virtual const char returnByConstValueChar() override{
        const char value = ExpectedChar;
        return value;
    }
    // string
    virtual const string returnByConstValueString() override{
        const string value = ExpectedString;
        return value;
    }
    // floating point
    virtual const float returnByConstValueFloat() override{
        const float value = ExpectedFloat;
        return value;
    }
    virtual const double returnByConstValueDouble() override{
        const double value = ExpectedDouble;
        return value;
    }
    virtual const long double returnByConstValueLongDouble() override{
        const long double value = ExpectedLongDouble;
        return value;
    }

    // ****************************************************************************************************************
    // pass by value
    // ****************************************************************************************************************
    // int with specific bit number
    virtual bool passByValueUIntStrict(uint8_t v1, uint16_t v2, uint32_t v3, uint64_t v4) override
    {
        bool result = true;

        if(v1 != ExpectedUint8t) result = false;
        if(v2 != ExpectedUint16t) result = false;
        if(v3 != ExpectedUint32t) result = false;
        if(v4 != ExpectedUint64t) result = false;

        return result;
    }
    virtual bool passByValueIntStrict(int8_t v1, int16_t v2, int32_t v3, int64_t v4) override
    {
        bool result = true;

        if(v1 != ExpectedInt8t) result = false;
        if(v2 != ExpectedInt16t) result = false;
        if(v3 != ExpectedInt32t) result = false;
        if(v4 != ExpectedInt64t) result = false;

        return result;
    }
    // short int
    virtual bool passByValueShortInt(short v1, short int v2, signed short v3, signed short int v4) override
    {
        bool result = true;

        if(v1 != ExpectedShort) result = false;
        if(v2 != ExpectedShortInt) result = false;
        if(v3 != ExpectedSignedShort) result = false;
        if(v4 != ExpectedSignedShortInt) result = false;

        return result;
    }
    // unsigned short int
    virtual bool passByValueUnsignedShortInt(unsigned short v1, unsigned short int v2) override
    {
        bool result = true;

        if(v1 != ExpectedUnsignedShort) result = false;
        if(v2 != ExpectedUnsignedShortInt) result = false;

        return result;
    }
    // int
    virtual bool passByValueInt(int v1, signed v2, signed int v3) override
    {
        bool result = true;

        if(v1 != ExpectedInt) result = false;
        if(v2 != ExpectedSigned) result = false;
        if(v3 != ExpectedSignedInt) result = false;

        return result;
    }
    // unsigned int
    virtual bool passByValueUnsignedInt(unsigned v1, unsigned int v2) override
    {
        bool result = true;

        if(v1 != ExpectedUnsigned) result = false;
        if(v2 != ExpectedUnsignedInt) result = false;

        return result;
    }
    // long int
    virtual bool passByValueLongInt(long v1, long int v2, signed long v3, signed long int v4) override
    {
        bool result = true;

        if(v1 != ExpectedLong) result = false;
        if(v2 != ExpectedLongInt) result = false;
        if(v3 != ExpectedSignedLong) result = false;
        if(v4 != ExpectedSignedLongInt) result = false;

        return result;
    }
    // unsigned long int
    virtual bool passByValueUnsignedLongInt(unsigned long v1, unsigned long int v2) override
    {
        bool result = true;

        if(v1 != ExpectedUnsignedLong) result = false;
        if(v2 != ExpectedUnsignedLongInt) result = false;

        return result;
    }
    // long long int
    virtual bool passByValueLongLongInt(long long v1, long long int v2, signed long long v3, signed long long int v4) override
    {
        bool result = true;

        if(v1 != ExpectedLongLong) result = false;
        if(v2 != ExpectedLongLongInt) result = false;
        if(v3 != ExpectedSignedLongLong) result = false;
        if(v4 != ExpectedSignedLongLongInt) result = false;

        return result;
    }
    // unsigned long long int
    virtual bool passByValueUnsignedLongLongInt(unsigned long long v1, unsigned long long int v2) override
    {
        bool result = true;

        if(v1 != ExpectedUnsignedLongLong) result = false;
        if(v2 != ExpectedUnsignedLongLongInt) result = false;

        return result;
    }
    // char
    virtual bool passByValueChar(char v1, signed char v2, unsigned char v3) override
    {
        bool result = true;

        if(v1 != ExpectedSignedChar) result = false;
        if(v2 != ExpectedUnsignedChar) result = false;
        if(v3 != ExpectedChar) result = false;

        return result;
    }
    // string
    virtual bool passByValueString(string v1) override
    {
        bool result = true;

        if(v1 != ExpectedString) result = false;

        return result;
    }

    // floating point
    virtual bool passByValueFloat(float v1, double v2, long double v3) override
    {
        bool result = true;

        if(v1 != ExpectedFloat) result = false;
        if(v2 != ExpectedDouble) result = false;
        if(v3 != ExpectedLongDouble) result = false;

        return result;
    }

    // ****************************************************************************************************************
    // pass by const value
    // ****************************************************************************************************************
    // int with specific bit number
    virtual bool passByConstValueUIntStrict(const uint8_t v1, const uint16_t v2, const uint32_t v3, const uint64_t v4) override
    {
        bool result = true;

        if(v1 != ExpectedUint8t) result = false;
        if(v2 != ExpectedUint16t) result = false;
        if(v3 != ExpectedUint32t) result = false;
        if(v4 != ExpectedUint64t) result = false;

        return result;
    }
    virtual bool passByConstValueIntStrict(const int8_t v1, const int16_t v2, const int32_t v3, const int64_t v4) override
    {
        bool result = true;

        if(v1 != ExpectedInt8t) result = false;
        if(v2 != ExpectedInt16t) result = false;
        if(v3 != ExpectedInt32t) result = false;
        if(v4 != ExpectedInt64t) result = false;

        return result;
    }
    // short int
    virtual bool passByConstValueShortInt(const short v1, const short int v2, const signed short v3, const signed short int v4) override
    {
        bool result = true;

        if(v1 != ExpectedShort) result = false;
        if(v2 != ExpectedShortInt) result = false;
        if(v3 != ExpectedSignedShort) result = false;
        if(v4 != ExpectedSignedShortInt) result = false;

        return result;
    }
    // unsigned short int
    virtual bool passByConstValueUnsignedShortInt(const unsigned short v1, const unsigned short int v2) override
    {
        bool result = true;

        if(v1 != ExpectedUnsignedShort) result = false;
        if(v2 != ExpectedUnsignedShortInt) result = false;

        return result;
    }
    // int
    virtual bool passByConstValueInt(const int v1, const signed v2, const signed int v3) override
    {
        bool result = true;

        if(v1 != ExpectedInt) result = false;
        if(v2 != ExpectedSigned) result = false;
        if(v3 != ExpectedSignedInt) result = false;

        return result;
    }
    // unsigned int
    virtual bool passByConstValueUnsignedInt(const unsigned v1, const unsigned int v2) override
    {
        bool result = true;

        if(v1 != ExpectedUnsigned) result = false;
        if(v2 != ExpectedUnsignedInt) result = false;

        return result;
    }
    // long int
    virtual bool passByConstValueLongInt(const long v1, const long int v2, const signed long v3, const signed long int v4) override
    {
        bool result = true;

        if(v1 != ExpectedLong) result = false;
        if(v2 != ExpectedLongInt) result = false;
        if(v3 != ExpectedSignedLong) result = false;
        if(v4 != ExpectedSignedLongInt) result = false;

        return result;
    }
    // unsigned long int
    virtual bool passByConstValueUnsignedLongInt(const unsigned long v1, const unsigned long int v2) override
    {
        bool result = true;

        if(v1 != ExpectedUnsignedLong) result = false;
        if(v2 != ExpectedUnsignedLongInt) result = false;

        return result;
    }
    // long long int
    virtual bool passByConstValueLongLongInt(const long long v1, const long long int v2, const signed long long v3, const signed long long int v4) override
    {
        bool result = true;

        if(v1 != ExpectedLongLong) result = false;
        if(v2 != ExpectedLongLongInt) result = false;
        if(v3 != ExpectedSignedLongLong) result = false;
        if(v4 != ExpectedSignedLongLongInt) result = false;

        return result;
    }
    // unsigned long long int
    virtual bool passByConstValueUnsignedLongLongInt(const unsigned long long v1, const unsigned long long int v2) override
    {
        bool result = true;

        if(v1 != ExpectedUnsignedLongLong) result = false;
        if(v2 != ExpectedUnsignedLongLongInt) result = false;

        return result;
    }
    // char
    virtual bool passByConstValueChar(const char v1, const signed char v2, const unsigned char v3) override
    {
        bool result = true;

        if(v1 != ExpectedSignedChar) result = false;
        if(v2 != ExpectedUnsignedChar) result = false;
        if(v3 != ExpectedChar) result = false;

        return result;
    }
    // string
    virtual bool passByConstValueString(const string v1) override
    {
        bool result = true;

        if(v1 != ExpectedString) result = false;

        return result;
    }

    // floating point
    virtual bool passByConstValueFloat(const float v1, const double v2, const long double v3) override
    {
        bool result = true;

        if(v1 != ExpectedFloat) result = false;
        if(v2 != ExpectedDouble) result = false;
        if(v3 != ExpectedLongDouble) result = false;

        return result;
    }

    // ****************************************************************************************************************
    // pass by reference
    // ****************************************************************************************************************
    // int with specific bit number
    virtual bool passByReferenceUIntStrict(uint8_t& v1, uint16_t& v2, uint32_t& v3, uint64_t& v4) = 0;
    virtual bool passByReferenceIntStrict(int8_t& v1, int16_t& v2, int32_t& v3, int64_t& v4) = 0;
    // short int
    virtual bool passByReferenceShortInt(short& v1, short int& v2, signed short& v3, signed short int& v4) = 0;
    // unsigned short int
    virtual bool passByReferenceUnsignedShortInt(unsigned short& v1, unsigned short int& v2) = 0;
    // int
    virtual bool passByReferenceInt(int& v1, signed& v2, signed int& v3) = 0;
    // unsigned int
    virtual bool passByReferenceUnsignedInt(unsigned& v1, unsigned int& v2) = 0;
    // long int
    virtual bool passByReferenceLongInt(long& v1, long int& v2, signed long& v3, signed long int& v4) = 0;
    // unsigned long int
    virtual bool passByReferenceUnsignedLongInt(unsigned long& v1, unsigned long int& v2) = 0;
    // long long int
    virtual bool passByReferenceLongLongInt(long long& v1, long long int& v2, signed long long& v3, signed long long int& v4) = 0;
    // unsigned long long int
    virtual bool passByReferenceUnsignedLongLongInt(unsigned long long& v1, unsigned long long int& v2) = 0;
    // char
    virtual bool passByReferenceChar(char& v1, signed char& v2, unsigned char& v3) = 0;
    // string
    virtual bool passByReferenceString(string& v1) = 0;
    // floating point
    virtual bool passByReferenceFloat(float& v1, double& v2, long double& v3) = 0;
    BEGIN_INTERFACE_MAP(ProxyStubsValidatorImp)
    INTERFACE_ENTRY(Exchange::IProxyStubsValidator)
    END_INTERFACE_MAP
};

SERVICE_REGISTRATION(ProxyStubsValidatorImp, 1, 0);

} // namespace WPEFramework

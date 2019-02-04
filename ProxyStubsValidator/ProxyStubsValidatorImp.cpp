#include "Module.h"

#include <interfaces/IProxyStubsValidator.h>

namespace WPEFramework {

class ProxyStubsValidatorImp : public Exchange::IProxyStubsValidator {
private:
    ProxyStubsValidatorImp(const ProxyStubsValidatorImp&) = delete;
    ProxyStubsValidatorImp& operator=(const ProxyStubsValidatorImp&) = delete;

public:
    // int with specific bit number
    static const uint8_t ExpectedUint8t = std::numeric_limits<uint8_t>::max();
    static const uint16_t ExpectedUint16t = std::numeric_limits<uint16_t>::max();
    static const uint32_t ExpectedUint32t = std::numeric_limits<uint32_t>::max();
    static const uint64_t ExpectedUint64t = std::numeric_limits<uint64_t>::max();
    static const int8_t ExpectedInt8t = std::numeric_limits<int8_t>::max();
    static const int16_t ExpectedInt16t = std::numeric_limits<int16_t>::max();
    static const int32_t ExpectedInt32t = std::numeric_limits<int32_t>::max();
    static const int64_t ExpectedInt64t = std::numeric_limits<int64_t>::max();
    // short int
    static const short ExpectedShort = std::numeric_limits<short>::max();
    static const short int ExpectedShortInt = std::numeric_limits<short int>::max();
    static const signed short ExpectedSignedShort = std::numeric_limits<signed short>::max();
    static const signed short int ExpectedSignedShortInt = std::numeric_limits<signed short int>::max();
    // unsigned short int
    static const unsigned short ExpectedUnsignedShort = std::numeric_limits<unsigned short>::max();
    static const unsigned short int ExpectedUnsignedShortInt = std::numeric_limits<unsigned short int>::max();
    // int
    static const int ExpectedInt = std::numeric_limits<int>::max();
    static const signed ExpectedSigned = std::numeric_limits<signed>::max();
    static const signed int ExpectedSignedInt = std::numeric_limits<signed int>::max();
    // unsigned int
    static const unsigned ExpectedUnsigned = std::numeric_limits<unsigned>::max();
    static const unsigned int ExpectedUnsignedInt = std::numeric_limits<unsigned int>::max();
    // long int
    static const long ExpectedLong = std::numeric_limits<long>::max();
    static const long int ExpectedLongInt = std::numeric_limits<long int>::max();
    static const signed long ExpectedSignedLong = std::numeric_limits<signed long>::max();
    static const signed long int ExpectedSignedLongInt = std::numeric_limits<signed long int>::max();
    // unsigned long int
    static const unsigned long ExpectedUnsignedLong = std::numeric_limits<unsigned long>::max();
    static const unsigned long int ExpectedUnsignedLongInt = std::numeric_limits<unsigned long int>::max();
    // long long int
    static const long long ExpectedLongLong = std::numeric_limits<long long>::max();
    static const long long int ExpectedLongLongInt = std::numeric_limits<long long int>::max();
    static const signed long long ExpectedSignedLongLong = std::numeric_limits<signed long long>::max();
    static const signed long long int ExpectedSignedLongLongInt = std::numeric_limits<signed long long int>::max();
    // unsigned long long int
    static const unsigned long long ExpectedUnsignedLongLong = std::numeric_limits<unsigned long long>::max();
    static const unsigned long long int ExpectedUnsignedLongLongInt = std::numeric_limits<unsigned long long int>::max();
    // char
    static const signed char ExpectedSignedChar = std::numeric_limits<signed char>::max();
    static const unsigned char ExpectedUnsignedChar = std::numeric_limits<unsigned char>::max();
    static const char ExpectedChar = std::numeric_limits<char>::max();
    // string
    static const string ExpectedString = {"string"};
    // floating point
    static const float ExpectedFloat = std::numeric_limits<float>::max();
    static const double ExpectedDouble = std::numeric_limits<double>::max();
    static const long double ExpectedLongDouble = std::numeric_limits<long double>::max();

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
    virtual void passByReferenceUIntStrict(uint8_t& v1, uint16_t& v2, uint32_t& v3, uint64_t& v4) override {
        v1 = ExpectedUint8t;
        v2 = ExpectedUint16t;
        v3 = ExpectedUint32t;
        v4 = ExpectedUint64t;
    }

    virtual void passByReferenceIntStrict(int8_t& v1, int16_t& v2, int32_t& v3, int64_t& v4) override {
        v1 = ExpectedInt8t;
        v2 = ExpectedInt16t;
        v3 = ExpectedInt32t;
        v4 = ExpectedInt64t;
    }

    // short int
    virtual void passByReferenceShortInt(short& v1, short int& v2, signed short& v3, signed short int& v4) override {
        v1 = ExpectedShort;
        v2 = ExpectedShortInt;
        v3 = ExpectedSignedShort;
        v4 = ExpectedSignedShortInt;
    }

    // unsigned short int
    virtual void passByReferenceUnsignedShortInt(unsigned short& v1, unsigned short int& v2) override {
        v1 = ExpectedUnsignedShort;
        v2 = ExpectedUnsignedShortInt;
    }

    // int
    virtual void passByReferenceInt(int& v1, signed& v2, signed int& v3) override {
        v1 = ExpectedInt;
        v2 = ExpectedSigned;
        v3 = ExpectedSignedInt;
    }

    // unsigned int
    virtual void passByReferenceUnsignedInt(unsigned& v1, unsigned int& v2) override {
        v1 = ExpectedUnsigned;
        v2 = ExpectedUnsignedInt;
    }

    // long int
    virtual void passByReferenceLongInt(long& v1, long int& v2, signed long& v3, signed long int& v4) override {
        v1 = ExpectedLong;
        v2 = ExpectedLongInt;
        v3 = ExpectedSignedLong;
        v4 = ExpectedSignedLongInt;
    }

    // unsigned long int
    virtual void passByReferenceUnsignedLongInt(unsigned long& v1, unsigned long int& v2) override {
        v1 = ExpectedUnsignedLong;
        v2 = ExpectedUnsignedLongInt;
    }

    // long long int
    virtual void passByReferenceLongLongInt(long long& v1, long long int& v2, signed long long& v3, signed long long int& v4) override {
        v1 = ExpectedLongLong;
        v2 = ExpectedLongLongInt;
        v3 = ExpectedSignedLongLong;
        v4 = ExpectedSignedLongLongInt;
    }

    // unsigned long long int
    virtual void passByReferenceUnsignedLongLongInt(unsigned long long& v1, unsigned long long int& v2) override {
        v1 = ExpectedUnsignedLongLong;
        v2 = ExpectedUnsignedLongLongInt;
    }

    // char
    virtual void passByReferenceChar(char& v1, signed char& v2, unsigned char& v3) override {
        v1 = ExpectedSignedChar;
        v2 = ExpectedUnsignedChar;
        v3 = ExpectedChar;
    }

    // string
    virtual void passByReferenceString(string& v1) override {
        v1 = ExpectedString;
    }

    // floating point
    virtual void passByReferenceFloat(float& v1, double& v2, long double& v3) override {
        v1 = ExpectedFloat;
        v2 = ExpectedDouble;
        v3 = ExpectedLongDouble;
    }

    // ****************************************************************************************************************
    // pass by const reference
    // ****************************************************************************************************************
    // int with specific bit number
    virtual bool passByConstReferenceUIntStrict(const uint8_t& v1, const uint16_t& v2, const uint32_t& v3, const uint64_t& v4) override {
        bool result = true;

        if(v1 != ExpectedUint8t) result = false;
        if(v2 != ExpectedUint16t) result = false;
        if(v3 != ExpectedUint32t) result = false;
        if(v4 != ExpectedUint64t) result = false;

        return result;
    }

    virtual bool passByConstReferenceIntStrict(const int8_t& v1, const int16_t& v2, const int32_t& v3, const int64_t& v4) override {
        bool result = true;

        if(v1 != ExpectedInt8t) result = false;
        if(v2 != ExpectedInt16t) result = false;
        if(v3 != ExpectedInt32t) result = false;
        if(v4 != ExpectedInt64t) result = false;

        return result;
    }

    // short int
    virtual bool passByConstReferenceShortInt(const short& v1, const short int& v2, const signed short& v3, const signed short int& v4) override {
        bool result = true;

        if(v1 != ExpectedShort) result = false;
        if(v2 != ExpectedShortInt) result = false;
        if(v3 != ExpectedSignedShort) result = false;
        if(v4 != ExpectedSignedShortInt) result = false;

        return result;
    }

    // unsigned short int
    virtual bool passByConstReferenceUnsignedShortInt(const unsigned short& v1, const unsigned short int& v2) override {
        bool result = true;

        if(v1 != ExpectedUnsignedShort) result = false;
        if(v2 != ExpectedUnsignedShortInt) result = false;

        return result;
    }

    // int
    virtual bool passByConstReferenceInt(const int& v1, const signed& v2, const signed int& v3) override {
        bool result = true;

        if(v1 != ExpectedInt) result = false;
        if(v2 != ExpectedSigned) result = false;
        if(v3 != ExpectedSignedInt) result = false;

        return result;
    }

    // unsigned int
    virtual bool passByConstReferenceUnsignedInt(const unsigned& v1, const unsigned int& v2) override {
        bool result = true;

        if(v1 != ExpectedUnsigned) result = false;
        if(v2 != ExpectedUnsignedInt) result = false;;

        return result;
    }

    // long int
    virtual bool passByConstReferenceLongInt(const long& v1, long int& v2, const signed long& v3, const signed long int& v4) override {
        bool result = true;

        if(v1 != ExpectedLong) result = false;
        if(v2 != ExpectedLongInt) result = false;
        if(v3 != ExpectedSignedLong) result = false;
        if(v4 != ExpectedSignedLongInt) result = false;

        return result;
    }

    // unsigned long int
    virtual bool passByConstReferenceUnsignedLongInt(const unsigned long& v1, const unsigned long int& v2) override {
        bool result = true;

        if(v1 != ExpectedUnsignedLong) result = false;
        if(v2 != ExpectedUnsignedLongInt) result = false;

        return result;
    }

    // long long int
    virtual bool passByConstReferenceLongLongInt(const long long& v1, const long long int& v2, const signed long long& v3, const signed long long int& v4) override {
        bool result = true;

        if(v1 != ExpectedLongLong) result = false;
        if(v2 != ExpectedLongLongInt) result = false;
        if(v3 != ExpectedSignedLongLong) result = false;
        if(v4 != ExpectedSignedLongLongInt) result = false;

        return result;
    }

    // unsigned long long int
    virtual bool passByConstReferenceUnsignedLongLongInt(const unsigned long long& v1, const unsigned long long int& v2) override {
        bool result = true;

        if(v1 != ExpectedUnsignedLongLong) result = false;
        if(v2 != ExpectedUnsignedLongLongInt) result = false;

        return result;
    }

    // char
    virtual bool passByConstReferenceChar(const char& v1, const signed char& v2, const unsigned char& v3) override {
        bool result = true;

        if(v1 != ExpectedSignedChar) result = false;
        if(v2 != ExpectedUnsignedChar) result = false;
        if(v3 != ExpectedChar) result = false;

        return result;
    }

    // string
    virtual bool passByConstReferenceString(const string& v1) override {
        bool result = true;

        if(v1 != ExpectedString) result = false;

        return result;
    }

    // floating point
    virtual bool passByConstReferenceFloat(const float& v1, const double& v2, const long double& v3) override {
        bool result = true;

        if(v1 != ExpectedFloat) result = false;
        if(v2 != ExpectedDouble) result = false;
        if(v3 != ExpectedLongDouble) result = false;

        return result;
    }

    BEGIN_INTERFACE_MAP(ProxyStubsValidatorImp)
    INTERFACE_ENTRY(Exchange::IProxyStubsValidator)
    END_INTERFACE_MAP
};

SERVICE_REGISTRATION(ProxyStubsValidatorImp, 1, 0);

} // namespace WPEFramework

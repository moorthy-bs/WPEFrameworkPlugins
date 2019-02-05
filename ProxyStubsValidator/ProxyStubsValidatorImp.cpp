#include "Module.h"

#include <interfaces/IProxyStubsValidator.h>
#include "ExpectedValues.h"

namespace WPEFramework {

class ProxyStubsValidatorImp : public Exchange::IProxyStubsValidator {
private:
    ProxyStubsValidatorImp(const ProxyStubsValidatorImp&) = delete;
    ProxyStubsValidatorImp& operator=(const ProxyStubsValidatorImp&) = delete;

public:
    ProxyStubsValidatorImp() {}

    virtual ~ProxyStubsValidatorImp() {}

    //  IProxyStubsValidator methods

    // ****************************************************************************************************************
    // return by value
    // ****************************************************************************************************************
    // int with specific bit number
    virtual uint8_t returnByValueUint8t() override{ return Expected::Uint8t;}
    virtual uint16_t returnByValueUint16t() override{ return Expected::Uint16t;}
    virtual uint32_t returnByValueUint32t() override{ return Expected::Uint32t;}
    virtual uint64_t returnByValueUint64t() override{ return Expected::Uint64t;}
    virtual int8_t returnByValueInt8t() override{ return Expected::Int8t;}
    virtual int16_t returnByValueInt16t() override{ return Expected::Int16t;}
    virtual int32_t returnByValueInt32t() override{ return Expected::Int32t;}
    virtual int64_t returnByValueInt64t() override{ return Expected::Int64t;}
    // short int
    virtual short returnByValueShort() override{ return Expected::Short;}
    virtual short int returnByValueShortInt() override{ return Expected::ShortInt;}
    virtual signed short returnByValueSignedShort() override{ return Expected::SignedShort;}
    virtual signed short int returnByValueSignedShortInt() override{ return Expected::SignedShortInt;}
    // unsigned short int
    virtual unsigned short returnByValueUnsignedShort() override{ return Expected::UnsignedShort;}
    virtual unsigned short int returnByValueUnsignedShortInt() override{ return Expected::UnsignedShortInt;}
    // int
    virtual int returnByValueInt() override{ return Expected::Int;}
    virtual signed returnByValueSigned() override{ return Expected::Signed;}
    virtual signed int returnByValueSignedInt() override{ return Expected::SignedInt;}
    // unsigned int
    virtual unsigned returnByValueUnsigned() override{ return Expected::Unsigned;}
    virtual unsigned int returnByValueUnsignedInt() override{ return Expected::UnsignedInt;}
    // long int
    virtual long returnByValueLong() override{ return Expected::Long;}
    virtual long int returnByValueLongInt() override{ return Expected::LongInt;}
    virtual signed long returnByValueSignedLong() override{ return Expected::SignedLong;}
    virtual signed long int returnByValueSignedLongInt() override{ return Expected::SignedLongInt;}
    // unsigned long int
    virtual unsigned long returnByValueUnsignedLong() override{ return Expected::UnsignedLong;}
    virtual unsigned long int returnByValueUnsignedLongInt() override{ return Expected::UnsignedLongInt;}
    // long long int
    virtual long long returnByValueLongLong() override{ return Expected::LongLong;}
    virtual long long int returnByValueLongLongInt() override{ return Expected::LongLongInt;}
    virtual signed long long returnByValueSignedLongLong() override{ return Expected::SignedLongLong;}
    virtual signed long long int returnByValueSignedLongLongInt() override{ return Expected::SignedLongLongInt;}
    // unsigned long long int
    virtual unsigned long long returnByValueUnsignedLongLong() override{ return Expected::UnsignedLongLong;}
    virtual unsigned long long int returnByValueUnsignedLongLongInt() override{ return Expected::UnsignedLongLongInt;}
    // char
    virtual signed char returnByValueSignedChar() override{ return Expected::SignedChar;}
    virtual unsigned char returnByValueUnsignedChar() override{ return Expected::UnsignedChar;}
    virtual char returnByValueChar() override{ return Expected::Char;}
    // string
    virtual string returnByValueString() override{ return Expected::String;}
    // floating point
    virtual float returnByValueFloat() override{ return Expected::Float;}
    virtual double returnByValueDouble() override{ return Expected::Double;}
    virtual long double returnByValueLongDouble() override{ return Expected::LongDouble;}
    virtual bool returnByValueBool() override { return Expected::Bool;}
    // enum
    virtual Enum returnByValueEnum() override { return Expected::Enum;}
    virtual ScopedEnum returnByValueScopedEnum() override { return Expected::ScopedEnum;}
    virtual ScopedTypedEnum returnByValueScopedTypedEnum() override { return Expected::ScopedTypedEnum;}
    // struct
    virtual Structure returnByValueStructure() override { return Expected::Structure;}

    // ****************************************************************************************************************
    // return by const value
    // ****************************************************************************************************************
    // int with specific bit number
    virtual const uint8_t returnByConstValueUint8t() override{
        const uint8_t value = Expected::Uint8t;
        return value;
    }

    virtual const uint16_t returnByConstValueUint16t() override{
        const uint16_t value = Expected::Uint16t;
        return value;
    }

    virtual const uint32_t returnByConstValueUint32t() override{
        const uint32_t value = Expected::Uint32t;
        return value;
    }

    virtual const uint64_t returnByConstValueUint64t() override{
        const uint64_t value = Expected::Uint64t;
        return value;
    }

    virtual const int8_t returnByConstValueInt8t() override{
        const int8_t value = Expected::Int8t;
        return value;
    }

    virtual const int16_t returnByConstValueInt16t() override{
        const int16_t value = Expected::Int16t;
        return value;
    }

    virtual const int32_t returnByConstValueInt32t() override{
        const int32_t value = Expected::Int32t;
        return value;
    }

    virtual const int64_t returnByConstValueInt64t() override{
        const int64_t value = Expected::Int64t;
        return value;
    }

    // short int
    virtual const short returnByConstValueShort() override{
        const short value = Expected::Short;
        return value;
    }

    virtual const short int returnByConstValueShortInt() override{
        const int value = Expected::ShortInt;
        return value;
    }

    virtual const signed short returnByConstValueSignedShort() override{
        const signed short value = Expected::SignedShort;
        return value;
    }

    virtual const signed short int returnByConstValueSignedShortInt() override{
        const  signed short int value = Expected::SignedShortInt;
        return value;
    }

    // unsigned short int
    virtual const unsigned short returnByConstValueUnsignedShort() override{
        const unsigned short value = Expected::UnsignedShort;
        return value;
    }

    virtual const unsigned short int returnByConstValueUnsignedShortInt() override{
        const unsigned short int value= Expected::UnsignedShortInt;
        return value;
    }

    // int
    virtual const int returnByConstValueInt() override{
        const int  value = Expected::Int;
        return value;
    }

    virtual const signed returnByConstValueSigned() override{
        const signed value = Expected::Signed;
        return value;
    }

    virtual const signed int returnByConstValueSignedInt() override{
        const signed int value = Expected::SignedInt;
        return value;
    }

    // unsigned int
    virtual const unsigned returnByConstValueUnsigned() override{
        const unsigned value = Expected::Unsigned;
        return value;
    }

    virtual const unsigned int returnByConstValueUnsignedInt() override{
        const unsigned int value = Expected::UnsignedInt;
        return value;
    }

    // long int
    virtual const long returnByConstValueLong() override{
        const long value = Expected::Long;
        return value;
    }

    virtual const long int returnByConstValueLongInt() override{
        const long int value = Expected::LongInt;
        return value;
    }

    virtual const signed long returnByConstValueSignedLong() override{
        const signed long value = Expected::SignedLong;
        return value;
    }

    virtual const signed long int returnByConstValueSignedLongInt() override{
        const signed long int value = Expected::SignedLongInt;
        return value;
    }

    // unsigned long int
    virtual const unsigned long returnByConstValueUnsignedLong() override{
        const unsigned long value = Expected::UnsignedLong;
        return value;
    }

    virtual const unsigned long int returnByConstValueUnsignedLongInt() override{
        const unsigned long int value =  Expected::UnsignedLongInt;
        return value;
    }

    // long long int
    virtual const long long returnByConstValueLongLong() override{
        const long long value = Expected::LongLong;
        return value;
    }

    virtual const long long int returnByConstValueLongLongInt() override{
        const long long int value = Expected::LongLongInt;
        return value;
    }

    virtual const signed long long returnByConstValueSignedLongLong() override{
        const signed long long value = Expected::SignedLongLong;
        return value;
    }

    virtual const signed long long int returnByConstValueSignedLongLongInt() override{
        const signed long long int value = Expected::SignedLongLongInt;
        return value;
    }

    // unsigned long long int
    virtual const unsigned long long returnByConstValueUnsignedLongLong() override{
        const unsigned long long value = Expected::UnsignedLongLong;
        return value;
    }

    virtual const unsigned long long int returnByConstValueUnsignedLongLongInt() override{
        const unsigned long long int value = Expected::UnsignedLongLongInt;
        return value;
    }

    // char
    virtual const signed char returnByConstValueSignedChar() override{
        const signed char value = Expected::SignedChar;
        return value;
    }

    virtual const unsigned char returnByConstValueUnsignedChar() override{
        const unsigned char value = Expected::UnsignedChar;
        return value;
    }

    virtual const char returnByConstValueChar() override{
        const char value = Expected::Char;
        return value;
    }

    // string
    virtual const string returnByConstValueString() override{
        const string value = Expected::String;
        return value;
    }

    // floating point
    virtual const float returnByConstValueFloat() override{
        const float value = Expected::Float;
        return value;
    }

    virtual const double returnByConstValueDouble() override{
        const double value = Expected::Double;
        return value;
    }

    virtual const long double returnByConstValueLongDouble() override{
        const long double value = Expected::LongDouble;
        return value;
    }

    virtual const bool returnByConstValueBool() override{
        const bool value = Expected::Bool;
        return value;
    }

    // enum
    virtual const Enum returnByConstValueEnum() override{
        const Enum value = Expected::Enum;
        return value;
    }

    virtual const ScopedEnum returnByConstValueScopedEnum() override{
        const ScopedEnum value = Expected::ScopedEnum;
        return value;
    }

    virtual const ScopedTypedEnum returnByConstValueScopedTypedEnum() override{
        const ScopedTypedEnum value = Expected::ScopedTypedEnum;
        return value;
    }

    // struct
    virtual const Structure returnByConstValueStructure() override{
        const Structure value = Expected::Structure;
        return value;
    }

    // ****************************************************************************************************************
    // pass by value
    // ****************************************************************************************************************
    // int with specific bit number
    virtual bool passByValueUIntStrict(uint8_t v1, uint16_t v2, uint32_t v3, uint64_t v4) override
    {
        bool result = true;

        if(v1 != Expected::Uint8t) result = false;
        if(v2 != Expected::Uint16t) result = false;
        if(v3 != Expected::Uint32t) result = false;
        if(v4 != Expected::Uint64t) result = false;

        return result;
    }

    virtual bool passByValueIntStrict(int8_t v1, int16_t v2, int32_t v3, int64_t v4) override
    {
        bool result = true;

        if(v1 != Expected::Int8t) result = false;
        if(v2 != Expected::Int16t) result = false;
        if(v3 != Expected::Int32t) result = false;
        if(v4 != Expected::Int64t) result = false;

        return result;
    }

    // short int
    virtual bool passByValueShortInt(short v1, short int v2, signed short v3, signed short int v4) override
    {
        bool result = true;

        if(v1 != Expected::Short) result = false;
        if(v2 != Expected::ShortInt) result = false;
        if(v3 != Expected::SignedShort) result = false;
        if(v4 != Expected::SignedShortInt) result = false;

        return result;
    }

    // unsigned short int
    virtual bool passByValueUnsignedShortInt(unsigned short v1, unsigned short int v2) override
    {
        bool result = true;

        if(v1 != Expected::UnsignedShort) result = false;
        if(v2 != Expected::UnsignedShortInt) result = false;

        return result;
    }

    // int
    virtual bool passByValueInt(int v1, signed v2, signed int v3) override
    {
        bool result = true;

        if(v1 != Expected::Int) result = false;
        if(v2 != Expected::Signed) result = false;
        if(v3 != Expected::SignedInt) result = false;

        return result;
    }

    // unsigned int
    virtual bool passByValueUnsignedInt(unsigned v1, unsigned int v2) override
    {
        bool result = true;

        if(v1 != Expected::Unsigned) result = false;
        if(v2 != Expected::UnsignedInt) result = false;

        return result;
    }

    // long int
    virtual bool passByValueLongInt(long v1, long int v2, signed long v3, signed long int v4) override
    {
        bool result = true;

        if(v1 != Expected::Long) result = false;
        if(v2 != Expected::LongInt) result = false;
        if(v3 != Expected::SignedLong) result = false;
        if(v4 != Expected::SignedLongInt) result = false;

        return result;
    }

    // unsigned long int
    virtual bool passByValueUnsignedLongInt(unsigned long v1, unsigned long int v2) override
    {
        bool result = true;

        if(v1 != Expected::UnsignedLong) result = false;
        if(v2 != Expected::UnsignedLongInt) result = false;

        return result;
    }

    // long long int
    virtual bool passByValueLongLongInt(long long v1, long long int v2, signed long long v3, signed long long int v4) override
    {
        bool result = true;

        if(v1 != Expected::LongLong) result = false;
        if(v2 != Expected::LongLongInt) result = false;
        if(v3 != Expected::SignedLongLong) result = false;
        if(v4 != Expected::SignedLongLongInt) result = false;

        return result;
    }

    // unsigned long long int
    virtual bool passByValueUnsignedLongLongInt(unsigned long long v1, unsigned long long int v2) override
    {
        bool result = true;

        if(v1 != Expected::UnsignedLongLong) result = false;
        if(v2 != Expected::UnsignedLongLongInt) result = false;

        return result;
    }

    // char
    virtual bool passByValueChar(char v1, signed char v2, unsigned char v3) override
    {
        bool result = true;

        if(v1 != Expected::Char) result = false;
        if(v2 != Expected::SignedChar) result = false;
        if(v3 != Expected::UnsignedChar) result = false;

        return result;
    }

    // string
    virtual bool passByValueString(string v1) override
    {
        bool result = true;

        if(v1 != Expected::String) result = false;

        return result;
    }

    // floating point
    virtual bool passByValueFloat(float v1, double v2, long double v3) override
    {
        bool result = true;

        if(v1 != Expected::Float) result = false;
        if(v2 != Expected::Double) result = false;
        if(v3 != Expected::LongDouble) result = false;

        return result;
    }

    // bool
    virtual bool passByValueBool(bool v1) override
    {
        bool result = true;

        if(v1 != Expected::Bool) result = false;

        return result;
    }

    // enum
    virtual bool passByValueEnum(Enum v1, ScopedEnum v2, ScopedTypedEnum v3) override
    {
        bool result = true;

        if(v1 != Expected::Enum) result = false;
        if(v2 != Expected::ScopedEnum) result = false;
        if(v3 != Expected::ScopedTypedEnum) result = false;

        return result;
    }

    // struct
    virtual bool passByValueStructure(Structure v1) override
    {
        bool result = true;

        if(v1.field1 != Expected::Structure.field1) result = false;
        if(v1.field2 != Expected::Structure.field2) result = false;

        return result;
    }

    // ****************************************************************************************************************
    // pass by const value
    // ****************************************************************************************************************
    // int with specific bit number
    virtual bool passByConstValueUIntStrict(const uint8_t v1, const uint16_t v2, const uint32_t v3, const uint64_t v4) override
    {
        bool result = true;

        if(v1 != Expected::Uint8t) result = false;
        if(v2 != Expected::Uint16t) result = false;
        if(v3 != Expected::Uint32t) result = false;
        if(v4 != Expected::Uint64t) result = false;

        return result;
    }

    virtual bool passByConstValueIntStrict(const int8_t v1, const int16_t v2, const int32_t v3, const int64_t v4) override
    {
        bool result = true;

        if(v1 != Expected::Int8t) result = false;
        if(v2 != Expected::Int16t) result = false;
        if(v3 != Expected::Int32t) result = false;
        if(v4 != Expected::Int64t) result = false;

        return result;
    }

    // short int
    virtual bool passByConstValueShortInt(const short v1, const short int v2, const signed short v3, const signed short int v4) override
    {
        bool result = true;

        if(v1 != Expected::Short) result = false;
        if(v2 != Expected::ShortInt) result = false;
        if(v3 != Expected::SignedShort) result = false;
        if(v4 != Expected::SignedShortInt) result = false;

        return result;
    }

    // unsigned short int
    virtual bool passByConstValueUnsignedShortInt(const unsigned short v1, const unsigned short int v2) override
    {
        bool result = true;

        if(v1 != Expected::UnsignedShort) result = false;
        if(v2 != Expected::UnsignedShortInt) result = false;

        return result;
    }

    // int
    virtual bool passByConstValueInt(const int v1, const signed v2, const signed int v3) override
    {
        bool result = true;

        if(v1 != Expected::Int) result = false;
        if(v2 != Expected::Signed) result = false;
        if(v3 != Expected::SignedInt) result = false;

        return result;
    }

    // unsigned int
    virtual bool passByConstValueUnsignedInt(const unsigned v1, const unsigned int v2) override
    {
        bool result = true;

        if(v1 != Expected::Unsigned) result = false;
        if(v2 != Expected::UnsignedInt) result = false;

        return result;
    }

    // long int
    virtual bool passByConstValueLongInt(const long v1, const long int v2, const signed long v3, const signed long int v4) override
    {
        bool result = true;

        if(v1 != Expected::Long) result = false;
        if(v2 != Expected::LongInt) result = false;
        if(v3 != Expected::SignedLong) result = false;
        if(v4 != Expected::SignedLongInt) result = false;

        return result;
    }

    // unsigned long int
    virtual bool passByConstValueUnsignedLongInt(const unsigned long v1, const unsigned long int v2) override
    {
        bool result = true;

        if(v1 != Expected::UnsignedLong) result = false;
        if(v2 != Expected::UnsignedLongInt) result = false;

        return result;
    }

    // long long int
    virtual bool passByConstValueLongLongInt(const long long v1, const long long int v2, const signed long long v3, const signed long long int v4) override
    {
        bool result = true;

        if(v1 != Expected::LongLong) result = false;
        if(v2 != Expected::LongLongInt) result = false;
        if(v3 != Expected::SignedLongLong) result = false;
        if(v4 != Expected::SignedLongLongInt) result = false;

        return result;
    }

    // unsigned long long int
    virtual bool passByConstValueUnsignedLongLongInt(const unsigned long long v1, const unsigned long long int v2) override
    {
        bool result = true;

        if(v1 != Expected::UnsignedLongLong) result = false;
        if(v2 != Expected::UnsignedLongLongInt) result = false;

        return result;
    }

    // char
    virtual bool passByConstValueChar(const char v1, const signed char v2, const unsigned char v3) override
    {
        bool result = true;

        if(v1 != Expected::Char) result = false;
        if(v2 != Expected::SignedChar) result = false;
        if(v3 != Expected::UnsignedChar) result = false;

        return result;
    }

    // string
    virtual bool passByConstValueString(const string v1) override
    {
        bool result = true;

        if(v1 != Expected::String) result = false;

        return result;
    }

    // floating point
    virtual bool passByConstValueFloat(const float v1, const double v2, const long double v3) override
    {
        bool result = true;

        if(v1 != Expected::Float) result = false;
        if(v2 != Expected::Double) result = false;
        if(v3 != Expected::LongDouble) result = false;

        return result;
    }

    // bool
    virtual bool passByConstValueBool(const bool v1) override
    {
        bool result = true;

        if(v1 != Expected::Bool) result = false;

        return result;
    }

    // enum
    virtual bool passByConstValueEnum(const Enum v1, const ScopedEnum v2, const ScopedTypedEnum v3) override
    {
        bool result = true;

        if(v1 != Expected::Enum) result = false;
        if(v2 != Expected::ScopedEnum) result = false;
        if(v3 != Expected::ScopedTypedEnum) result = false;

        return result;
    }

    // struct
    virtual bool passByConstValueStructure(const Structure v1) override
    {
        bool result = true;

        if(v1.field1 != Expected::Structure.field1) result = false;
        if(v1.field2 != Expected::Structure.field2) result = false;

        return result;
    }

    // ****************************************************************************************************************
    // pass by reference
    // ****************************************************************************************************************
    // int with specific bit number
    virtual void passByReferenceUIntStrict(uint8_t& v1, uint16_t& v2, uint32_t& v3, uint64_t& v4) override {
        v1 = Expected::Uint8t;
        v2 = Expected::Uint16t;
        v3 = Expected::Uint32t;
        v4 = Expected::Uint64t;
    }

    virtual void passByReferenceIntStrict(int8_t& v1, int16_t& v2, int32_t& v3, int64_t& v4) override {
        v1 = Expected::Int8t;
        v2 = Expected::Int16t;
        v3 = Expected::Int32t;
        v4 = Expected::Int64t;
    }

    // short int
    virtual void passByReferenceShortInt(short& v1, short int& v2, signed short& v3, signed short int& v4) override {
        v1 = Expected::Short;
        v2 = Expected::ShortInt;
        v3 = Expected::SignedShort;
        v4 = Expected::SignedShortInt;
    }

    // unsigned short int
    virtual void passByReferenceUnsignedShortInt(unsigned short& v1, unsigned short int& v2) override {
        v1 = Expected::UnsignedShort;
        v2 = Expected::UnsignedShortInt;
    }

    // int
    virtual void passByReferenceInt(int& v1, signed& v2, signed int& v3) override {
        v1 = Expected::Int;
        v2 = Expected::Signed;
        v3 = Expected::SignedInt;
    }

    // unsigned int
    virtual void passByReferenceUnsignedInt(unsigned& v1, unsigned int& v2) override {
        v1 = Expected::Unsigned;
        v2 = Expected::UnsignedInt;
    }

    // long int
    virtual void passByReferenceLongInt(long& v1, long int& v2, signed long& v3, signed long int& v4) override {
        v1 = Expected::Long;
        v2 = Expected::LongInt;
        v3 = Expected::SignedLong;
        v4 = Expected::SignedLongInt;
    }

    // unsigned long int
    virtual void passByReferenceUnsignedLongInt(unsigned long& v1, unsigned long int& v2) override {
        v1 = Expected::UnsignedLong;
        v2 = Expected::UnsignedLongInt;
    }

    // long long int
    virtual void passByReferenceLongLongInt(long long& v1, long long int& v2, signed long long& v3, signed long long int& v4) override {
        v1 = Expected::LongLong;
        v2 = Expected::LongLongInt;
        v3 = Expected::SignedLongLong;
        v4 = Expected::SignedLongLongInt;
    }

    // unsigned long long int
    virtual void passByReferenceUnsignedLongLongInt(unsigned long long& v1, unsigned long long int& v2) override {
        v1 = Expected::UnsignedLongLong;
        v2 = Expected::UnsignedLongLongInt;
    }

    // char
    virtual void passByReferenceChar(char& v1, signed char& v2, unsigned char& v3) override {
        v1 = Expected::SignedChar;
        v2 = Expected::UnsignedChar;
        v3 = Expected::Char;
    }

    // string
    virtual void passByReferenceString(string& v1) override {
        v1 = Expected::String;
    }

    // floating point
    virtual void passByReferenceFloat(float& v1, double& v2, long double& v3) override {
        v1 = Expected::Float;
        v2 = Expected::Double;
        v3 = Expected::LongDouble;
    }

    virtual void passByReferenceBool(bool& v1) override {
        v1 = Expected::Bool;
    }

    // ****************************************************************************************************************
    // pass by const reference
    // ****************************************************************************************************************
    // int with specific bit number
    virtual bool passByConstReferenceUIntStrict(const uint8_t& v1, const uint16_t& v2, const uint32_t& v3, const uint64_t& v4) override {
        bool result = true;

        if(v1 != Expected::Uint8t) result = false;
        if(v2 != Expected::Uint16t) result = false;
        if(v3 != Expected::Uint32t) result = false;
        if(v4 != Expected::Uint64t) result = false;

        return result;
    }

    virtual bool passByConstReferenceIntStrict(const int8_t& v1, const int16_t& v2, const int32_t& v3, const int64_t& v4) override {
        bool result = true;

        if(v1 != Expected::Int8t) result = false;
        if(v2 != Expected::Int16t) result = false;
        if(v3 != Expected::Int32t) result = false;
        if(v4 != Expected::Int64t) result = false;

        return result;
    }

    // short int
    virtual bool passByConstReferenceShortInt(const short& v1, const short int& v2, const signed short& v3, const signed short int& v4) override {
        bool result = true;

        if(v1 != Expected::Short) result = false;
        if(v2 != Expected::ShortInt) result = false;
        if(v3 != Expected::SignedShort) result = false;
        if(v4 != Expected::SignedShortInt) result = false;

        return result;
    }

    // unsigned short int
    virtual bool passByConstReferenceUnsignedShortInt(const unsigned short& v1, const unsigned short int& v2) override {
        bool result = true;

        if(v1 != Expected::UnsignedShort) result = false;
        if(v2 != Expected::UnsignedShortInt) result = false;

        return result;
    }

    // int
    virtual bool passByConstReferenceInt(const int& v1, const signed& v2, const signed int& v3) override {
        bool result = true;

        if(v1 != Expected::Int) result = false;
        if(v2 != Expected::Signed) result = false;
        if(v3 != Expected::SignedInt) result = false;

        return result;
    }

    // unsigned int
    virtual bool passByConstReferenceUnsignedInt(const unsigned& v1, const unsigned int& v2) override {
        bool result = true;

        if(v1 != Expected::Unsigned) result = false;
        if(v2 != Expected::UnsignedInt) result = false;;

        return result;
    }

    // long int
    virtual bool passByConstReferenceLongInt(const long& v1, const long int& v2, const signed long& v3, const signed long int& v4) override {
        bool result = true;

        if(v1 != Expected::Long) result = false;
        if(v2 != Expected::LongInt) result = false;
        if(v3 != Expected::SignedLong) result = false;
        if(v4 != Expected::SignedLongInt) result = false;

        return result;
    }

    // unsigned long int
    virtual bool passByConstReferenceUnsignedLongInt(const unsigned long& v1, const unsigned long int& v2) override {
        bool result = true;

        if(v1 != Expected::UnsignedLong) result = false;
        if(v2 != Expected::UnsignedLongInt) result = false;

        return result;
    }

    // long long int
    virtual bool passByConstReferenceLongLongInt(const long long& v1, const long long int& v2, const signed long long& v3, const signed long long int& v4) override {
        bool result = true;

        if(v1 != Expected::LongLong) result = false;
        if(v2 != Expected::LongLongInt) result = false;
        if(v3 != Expected::SignedLongLong) result = false;
        if(v4 != Expected::SignedLongLongInt) result = false;

        return result;
    }

    // unsigned long long int
    virtual bool passByConstReferenceUnsignedLongLongInt(const unsigned long long& v1, const unsigned long long int& v2) override {
        bool result = true;

        if(v1 != Expected::UnsignedLongLong) result = false;
        if(v2 != Expected::UnsignedLongLongInt) result = false;

        return result;
    }

    // char
    virtual bool passByConstReferenceChar(const char& v1, const signed char& v2, const unsigned char& v3) override {
        bool result = true;

        if(v1 != Expected::SignedChar) result = false;
        if(v2 != Expected::UnsignedChar) result = false;
        if(v3 != Expected::Char) result = false;

        return result;
    }

    // string
    virtual bool passByConstReferenceString(const string& v1) override {
        bool result = true;

        if(v1 != Expected::String) result = false;

        return result;
    }

    // floating point
    virtual bool passByConstReferenceFloat(const float& v1, const double& v2, const long double& v3) override {
        bool result = true;

        if(v1 != Expected::Float) result = false;
        if(v2 != Expected::Double) result = false;
        if(v3 != Expected::LongDouble) result = false;

        return result;
    }

    // bool
    virtual bool passByConstReferenceBool(const bool& v1) override {
        bool result = true;

        if(v1 != Expected::Bool) result = false;

        return result;
    }

    // struct
    virtual bool passByConstReferenceStructure(const Structure& v1) override
    {
        bool result = true;

        if(v1.field1 != Expected::Structure.field1) result = false;
        if(v1.field2 != Expected::Structure.field2) result = false;

        return result;
    }

    BEGIN_INTERFACE_MAP(ProxyStubsValidatorImp)
    INTERFACE_ENTRY(Exchange::IProxyStubsValidator)
    END_INTERFACE_MAP
};

SERVICE_REGISTRATION(ProxyStubsValidatorImp, 1, 0);

} // namespace WPEFramework

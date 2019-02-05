#pragma once

#include "Module.h"

#include <interfaces/IProxyStubsValidator.h>

namespace WPEFramework {
namespace Expected {

// int with specific bit number
static const uint8_t Uint8t = std::numeric_limits<uint8_t>::max();
static const uint16_t Uint16t = std::numeric_limits<uint16_t>::max();
static const uint32_t Uint32t = std::numeric_limits<uint32_t>::max();
static const uint64_t Uint64t = std::numeric_limits<uint64_t>::max();
static const int8_t Int8t = std::numeric_limits<int8_t>::max();
static const int16_t Int16t = std::numeric_limits<int16_t>::max();
static const int32_t Int32t = std::numeric_limits<int32_t>::max();
static const int64_t Int64t = std::numeric_limits<int64_t>::max();
// short int
static const short Short = std::numeric_limits<short>::max();
static const short int ShortInt = std::numeric_limits<short int>::max();
static const signed short SignedShort = std::numeric_limits<signed short>::max();
static const signed short int SignedShortInt = std::numeric_limits<signed short int>::max();
// unsigned short int
static const unsigned short UnsignedShort = std::numeric_limits<unsigned short>::max();
static const unsigned short int UnsignedShortInt = std::numeric_limits<unsigned short int>::max();
// int
static const int Int = std::numeric_limits<int>::max();
static const signed Signed = std::numeric_limits<signed>::max();
static const signed int SignedInt = std::numeric_limits<signed int>::max();
// unsigned int
static const unsigned Unsigned = std::numeric_limits<unsigned>::max();
static const unsigned int UnsignedInt = std::numeric_limits<unsigned int>::max();
// long int
static const long Long = std::numeric_limits<long>::max();
static const long int LongInt = std::numeric_limits<long int>::max();
static const signed long SignedLong = std::numeric_limits<signed long>::max();
static const signed long int SignedLongInt = std::numeric_limits<signed long int>::max();
// unsigned long int
static const unsigned long UnsignedLong = std::numeric_limits<unsigned long>::max();
static const unsigned long int UnsignedLongInt = std::numeric_limits<unsigned long int>::max();
// long long int
static const long long LongLong = std::numeric_limits<long long>::max();
static const long long int LongLongInt = std::numeric_limits<long long int>::max();
static const signed long long SignedLongLong = std::numeric_limits<signed long long>::max();
static const signed long long int SignedLongLongInt = std::numeric_limits<signed long long int>::max();
// unsigned long long int
static const unsigned long long UnsignedLongLong = std::numeric_limits<unsigned long long>::max();
static const unsigned long long int UnsignedLongLongInt = std::numeric_limits<unsigned long long int>::max();
// char
static const signed char SignedChar = std::numeric_limits<signed char>::max();
static const unsigned char UnsignedChar = std::numeric_limits<unsigned char>::max();
static const char Char = std::numeric_limits<char>::max();
// string
static const string String = _T("string");
// floating point
static const float Float = std::numeric_limits<float>::max();
static const double Double = std::numeric_limits<double>::max();
static const long double LongDouble = std::numeric_limits<long double>::max();
// bool
static const bool Bool = true;
// enum
static const Exchange::IProxyStubsValidator::Enum Enum = Exchange::IProxyStubsValidator::Enum::ENUM_VALUE_2;
static const Exchange::IProxyStubsValidator::ScopedEnum ScopedEnum = Exchange::IProxyStubsValidator::ScopedEnum::ScopedEnumValue2;
static const Exchange::IProxyStubsValidator::ScopedTypedEnum ScopedTypedEnum = Exchange::IProxyStubsValidator::ScopedTypedEnum::ScopedTypedEnumValue2;

} // namespace Expected
} // namespace WPEFramework

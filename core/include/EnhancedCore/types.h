/*
 * Copyright (C) 2021 Liu Baihao.
 * This product is licensed under Enhanced License.
 *
 * This copyright disclaimer is subject to change without notice.
 *
 * This software is a free software,
 * everyone can change, copy, publication, demonstrate, use, etc.
 *
 * If you change and publication this software,
 * must credit the original software source and author's name,
 * and include this copyright disclaimer and
 * the license of this software in your software.
 *
 * This software and documentation may provide
 * third-party content, product and other information.
 * I am not responsible for any loss or damage caused
 * by your access to or use of third-party content, products, etc.
 */

#ifndef ENHANCED_CORE_TYPES_H
#define ENHANCED_CORE_TYPES_H

#include "EnhancedCore/defines.h"

typedef char int8;
typedef short int16;
typedef int int32;
#if defined(WINDOWS_OS) // Windows OS
typedef long long int64;
#elif defined(LINUX_OS) // Linux OS
typedef long int64;
#endif // defined(WINDOWS_OS)

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
#if defined(WINDOWS_OS) /* Windows OS */ || defined(ARCH_32_BIT) /* 32-bit */
typedef unsigned long long uint64;
#elif defined(LINUX_OS) // Linux OS
typedef unsigned long uint64;
#endif // defined(WINDOWS_OS) || defined(ARCH_32_BIT)

typedef float float32;
typedef double float64;
#ifndef COMPILER_MSVC // Non Microsoft Visual C++ compiler
#if defined(ARCH_32_BIT) // 32-bit
typedef long double float96;
#elif defined(ARCH_64_BIT) // 64-bit
typedef long double float128;
#endif // defined(ARCH_32_BIT)
#endif // !COMPILER_MSVC

typedef int64 llong;

typedef uint8 uchar;
typedef uint16 ushort;
typedef uint32 uint;
#if defined(WINDOWS_OS) /* Windows OS */ || defined(ARCH_32_BIT) /* 32-bit */
typedef uint32 ulong;
#elif defined(LINUX_OS) // Linux OS
typedef uint64 ulong;
#endif // defined(WINDOWS_OS) || defined(ARCH_32_BIT)
typedef uint64 ullong;

#ifndef COMPILER_MSVC // Non Microsoft Visual C++ compiler
#if defined(ARCH_32_BIT) // 32-bit
typedef float96 ldouble;
#elif defined(ARCH_64_BIT) // 64-bit
typedef float128 ldouble;
#endif // defined(ARCH_32_BIT)
#else
typedef float64 ldouble;
#endif // !COMPILER_MSVC

typedef uint8 Byte;
typedef uint16 WChar;
#if defined(ARCH_32_BIT) // 32-bit
typedef uint32 Size;
#elif defined(ARCH_64_BIT) // 64-bit
typedef uint64 Size;
#else // Unknown
typedef uint32 Size;
#endif // defined(ARCH_32_BIT)

typedef uint8 byte;
typedef uint16 word;
typedef uint32 dword;
typedef uint64 qword;

#ifdef C_LANGUAGE // C language
typedef int bool;

#ifdef false
#undef false
#endif // false
#ifdef true
#undef true
#endif // true

#define false 0
#define true 1
#endif // C_LANGUAGE

#ifdef CXX_LANGUAGE // C++ language
#ifdef CXX_11_OR_MORE
#define null nullptr
typedef decltype(null) NullType;
#else // below C++11
#define null 0
typedef int NullType;
#endif // CXX_11_OR_MORE
#else // C language
#define null ((void *) 0)
typedef void *NullType;
#endif // CXX_LANGUAGE

#ifndef SUPPRESS_DEFINE_UPPERCASE_TYPES

#ifdef NULL
#undef NULL
#endif // NULL
#ifdef TRUE
#undef TRUE
#endif // TRUE
#ifdef FALSE
#undef FALSE
#endif // FALSE

typedef int8 INT8;
typedef int16 INT16;
typedef int32 INT32;
typedef int64 INT64;

typedef uint8 UINT8;
typedef uint16 UINT16;
typedef uint32 UINT32;
typedef uint64 UINT64;

typedef float32 FLOAT32;
typedef float64 FLOAT64;
#ifndef COMPILER_MSVC // Non Microsoft Visual C++ compiler
#if defined(ARCH_32_BIT) // 32-bit
typedef float96 FLOAT96;
#elif defined(ARCH_64_BIT) // 64-bit
typedef float128 FLOAT128;
#endif // defined(ARCH_32_BIT)
#endif // !COMPILER_MSVC

typedef char CHAR;
typedef short SHORT;
typedef int INT;
typedef long LONG;
typedef llong LLONG;

typedef uchar UCHAR;
typedef ushort USHORT;
typedef uint UINT;
typedef ulong ULONG;
typedef ullong ULLONG;

typedef float FLOAT;
typedef double DOUBLE;
typedef ldouble LDOUBLE;

typedef Byte BYTE_TYPE;
typedef WChar WCHAR_TYPE;
typedef Size SIZE_TYPE;

typedef byte BYTE;
typedef word WORD;
typedef dword DWORD;
typedef qword QWORD;

typedef bool BOOL;
#define TRUE true
#define FALSE false

#define NULL null
typedef NullType NULL_TYPE;

#endif // !SUPPRESS_DEFINE_UPPERCASE_TYPES

#ifdef INT8_MIN
#undef INT8_MIN
#endif // INT8_MIN
#ifdef INT16_MIN
#undef INT16_MIN
#endif // INT16_MIN
#ifdef INT32_MIN
#undef INT32_MIN
#endif // INT32_MIN
#ifdef INT64_MIN
#undef INT64_MIN
#endif // INT64_MIN

#ifdef UINT8_MIN
#undef UINT8_MIN
#endif // UINT8_MIN
#ifdef UINT16_MIN
#undef UINT16_MIN
#endif // UINT16_MIN
#ifdef UINT32_MIN
#undef UINT32_MIN
#endif // UINT32_MIN
#ifdef UINT64_MIN
#undef UINT64_MIN
#endif // UINT64_MIN

#ifdef FLOAT32_MIN
#undef FLOAT32_MIN
#endif // FLOAT32_MIN
#ifdef FLOAT64_MIN
#undef FLOAT64_MIN
#endif // FLOAT64_MIN
#ifdef FLOAT96_MIN
#undef FLOAT96_MIN
#endif // FLOAT96_MIN
#ifdef FLOAT128_MIN
#undef FLOAT128_MIN
#endif // FLOAT128_MIN

#ifdef CHAR_MIN
#undef CHAR_MIN
#endif // CHAR_MIN
#ifdef SHORT_MIN
#undef SHORT_MIN
#endif // SHORT_MIN
#ifdef INT_MIN
#undef INT_MIN
#endif // INT_MIN
#ifdef LONG_MIN
#undef LONG_MIN
#endif // LONG_MIN
#ifdef LLONG_MIN
#undef LLONG_MIN
#endif // LLONG_MIN

#ifdef UCHAR_MIN
#undef UCHAR_MIN
#endif // UCHAR_MIN
#ifdef USHORT_MIN
#undef USHORT_MIN
#endif // USHORT_MIN
#ifdef UINT_MIN
#undef UINT_MIN
#endif // UINT_MIN
#ifdef ULONG_MIN
#undef ULONG_MIN
#endif // ULONG_MIN
#ifdef ULLONG_MIN
#undef ULLONG_MIN
#endif // ULLONG_MIN

#ifdef FLOAT_MIN
#undef FLOAT_MIN
#endif // FLOAT_MIN
#ifdef DOUBLE_MIN
#undef DOUBLE_MIN
#endif // DOUBLE_MIN
#ifdef LDOUBLE_MIN
#undef LDOUBLE_MIN
#endif // LDOUBLE_MIN

#ifdef BYTE_TYPE_MIN
#undef BYTE_TYPE_MIN
#endif // BYTE_TYPE_MIN
#ifdef WCHAR_TYPE_MIN
#undef WCHAR_TYPE_MIN
#endif // WCHAR_TYPE_MIN
#ifdef SIZE_TYPE_MIN
#undef SIZE_TYPE_MIN
#endif // SIZE_TYPE_MIN

#ifdef BYTE_MIN
#undef BYTE_MIN
#endif // BYTE_MIN
#ifdef WORD_MIN
#undef WORD_MIN
#endif // WORD_MIN
#ifdef DWORD_MIN
#undef DWORD_MIN
#endif // DWORD_MIN
#ifdef QWORD_MIN
#undef QWORD_MIN
#endif // QWORD_MIN

#define INT8_MIN ((int8) (-(0xff >> 1) - 1)) // -128
#define INT16_MIN ((int16) (-(0xffff >> 1) - 1)) // -32768
#define INT32_MIN ((int32) (-(0xffffffff >> 1) - 1)) // -2147483648
#define INT64_MIN ((int64) (-(0xffffffffffffffff >> 1) - 1)) // -9223372036854775808

#define UINT8_MIN ((uint8) 0x0) // 0
#define UINT16_MIN ((uint16) 0x0) // 0
#define UINT32_MIN ((uint32) 0x0) // 0
#define UINT64_MIN ((uint64) 0x0) // 0

#define FLOAT32_MIN ((float32) 1.17549435082228750796873653722224568e-38)
#define FLOAT64_MIN ((float64) 2.22507385850720138309023271733240406e-308)
#ifndef COMPILER_MSVC // Non Microsoft Visual C++ compiler
#if defined(ARCH_32_BIT) // 32-bit
#define FLOAT96_MIN 0.0 // Unknown
#elif defined(ARCH_64_BIT) // 64-bit
#define FLOAT128_MIN ((float128) 3.36210314311209350626267781732175260e-4932)
#endif // defined(ARCH_32_BIT)
#endif // !COMPILER_MSVC

#define CHAR_MIN INT8_MIN
#define SHORT_MIN INT16_MIN
#define INT_MIN INT32_MIN
#if defined(WINDOWS_OS) /* Windows OS */ || defined(ARCH_32_BIT) /* 32-bit */
#define LONG_MIN INT32_MIN
#elif defined(LINUX_OS) // Linux OS
#define LONG_MIN INT64_MIN
#else // Unknown
#define LONG_MIN INT64_MIN
#endif // defined(WINDOWS_OS) || defined(ARCH_32_BIT)
#define LLONG_MIN INT64_MIN

#define UCHAR_MIN UINT8_MIN;
#define USHORT_MIN UINT16_MIN;
#define UINT_MIN UINT32_MIN;
#if defined(WINDOWS_OS) /* Windows OS */ || defined(ARCH_32_BIT) /* 32-bit */
#define ULONG_MIN UINT32_MIN
#elif defined(LINUX_OS) // Linux OS
#define ULONG_MIN UINT64_MIN
#else // Unknown
#define ULONG_MIN UINT64_MIN
#endif // defined(WINDOWS_OS) || defined(ARCH_32_BIT)
#define ULLONG_MIN UINT64_MIN

#define FLOAT_MIN FLOAT32_MIN
#define DOUBLE_MIN FLOAT64_MIN
#ifdef COMPILER_MSVC // Microsoft Visual C++
#define LDOUBLE_MIN FLOAT32_MIN
#else // Another compiler
#if defined(ARCH_32_BIT) // 32-bit
#define LDOUBLE_MIN FLOAT96_MIN
#elif defined(ARCH_64_BIT) // 64-bit
#define LDOUBLE_MIN FLOAT128_MIN
#else // Unknown
#define LDOUBLE_MIN FLOAT32_MIN
#endif // defined(ARCH_32_BIT)
#endif // COMPILER_MSVC

#define BYTE_TYPE_MIN UINT8_MIN
#define WCHAR_TYPE_MIN UINT16_MIN
#if defined(ARCH_32_BIT) // 32-bit
#define SIZE_TYPE_MIN UINT32_MIN
#elif defined(ARCH_64_BIT) // 64-bit
#define SIZE_TYPE_MIN UINT64_MIN
#else // Unknown
#define SIZE_TYPE_MIN UINT32_MIN
#endif // ARCH_64_BIT

#define BYTE_MIN UINT8_MIN
#define WORD_MIN UINT16_MIN
#define DWORD_MIN UINT32_MIN
#define QWORD_MIN UINT64_MIN

#ifdef INT8_MAX
#undef INT8_MAX
#endif // INT8_MAX
#ifdef INT16_MAX
#undef INT16_MAX
#endif // INT16_MAX
#ifdef INT32_MAX
#undef INT32_MAX
#endif // INT32_MAX
#ifdef INT64_MAX
#undef INT64_MAX
#endif // INT64_MAX

#ifdef UINT8_MAX
#undef UINT8_MAX
#endif // UINT8_MAX
#ifdef UINT16_MAX
#undef UINT16_MAX
#endif // UINT16_MAX
#ifdef UINT32_MAX
#undef UINT32_MAX
#endif // UINT32_MAX
#ifdef UINT64_MAX
#undef UINT64_MAX
#endif // UINT64_MAX

#ifdef FLOAT32_MAX
#undef FLOAT32_MAX
#endif // FLOAT32_MAX
#ifdef FLOAT64_MAX
#undef FLOAT64_MAX
#endif // FLOAT64_MAX
#ifdef FLOAT96_MAX
#undef FLOAT96_MAX
#endif // FLOAT96_MAX
#ifdef FLOAT128_MAX
#undef FLOAT128_MAX
#endif // FLOAT128_MAX

#ifdef CHAR_MAX
#undef CHAR_MAX
#endif // CHAR_MAX
#ifdef SHORT_MAX
#undef SHORT_MAX
#endif // SHORT_MAX
#ifdef INT_MAX
#undef INT_MAX
#endif // INT_MAX
#ifdef LONG_MAX
#undef LONG_MAX
#endif // LONG_MAX
#ifdef LLONG_MAX
#undef LLONG_MAX
#endif // LLONG_MAX

#ifdef UCHAR_MAX
#undef UCHAR_MAX
#endif // UCHAR_MAX
#ifdef USHORT_MAX
#undef USHORT_MAX
#endif // USHORT_MAX
#ifdef UINT_MAX
#undef UINT_MAX
#endif // UINT_MAX
#ifdef ULONG_MAX
#undef ULONG_MAX
#endif // ULONG_MAX
#ifdef ULLONG_MAX
#undef ULLONG_MAX
#endif // ULLONG_MAX

#ifdef FLOAT_MAX
#undef FLOAT_MAX
#endif // FLOAT_MAX
#ifdef DOUBLE_MAX
#undef DOUBLE_MAX
#endif // DOUBLE_MAX
#ifdef LDOUBLE_MAX
#undef LDOUBLE_MAX
#endif // LDOUBLE_MAX

#ifdef BYTE_TYPE_MAX
#undef BYTE_TYPE_MAX
#endif // BYTE_TYPE_MAX
#ifdef WCHAR_TYPE_MAX
#undef WCHAR_TYPE_MAX
#endif // WCHAR_TYPE_MAX
#ifdef SIZE_TYPE_MAX
#undef SIZE_TYPE_MAX
#endif // SIZE_TYPE_MAX

#ifdef BYTE_MAX
#undef BYTE_MAX
#endif // BYTE_MAX
#ifdef WORD_MAX
#undef WORD_MAX
#endif // WORD_MAX
#ifdef DWORD_MAX
#undef DWORD_MAX
#endif // DWORD_MAX
#ifdef QWORD_MAX
#undef QWORD_MAX
#endif // QWORD_MAX

#define INT8_MAX ((int8) (0xff >> 1)) // 127
#define INT16_MAX ((int16) (0xffff >> 1)) // 32767
#define INT32_MAX ((int32) (0xffffffff >> 1)) // 2147483647
#define INT64_MAX ((int64) (0xffffffffffffffff >> 1)) // 9223372036854775807

#define UINT8_MAX ((uint8) 0xff) // 255
#define UINT16_MAX ((uint16) 0xffff) // 65535
#define UINT32_MAX ((uint32) 0xffffffff) // 4294967295
#define UINT64_MAX ((uint64) 0xffffffffffffffff) // 18446744073709551615

#define FLOAT32_MAX ((float32) 3.40282346638528859811704183484516925e+38)
#define FLOAT64_MAX ((float64) 1.79769313486231570814527423731704357e+308)
#ifndef COMPILER_MSVC // Non Microsoft Visual C++ compiler
#if defined(ARCH_32_BIT) // 32-bit
#define FLOAT96_MAX 0.0 // Unknown
#elif defined(ARCH_64_BIT) // 64-bit
#define FLOAT128_MAX ((float128) 1.18973149535723176502126385303097021e+4932)
#endif // defined(ARCH_32_BIT)
#endif // !COMPILER_MSVC

#define CHAR_MAX INT8_MAX
#define SHORT_MAX INT16_MAX
#define INT_MAX INT32_MAX
#if defined(WINDOWS_OS) /* Windows OS */ || defined(ARCH_32_BIT) /* 32-bit */
#define LONG_MAX INT32_MAX
#elif defined(LINUX_OS) // Linux OS
#define LONG_MAX INT64_MAX
#else // Unknown
#define LONG_MAX INT64_MAX
#endif // defined(WINDOWS_OS) || defined(ARCH_32_BIT)
#define LLONG_MAX INT64_MAX

#define UCHAR_MAX UINT8_MAX
#define USHORT_MAX UINT16_MAX
#define UINT_MAX UINT32_MAX
#if defined(WINDOWS_OS) /* Windows OS */ || defined(ARCH_32_BIT) /* 32-bit */
#define ULONG_MAX UINT32_MAX
#elif defined(LINUX_OS) // Linux OS
#define ULONG_MAX UINT64_MAX
#else // Unknown
#define ULONG_MAX UINT64_MAX
#endif // defined(WINDOWS_OS) || defined(ARCH_32_BIT)
#define ULLONG_MAX UINT64_MAX

#define FLOAT_MAX FLOAT32_MAX
#define DOUBLE_MAX FLOAT64_MAX
#ifdef COMPILER_MSVC // Microsoft Visual C++
#define LDOUBLE_MAX FLOAT32_MAX
#else // Another compiler
#if defined(ARCH_32_BIT) // 32-bit
#define LDOUBLE_MAX FLOAT96_MAX
#elif defined(ARCH_64_BIT) // 64-bit
#define LDOUBLE_MAX FLOAT128_MAX
#else // Unknown
#define LDOUBLE_MAX FLOAT32_MAX
#endif // defined(ARCH_32_BIT)
#endif // COMPILER_MSVC

#define BYTE_TYPE_MAX UINT8_MAX
#define WCHAR_TYPE_MAX UINT16_MAX
#if defined(ARCH_32_BIT) // 32-bit
#define SIZE_TYPE_MAX UINT32_MAX
#elif defined(ARCH_64_BIT) // 64-bit
#define SIZE_TYPE_MAX UINT64_MAX
#else // Unknown
#define SIZE_TYPE_MAX UINT32_MAX
#endif // ARCH_64_BIT

#define BYTE_MAX UINT8_MAX
#define WORD_MAX UINT16_MAX
#define DWORD_MAX UINT32_MAX
#define QWORD_MAX UINT64_MAX

#ifdef POSITIVE_INFINITY
#undef POSITIVE_INFINITY
#endif // POSITIVE_INFINITY
#ifdef NEGATIVE_INFINITY
#undef NEGATIVE_INFINITY
#endif // NEGATIVE_INFINITY
#ifdef INFINITY
#undef INFINITY
#endif // INFINITY
#ifdef NAN
#undef NAN
#endif // NaN

#ifdef COMPILER_MSVC // Microsoft Visual C++
#define POSITIVE_INFINITY ((double) (1e+300 * 1e+300)) // Positive infinity: inf
#define NEGATIVE_INFINITY (-POSITIVE_INFINITY) // Negative infinity: -inf
#define INFINITY POSITIVE_INFINITY // Infinity: inf
#define NAN ((double) (INFINITY * 0.0)) // Not-a-Number: -nan(ind)
#else // Another compiler
#define POSITIVE_INFINITY (1.0 / 0.0) // Positive infinity: inf
#define NEGATIVE_INFINITY (-1.0 / 0.0) // Negative infinity: -inf
#define INFINITY POSITIVE_INFINITY // Infinity: inf
#define NAN (0.0 / 0.0) // Not-a-Number: nan
#endif // COMPILER_MSVC

#endif // !ENHANCED_CORE_TYPES_H
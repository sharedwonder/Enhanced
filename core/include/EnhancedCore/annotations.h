/*
 * Copyright (C) 2021 Liu Baihao. All rights reserved.
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

/*!
 * This file provides annotations for APIs.
 * Restrictive annotations don't affect compilation,
 * they don't have practical significance.
 * Attribute annotations may affect compilation.
 *
 * <p>* I will join more annotations at future.</p>
 *
 * @note The annotation with round brackets has arguments.
 *
 * @verbatim
 *
 * Restrictive annotations:
 *
 *     $Unsupported()        Indicates an environment not supported by the API.
 *
 *     $Out                  Sets the argument inside the function and pass it out
 *                           The argument must be a pointer or reference.
 *
 *     $InOut                Passes a argument and
 *                           sets the argument inside the function and pass it out.
 *
 *     $Requires             Indicates passed the pointer argument
 *                           should not be null.
 *
 *     $OutNotIgnored        Sets the argument inside the function and pass it out.
 *                           Passed data should not ignore.
 *
 *     $InOutNotIgnored      Passes a argument and
 *                           sets the argument inside the function and pass it out.
 *                           Passed data should not ignore.
 *
 *     $NotNull              Indicates the pointer cannot be null.
 *
 *     $Unused               Unused argument.
 *
 *     $RetNotIgnored()      The return value cannot be ignored.
 *
 *     $RequiresRelease      Indicates the programmer release the pointer
 *                           (return value or argument).
 *
 *     $RetRequiresRelease() Merges $RetNotIgnored() and $RequiresRelease.
 *
 *     $CaseFallThrough()    Suppress warning: "switch-case" statement without
 *                           break statement.
 *
 * Attribute annotations:
 *
 *     $Attribute()          Adds an attribute to the API.
 *
 *     $NoThrow              Declare that this function does not
 *                           throw an exception (for C++11, you should use noexcept).
 *
 *     $NoVtable             Virtual tables are not created for the class.
 *
 *     $NoInline             Prevents the compiler from inlining
 *                           the function/method.
 *
 *     $NoReturn             Indicates the function/method has no a return value.
 *
 * @endverbatim
 */

#ifndef ENHANCED_ANNOTATIONS_H
#define ENHANCED_ANNOTATIONS_H

#include "EnhancedCore/defines.h"

// =============================Restrictive annotations============================

#ifdef COMPILER_MSVC
#pragma warning(disable: 4003)
#endif // COMPILER_MSVC

#define $Unsupported(options)

#ifdef COMPILER_MSVC
#include <sal.h>
#endif // COMPILER_MSVC

#ifdef COMPILER_MSVC
#define $Optional _In_opt_
#define $Out _Out_opt_
#define $InOut _Inout_opt_
#define $OutNotIgnored _Out_
#define $InRequiredOutNotIgnored _Inout_
#define $NotNull _Notnull_
#else
#define $Optional
#define $Out
#define $InOut
#define $OutNotIgnored
#define $InRequiredOutNotIgnored
#define $NotNull
#endif // COMPILER_MSVC

#define $Unused [[maybe_unused]]

#ifdef CXX_20_OR_MORE
#define $RetNotIgnored(options) [[nodiscard options]]
#elif defined(CXX_17_OR_MORE) // C++17 or more
#define $RetNotIgnored(options) [[nodiscard]]
#elif defined(COMPILER_MSVC) // Microsoft Visual C++ compiler
#define $RetNotIgnored(options) _Check_return_
#else
#define $RetNotIgnored(options)
#endif // CXX_20_OR_MORE

#define $RequiresRelease

#define $RetRequiresRelease(options) $RetNotIgnored(options) $RequiresRelease

#ifdef CXX_14_OR_MORE
#define $Deprecated(options) [[deprecated options]]
#else
#define $Deprecated(options)
#endif // CXX_14_OR_MORE

// ==============================Attribute annotations=============================

#ifdef COMPILER_MSVC
#define $Attribute(options) __declspec options
#else
#define $Attribute(options) __attribute__(options)
#endif // COMPILER_MSVC

#ifdef CXX_LANGUAGE
#define $NoThrow $Attribute((nothrow))
#define $NoVtable $Attribute((novtable))
#endif // CXX_LANGUAGE

#define $NoInline $Attribute((noinline))
#define $NoReturn $Attribute((noreturn))

#endif // !ENHANCED_ANNOTATIONS_H
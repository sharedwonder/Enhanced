/*
 * Copyright (C) 2022 Liu Baihao. All rights reserved.
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

#ifndef ENHANCED_BASIC_UTILITY_LARGE0INTEGER_H
#define ENHANCED_BASIC_UTILITY_LARGE0INTEGER_H

#include "EnhancedCore/defines.h"
#include "EnhancedCore/types.h"

#include "EnhancedBasic/defines.h"

#if defined(C_LANGUAGE) /* C language */ || defined(ENHANCED_BASIC_C_MODE)

EXTERN_C_START

EXTERN_C_END

#else // C++ language

namespace EnhancedBasic {
    namespace Utility {
        class ENHANCED_BASIC_API LargeInteger {
        private:
            Byte *bytes;

            Byte isNegative;

            Size size;

            explicit LargeInteger(Size size);

        public:
            static LargeInteger newNumber(Size size);

            template <typename Type>
            LargeInteger(Type number);

            LargeInteger add(LargeInteger number);

            LargeInteger sub(LargeInteger number);

            LargeInteger mul(LargeInteger number);

            LargeInteger div(LargeInteger number);
        };
    } // namespace Utility
} // namespace EnhancedBasic

#endif // defined(C_LANGUAGE) || defined(ENHANCED_BASIC_C_MODE)

#endif // !ENHANCED_BASIC_UTILITY_LARGE0INTEGER_H

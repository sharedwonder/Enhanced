/*
 * Copyright (C) 2022 Liu Baihao. All rights reserved.
 * This software is licensed under Enhanced License.
 *
 * This copyright notice is subject to change without notice.
 *
 * This software is a free software, everyone can change,
 * copy, publication, demonstrate, use, etc.
 *
 * This software and documentation may provide
 * third-party content, product and other information.
 * The authors or copyright holders be not responsible for any loss or damage
 * caused by your access to or use of third-party content, products, etc.
 *
 * For any loss or damage caused by This software,
 * the authors or copyright holders may provide possible solutions,
 * but it does not mean that the authors or copyright holders
 * will definitely solve the problem.
 * In no event shall the author or copyright
 * owner be liable for any claims, damages or other liabilities.
 *
 * You should see the Enhanced License in this software, if not, visit
 * <https://sharedwonder.github.io/enhanced-website/ENHANCED-LICENSE.txt>
 */

#ifndef ENHANCED_BASIC_UTILITY_LARGE0INTEGER_H
#define ENHANCED_BASIC_UTILITY_LARGE0INTEGER_H

#include "EnhancedCore/defines.h"
#include "EnhancedCore/types.h"

#include "EnhancedBasic/export.h"

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

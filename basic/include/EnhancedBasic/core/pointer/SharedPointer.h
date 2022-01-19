/*
 * Copyright (C) 2022 Liu Baihao. All rights reserved.
 * This software is licensed under Enhanced License.
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

#ifndef ENHANCED_BASIC_POINTER_SHARED0POINTER_H
#define ENHANCED_BASIC_POINTER_SHARED0POINTER_H

#include "EnhancedCore/defines.h"
#include "EnhancedCore/types.h"
#include "EnhancedCore/annotations.h"

#ifdef CXX_LANGUAGE // C++ language

namespace EnhancedBasic {
    namespace core {
        namespace pointer {
            class SharedPointer0 {
            private:
                Size *referenceCount;

            protected:
                void *pointer;

                struct GenericsOperator {
                    void (*destroy)(void *ptr);
                };

                GenericsOperator genericsOperator;

                SharedPointer0(void *ptr, GenericsOperator genericsOperator);

                SharedPointer0(const SharedPointer0 &other);

                virtual ~SharedPointer0() noexcept;

                void release0() noexcept;

                void assign0(void *value) noexcept;

                void assign0(const SharedPointer0 &other) noexcept;
            };

            template <typename Type>
            class SharedPointer final : private SharedPointer0 {
            private:
                static void destroy(void *ptr);

            public:
                SharedPointer(Type *ptr = null);

                SharedPointer(const SharedPointer<Type> &other);

                void release() noexcept;

                $RetNotIgnored()
                SharedPointer<Type> operator+(Size offset) const noexcept;

                $RetNotIgnored()
                SharedPointer<Type> operator-(Size offset) const noexcept;

                $RetNotIgnored()
                Type **operator&() noexcept;

                $RetNotIgnored()
                Type *operator->() noexcept;

                $RetNotIgnored()
                Type &operator*() noexcept;

                $RetNotIgnored()
                Type &operator[](Size offset) noexcept;

                SharedPointer<Type> &operator=(Type *value) noexcept;

                SharedPointer<Type> &operator=(const SharedPointer<Type> &other) noexcept;

                SharedPointer<Type> operator+=(Size offset) noexcept;

                SharedPointer<Type> &operator++() noexcept;

                const SharedPointer<Type> operator++(int) noexcept;

                SharedPointer<Type> operator-=(Size offset) noexcept;

                SharedPointer<Type> &operator--() noexcept;

                const SharedPointer<Type> operator--(int) noexcept;

                $RetNotIgnored()
                operator Type *() noexcept;
            };
        } // namespace pointer
    }
} // namespace EnhancedBasic

#include "EnhancedBasic/core/pointer/SharedPointer.tcc"

#endif // CXX_LANGUAGE

#endif // !ENHANCED_BASIC_POINTER_SHARED0POINTER_H

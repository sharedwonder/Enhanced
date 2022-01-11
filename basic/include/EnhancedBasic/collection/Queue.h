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

#ifndef ENHANCED_BASIC_COLLECTION_QUEUE_H
#define ENHANCED_BASIC_COLLECTION_QUEUE_H

#include "EnhancedCore/defines.h"
#include "EnhancedCore/annotations.h"
#include "EnhancedCore/types.h"

#include "EnhancedBasic/collection/Collection.h"

#ifdef CXX_LANGUAGE // C++ language

namespace EnhancedBasic {
    namespace Collection {
        template <typename Type>
        interface Queue : public Collection<Type> {
            $RetNotIgnored()
            virtual Type &getFirst() const = 0;

            $RetNotIgnored()
            virtual Type &getLast() const = 0;

            $RetNotIgnored()
            virtual Type &get(Size index) const = 0;

            $RetNotIgnored()
            virtual Type &operator[](Size index) const = 0;

            $RetRequiresRelease()
            virtual Queue<Type> *copy() const = 0;

            virtual void addLast(const Type &element) = 0;

            virtual Type removeFirst() = 0;

            virtual void add(const Type &element) = 0;

            virtual Type remove() = 0;

            virtual void push(const Type &element) = 0;

            virtual Type popup() = 0;
        };
    } // namespace Collection
} // namespace EnhancedBasic

#endif // CXX_LANGUAGE

#endif // !ENHANCED_BASIC_COLLECTION_QUEUE_H
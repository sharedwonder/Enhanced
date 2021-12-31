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

#ifndef ENHANCED_CONTAINER_COLLECTION_REFERENCE_REFERENCE0QUEUE_H
#define ENHANCED_CONTAINER_COLLECTION_REFERENCE_REFERENCE0QUEUE_H

#include "EnhancedCore/defines.h"
#include "EnhancedCore/annotations.h"
#include "EnhancedCore/types.h"

#include "EnhancedContainer/collection/Collection.h"
#include "EnhancedContainer/collection/Queue.h"

#ifdef CXX_LANGUAGE // C++ language

namespace EnhancedContainer {
    namespace Collection {
        namespace Referenced {
            template <typename Type>
            interface ReferencedQueue : public Queue<Type> {
                virtual ReferencedQueue<Type> *copy() const = 0;
            };
        } // namespace Referenced
    } // namespace Collection
} // namespace EnhancedContainer

#endif // CXX_LANGUAGE

#endif // !ENHANCED_CONTAINER_COLLECTION_REFERENCE_REFERENCE0QUEUE_H

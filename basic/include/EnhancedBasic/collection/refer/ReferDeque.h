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
 * The Licensor is not responsible for any loss or damage
 * caused by your access to or use of third-party content, products, etc.
 *
 * For any loss or damage caused by this software,
 * the licensor may provide possible solutions,
 * but it does not mean that the licensor will definitely solve the problem.
 * In no event shall the licensor be liable for any claims,
 * damages or other liabilities.
 *
 * You should see a copy of Enhanced License in this software, if not, visit
 * <https://sharedwonder.github.io/enhanced-website/ENHANCED-LICENSE.txt>
 */

#ifndef ENHANCED_BASIC_COLLECTION_REFERENCE_REFERENCE0DEQUE_H
#define ENHANCED_BASIC_COLLECTION_REFERENCE_REFERENCE0DEQUE_H

#include "EnhancedCore/defines.h"
#include "EnhancedCore/types.h"
#include "EnhancedCore/annotations.h"

#include "EnhancedBasic/collection/Deque.h"
#include "EnhancedBasic/collection/refer/ReferQueue.h"

#ifdef CXX_LANGUAGE // C++ language

namespace EnhancedBasic {
    namespace collection {
        namespace refer {
            /*
             * When you build project with Microsoft Visual C++ Compiler,
             * If you don't explicitly extend the "Collection" class, you will see an error in compiling.
             * The compiler thinks the return type of virtual function 'copy' isn't
             * covariant with the return type the super method.
             * So the class must explicitly extend the "Collection" class.
             *
             * But when the class explicitly extend the "Collection" class,
             * The compiler show a warning (C4584), it thinks the class already extended "Collection" class.
             * So I use "#pragma warning(disable: 4584)" to disable the warning.
             */
        #ifdef COMPILER_MSVC
        #pragma warning(push)
        #pragma warning(disable: 4584)
            template <typename Type>
            struct ReferDeque : public Collection<Type>, public Queue<Type>,
                public Deque<Type>, public ReferQueue<Type> {
            #else
            template <typename Type>
            struct ReferDeque : public Deque<Type>, public ReferQueue<Type> {
            #endif // COMPILER_MSVC
                $RetNotIgnored()
                    virtual Size getLength() const = 0;

                $RetNotIgnored()
                    virtual bool isEmpty() const = 0;

                virtual Type& getFirst() const = 0;

                virtual Type& getLast() const = 0;

                virtual Type& get(Size index) const = 0;

                virtual Type& operator[](Size index) const = 0;

                virtual bool contain(const Type& value) const = 0;

                $RetNotIgnored()
                    typename core::Iterable<Type>::ForeachIterator begin() const override {
                    return Deque<Type>::begin();
                }

                $RetNotIgnored()
                    UnusedType end() const override {
                    return Deque<Type>::end();
                }

                virtual core::Iterator<Type>* iterator() const = 0;

                $RetRequiresRelease()
                    virtual ReferDeque<Type>* copy() const = 0;

                virtual void addLast(const Type& element) = 0;

                virtual Type removeLast() = 0;

                virtual void addFirst(const Type& element) = 0;

                virtual Type removeFirst() = 0;

                virtual void add(const Type& element) = 0;

                virtual Type remove() = 0;

                virtual void push(const Type& element) = 0;

                virtual Type popup() = 0;
            };
            } // namespace refer
        } // namespace collection
    } // namespace EnhancedBasic

#endif // CXX_LANGUAGE

#endif // !ENHANCED_BASIC_COLLECTION_REFERENCE_REFERENCE0DEQUE_H
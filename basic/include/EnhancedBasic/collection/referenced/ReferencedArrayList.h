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

#ifndef ENHANCED_BASIC_COLLECTION_REFERENCE_REFERENCED0ARRAY0LIST_H
#define ENHANCED_BASIC_COLLECTION_REFERENCE_REFERENCED0ARRAY0LIST_H

#include "EnhancedCore/defines.h"
#include "EnhancedCore/types.h"
#include "EnhancedCore/annotations.h"

#include "EnhancedBasic/export.h"

#include "EnhancedBasic/core/Iterable.h"
#include "EnhancedBasic/core/Iterator.h"

#include "EnhancedBasic/generic/Generic.h"

#include "EnhancedBasic/collection/RandomAccess.h"
#include "EnhancedBasic/collection/referenced/ReferencedList.h"

#ifdef CXX_LANGUAGE // C++ language

namespace BasicGenericImpl {
    namespace collection {
        namespace referenced {
            class ENHANCED_BASIC_API ReferencedArrayListImpl {
            private:
                void **elements;

                Size length;

                Size maxCount;

            protected:
                struct GenericOperator {
                    bool (*equals)(GenericReference, GenericReference);
                };

                class ENHANCED_BASIC_API ReferencedArrayListIteratorImpl {
                    friend class ReferencedArrayListImpl;

                private:
                    const ReferencedArrayListImpl *referenceArrayList;

                    mutable void **indexer;

                    mutable bool isFirst;

                    void **end;

                protected:
                    explicit ReferencedArrayListIteratorImpl(const ReferencedArrayListImpl *referenceArrayList);

                    virtual ~ReferencedArrayListIteratorImpl() noexcept;

                    $RetNotIgnored()
                    bool hasNext0() const;

                    void next0() const;

                    $RetNotIgnored()
                    bool each0() const;

                    $RetNotIgnored()
                    GenericReference get0() const;

                    void reset0() const;

                    $RetNotIgnored()
                    Size count0() const;
                };

                GenericOperator genericOperator;

                mutable ReferencedArrayListIteratorImpl *iterator;

                ReferencedArrayListImpl(Size length, GenericOperator genericOperator);

                ReferencedArrayListImpl(const ReferencedArrayListImpl &other);

                virtual ~ReferencedArrayListImpl() noexcept;

                $RetNotIgnored()
                Size getLength0() const;

                $RetNotIgnored()
                bool isEmpty0() const;

                $RetNotIgnored()
                GenericReference get0(Size index) const;

                $RetNotIgnored()
                bool contain0(GenericReference value) const;

                void add0(GenericReference element);

                void remove0();

                void expand0(Size size);

                void shrink0(Size size);
            };

        }
    }
}

namespace EnhancedBasic {
    namespace collection {
        namespace referenced {
            template <typename Type>
            class ReferencedArrayList final : public ReferencedList<Type>, public RandomAccess<Type>,
                                              private BasicGenericImpl::collection::referenced::ReferencedArrayListImpl {
            private:
                using ReferencedArrayListImpl = BasicGenericImpl::collection::referenced::ReferencedArrayListImpl;

                class ReferencedArrayListIterator : public core::Iterator<Type>,
                                                    private ReferencedArrayListImpl::ReferencedArrayListIteratorImpl {
                    friend struct core::Iterable<Type>;

                public:
                    explicit inline ReferencedArrayListIterator(const ReferencedArrayList<Type> *referencedArrayList);

                    $RetNotIgnored()
                    inline bool hasNext() const override;

                    inline const core::Iterator<Type> *next() const override;

                    $RetNotIgnored()
                    inline bool each() const override;

                    $RetNotIgnored()
                    inline Type &get() const override;

                    inline void reset() const override;

                    $RetNotIgnored()
                    inline Size count() const override;
                };

                $RetNotIgnored()
                static bool equals(GenericReference element, GenericReference value);

            public:
                explicit inline ReferencedArrayList();

                explicit inline ReferencedArrayList(Size maxCount);

                inline ReferencedArrayList(const ReferencedArrayList<Type> &other);

                $RetNotIgnored()
                inline Size getLength() const override;

                $RetNotIgnored()
                inline bool isEmpty() const override;

                $RetNotIgnored()
                inline Type &get(Size index) const override;

                $RetNotIgnored()
                inline Type &operator[](Size index) const override;

                inline core::Iterator<Type> *iterator() const override;

                $RetNotIgnored()
                inline bool contain(const Type &value) const override;

                $RetRequiresRelease()
                inline ReferencedArrayList<Type> *copy() const override;

                inline void add(const Type &element) override;

                inline Type remove() override;
            };
        } // namespace Reference
    } // namespace collection
} // namespace EnhancedBasic

#include "EnhancedBasic/collection/referenced/ReferencedArrayList.hpp"

#endif // CXX_LANGUAGE

#endif // !ENHANCED_BASIC_COLLECTION_REFERENCE_REFERENCED0ARRAY0LIST_H

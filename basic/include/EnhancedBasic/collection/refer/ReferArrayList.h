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

#ifndef ENHANCED_BASIC_COLLECTION_REFERENCE_REFER0ARRAY0LIST_H
#define ENHANCED_BASIC_COLLECTION_REFERENCE_REFER0ARRAY0LIST_H

#include "EnhancedCore/defines.h"
#include "EnhancedCore/types.h"
#include "EnhancedCore/annotations.h"

#include "EnhancedBasic/export.h"

#include "EnhancedBasic/core/Iterable.h"
#include "EnhancedBasic/core/Iterator.h"

#include "EnhancedBasic/generic/Generic.h"

#include "EnhancedBasic/collection/RandomAccess.h"
#include "EnhancedBasic/collection/refer/ReferList.h"

#ifdef CXX_LANGUAGE // C++ language

namespace BasicGenericImpl {
    namespace collection {
        namespace refer {
            class ENHANCED_BASIC_API ReferArrayListImpl {
            private:
                void** elements;

                Size length;

                Size maxCount;

            protected:
                struct GenericOperator {
                    bool (*equals)(GenericReference, GenericReference);
                };

                class ENHANCED_BASIC_API ReferArrayListIteratorImpl {
                    friend class ReferArrayListImpl;

                private:
                    const ReferArrayListImpl* referenceArrayList;

                    mutable void** indexer;

                    mutable bool isFirst;

                    void** end;

                protected:
                    explicit ReferArrayListIteratorImpl(const ReferArrayListImpl* referenceArrayList);

                    virtual ~ReferArrayListIteratorImpl() noexcept;

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

                mutable ReferArrayListIteratorImpl* iterator;

                ReferArrayListImpl(Size maxCount, GenericOperator genericOperator);

                ReferArrayListImpl(const ReferArrayListImpl& other);

                virtual ~ReferArrayListImpl() noexcept;

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
        namespace refer {
            template <typename Type>
            class ReferArrayList final : public ReferList<Type>, public RandomAccess<Type>,
                private BasicGenericImpl::collection::refer::ReferArrayListImpl {
            private:
                using ReferArrayListImpl = BasicGenericImpl::collection::refer::ReferArrayListImpl;

                class ReferArrayListIterator : public core::Iterator<Type>,
                    private ReferArrayListImpl::ReferArrayListIteratorImpl {
                    friend struct core::Iterable<Type>;

                public:
                    explicit inline ReferArrayListIterator(const ReferArrayList<Type>* referArrayList);

                    $RetNotIgnored()
                        inline bool hasNext() const override;

                    inline const core::Iterator<Type>* next() const override;

                    $RetNotIgnored()
                        inline bool each() const override;

                    $RetNotIgnored()
                        inline Type& get() const override;

                    inline void reset() const override;

                    $RetNotIgnored()
                        inline Size count() const override;
                };

                $RetNotIgnored()
                    static bool equals(GenericReference element, GenericReference value);

            public:
                explicit inline ReferArrayList();

                explicit inline ReferArrayList(Size maxCount);

                inline ReferArrayList(const ReferArrayList<Type>& other);

                $RetNotIgnored()
                    inline Size getLength() const override;

                $RetNotIgnored()
                    inline bool isEmpty() const override;

                $RetNotIgnored()
                    inline Type& get(Size index) const override;

                $RetNotIgnored()
                    inline Type& operator[](Size index) const override;

                inline core::Iterator<Type>* iterator() const override;

                $RetNotIgnored()
                    inline bool contain(const Type& value) const override;

                $RetRequiresRelease()
                    inline ReferArrayList<Type>* copy() const override;

                inline void add(const Type& element) override;

                inline Type remove() override;
            };
        } // namespace Reference
    } // namespace collection
} // namespace EnhancedBasic

#include "EnhancedBasic/collection/refer/ReferArrayList.hpp"

#endif // CXX_LANGUAGE

#endif // !ENHANCED_BASIC_COLLECTION_REFERENCE_REFER0ARRAY0LIST_H
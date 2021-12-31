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


#ifndef ENHANCED_CONTAINER_COLLECTION_REFERENCE_REFERENCED0ARRAY0LIST_H
#define ENHANCED_CONTAINER_COLLECTION_REFERENCE_REFERENCED0ARRAY0LIST_H

#include "EnhancedCore/defines.h"
#include "EnhancedCore/annotations.h"
#include "EnhancedCore/types.h"

#include "EnhancedContainer/defines.h"

#include "EnhancedContainer/collection/RandomAccess.h"
#include "EnhancedContainer/collection/referenced/ReferencedList.h"

#ifdef CXX_LANGUAGE // C++ language

namespace EnhancedContainer {
    namespace Collection {
        namespace Referenced {
            /*!
             * This class is the universal implementation class for
             * the template class "ReferencedArrayList\<Type\>".
             *
             * @note You should not extend this class from another class.
             *       And you should not instantiate this class directly.
             *       The correct approach is to instantiate the
             *       template class "ReferencedArrayList\<Type\>" (with "Type" as a type).
             *       Because this class has no public methods.
             *
             * <p>The meaning of this class is to separate the actual
             * implementation of the functions in the template class
             * "ReferencedArrayList\<Type\>" from the definition of
             * the template class "ReferencedArrayList\<Type\>".</p>
             *
             * <p>Methods in the template class "ReferencedArrayList\<Type\>" Type "only cast.</p>
             * <p>You'll see similar code in other classes in this module.</p>
             */
            class ENHANCED_CONTAINER_API ReferencedArrayList0 {
            private:
                Size maxCount;

                void **elements;

                Size length;

            protected:
                struct ElementOperator {
                    bool (*elementEqual)(void *&, void *&);
                };

                class ENHANCED_CONTAINER_API ReferencedArrayListIterator0 {
                private:
                    const ReferencedArrayList0 *referenceArrayList;

                    mutable void **indexer;

                    mutable bool isFirst;

                    const void **end;

                protected:
                    explicit ReferencedArrayListIterator0(const ReferencedArrayList0 *referenceArrayList);

                    $RetNotIgnored()
                    bool hasNext0() const;

                    void next0() const;

                    $RetNotIgnored()
                    bool each0() const;

                    $RetNotIgnored()
                    void *get0() const;

                    void reset0() const;

                    $RetNotIgnored()
                    Size count0() const;

                public:
                    virtual ~ReferencedArrayListIterator0() noexcept;
                };

                ElementOperator elementOperator;

                mutable ReferencedArrayListIterator0 *iterator;

                ReferencedArrayList0(Size length, ElementOperator elementOperator);

                virtual ~ReferencedArrayList0() noexcept;

                $RetNotIgnored()
                Size getLength0() const;

                $RetNotIgnored()
                bool isEmpty0() const;

                $RetNotIgnored()
                void *&get0(Size index) const;

                $RetNotIgnored()
                bool contain0(const void *element) const;

                void add0(const void *element);

                void remove0();

                void expand0(Size size);

                void shrink0(Size size);
            };

            template <typename Type>
            class ReferencedArrayList final : public ReferencedList<Type>, public RandomAccess<Type>,
                                              private ReferencedArrayList0 {
            private:
                class ReferencedArrayListIterator : public Iterator<Type>,
                                                    private ReferencedArrayListIterator0 {
                    friend class ReferencedArrayList<Type>;

                public:
                    inline explicit ReferencedArrayListIterator(const ReferencedArrayList<Type> *arrayList) :
                        ReferencedArrayListIterator0(arrayList) {}

                    $RetNotIgnored()
                    inline bool hasNext() const override {
                        return ReferencedArrayListIterator0::hasNext0();
                    }

                    inline const Iterator<Type> *next() const override {
                        ReferencedArrayListIterator0::next0();
                        return this;
                    }

                    $RetNotIgnored()
                    inline bool each() const override {
                        return ReferencedArrayListIterator0::each0();
                    }

                    $RetNotIgnored()
                    inline Type get() const override {
                        return *reinterpret_cast<Type *>(ReferencedArrayListIterator0::get0());
                    }

                    inline void reset() const override {
                        ReferencedArrayListIterator0::reset0();
                    }

                    $RetNotIgnored()
                    inline Size count() const override {
                        return ReferencedArrayListIterator0::count0();
                    }
                };

                static bool elementEqual(void *&element1, void *&element2) {
                    return *reinterpret_cast<Type *>(element1) == *reinterpret_cast<Type *>(element2);
                }

            public:
                inline explicit ReferencedArrayList() : ReferencedArrayList0(UINT8_MAX, {elementEqual}) {}

                inline explicit ReferencedArrayList(Size maxCount) : ReferencedArrayList0(maxCount, {elementEqual}) {}

                inline ReferencedArrayList(const ReferencedArrayList<Type> &originalCopy) :
                    ReferencedArrayList0(originalCopy) {}

                $RetNotIgnored()
                inline Size getLength() const override {
                    return ReferencedArrayList0::getLength0();
                }

                $RetNotIgnored()
                inline bool isEmpty() const override {
                    return ReferencedArrayList0::isEmpty0();
                }

                $RetNotIgnored()
                inline Type &get(Size index) const override {
                    return *reinterpret_cast<Type *>(ReferencedArrayList0::get0(index));
                }

                $RetNotIgnored()
                inline Type &operator[](Size index) const override {
                    return *reinterpret_cast<Type *>(ReferencedArrayList0::get0(index));
                }

                $RetNotIgnored()
                inline Iterator<Type> *iterator() const override {
                    return static_cast<ReferencedArrayListIterator *>(
                        ReferencedArrayList0::iterator = new ReferencedArrayListIterator(this)
                    );
                }

                $RetNotIgnored()
                inline bool contain(const Type &element) const override {
                    return ReferencedArrayList0::contain0(&element);
                }

                $RetRequiresRelease()
                inline ReferencedArrayList<Type> *copy() const override {
                    return new ReferencedArrayList<Type>(*this);
                }

                inline void add(const Type &element) override {
                    ReferencedArrayList0::add0(&element);
                }

                inline Type remove() override {
                    Type value = this->get(this->getLength() - 1);
                    ReferencedArrayList0::remove0();
                    return value;
                }
            };
        } // namespace Reference
    } // namespace Collection
} // namespace EnhancedContainer

#endif // CXX_LANGUAGE

#endif // !ENHANCED_CONTAINER_COLLECTION_REFERENCE_REFERENCED0ARRAY0LIST_H

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

#pragma once

#include "Enhanced/core/defines.h"
#include "Enhanced/core/types.h"
#include "Enhanced/core/annotations.h"

#include "Enhanced/basic/export.h"

#include "Enhanced/basic/core/Iterable.h"
#include "Enhanced/basic/core/Iterator.h"

#include "Enhanced/basic/util/Generic.h"

#include "List.h"
#include "Deque.h"

#ifdef CXX_LANGUAGE // C++ language

namespace EnhancedGenericImpl::basic::collection {
    class ENHANCED_BASIC_API LinkedListImpl {
    private:
        struct Node {
            void* value;

            Node* next;

            Node* back;
        };

        Node* first;

        Node* last;

        mutable Node* indexer;

        Size length;

        static Node*& nextNode(Node*& node);

        static Node*& backNode(Node*& node);

    protected:
        struct GenericOperator {
            void* (*allocate)(GenericReference);

            void (*destroy)(void*);

            bool (*equals)(GenericReference, GenericReference);
        };

        class ENHANCED_BASIC_API LinkedListIteratorImpl {
            friend class LinkedListImpl;

        private:
            const LinkedListImpl* linkedList;

            mutable bool isFirst;

        protected:
            explicit LinkedListIteratorImpl(const LinkedListImpl* linkedList);

            virtual ~LinkedListIteratorImpl() noexcept;

            RetNotIgnored()
            bool hasNext0() const;

            void next0() const;

            RetNotIgnored()
            bool each0() const;

            RetNotIgnored()
            GenericReference get0() const;

            void reset0() const;

            RetNotIgnored()
            Size count0() const;
        };

        GenericOperator genericOperator;

        mutable LinkedListIteratorImpl* iterator;

        explicit LinkedListImpl(GenericOperator genericOperator);

        LinkedListImpl(const LinkedListImpl& other);

        virtual ~LinkedListImpl() noexcept;

        RetNotIgnored()
        Size getLength0() const;

        RetNotIgnored()
        bool isEmpty0() const;

        RetNotIgnored()
        GenericReference getLast0() const;

        RetNotIgnored()
        GenericReference getFirst0() const;

        RetNotIgnored()
        GenericReference get0(Size index) const;

        RetNotIgnored()
        bool contain0(GenericReference value) const;

        void addLast0(GenericReference element);

        void removeLast0();

        void addFirst0(GenericReference element);

        void removeFirst0();
    };
}

namespace Enhanced::basic::collection {
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
    class LinkedList final : public Collection<Type>, public List<Type>, public Deque<Type>,
                             public EnhancedGenericImpl::basic::collection::LinkedListImpl {
#pragma warning(pop)
#else // Non Microsoft Visual C++ Compiler
    template <typename Type>
    class LinkedList : public List<Type>, public Deque<Type>,
                       private EnhancedGenericImpl::basic::collection::LinkedListImpl {
#endif // COMPILER_MSVC
    private:
        using LinkedListImpl = EnhancedGenericImpl::basic::collection::LinkedListImpl;

        class LinkedListIterator : public core::Iterator<Type>, private LinkedListImpl::LinkedListIteratorImpl {
            friend struct core::Iterable<Type>;

        public:
            explicit inline LinkedListIterator(const LinkedList<Type>* linkedList) : LinkedListIteratorImpl(linkedList) {}

            RetNotIgnored()
            inline bool hasNext() const override {
                return hasNext0();
            }

            inline const core::Iterator<Type>* next() const override {
                next0();
                return this;
            }

            RetNotIgnored()
            inline bool each() const override {
                return each0();
            }

            RetNotIgnored()
            inline Type& get() const override {
                return (Type&) get0();
            }

            inline void reset() const override {
                reset0();
            }

            RetNotIgnored()
            inline Size count() const override {
                return count0();
            }
        };

        RetRequiresRelease()
        static void* allocate(GenericReference element) {
            return new Type((Type&) element);
        }

        static void destroy(void* element) {
            delete (Type*) element;
        }

        RetNotIgnored()
        static bool equals(GenericReference element, GenericReference value) {
            return ((Type&) element) == ((Type&) value);
        }

    public:
        inline LinkedList() : LinkedListImpl({allocate, destroy, equals}) {}

        inline LinkedList(const LinkedList<Type>& other) : LinkedListImpl(other) {}

        RetNotIgnored()
        inline Size getLength() const override {
            return getLength0();
        }

        RetNotIgnored()
        inline bool isEmpty() const override {
            return isEmpty0();
        }

        RetNotIgnored()
        inline bool contain(const Type& value) const override {
            return contain0((GenericReference) value);
        }

        RetRequiresRelease()
        inline LinkedList<Type>* copy() const override {
            return new LinkedList<Type>(*this);
        }

        RetNotIgnored()
        inline core::Iterator<Type>* iterator() const override {
            return List<Type>::template getIterator<LinkedListIterator>(LinkedListImpl::iterator, this);
        }

        RetNotIgnored()
        inline typename core::Iterable<Type>::ForeachIterator begin() const override {
            return List<Type>::begin();
        }

        RetNotIgnored()
        inline void* end() const override {
            return List<Type>::end();
        }

        RetNotIgnored()
        inline Type& getLast() const override {
            return (Type&) getLast0();
        }

        RetNotIgnored()
        inline Type& getFirst() const override {
            return (Type&) getFirst0();
        }

        RetNotIgnored()
        inline Type& get(Size index) const override {
            return (Type&) get0(index);
        }

        RetNotIgnored()
        inline Type& operator[](Size index) const override {
            return (Type&) get0(index);
        }

        inline void addLast(const Type& element) override {
            addLast0((GenericReference) element);
        }

        inline Type removeLast() override{
            Type value = getLast();
            removeLast0();
            return value;
        }

        inline void addFirst(const Type& element) override {
            addFirst0((GenericReference) element);
        }

        inline Type removeFirst() override {
            Type value = getFirst();
            removeFirst0();
            return value;
        }

        inline void add(const Type& element) override {
            addLast(element);
        }

        inline Type remove() override {
            return removeLast();
        }

        inline void push(const Type& element) override {
            addFirst(element);
        }

        inline Type popup() override {
            return removeFirst();
        }
    };
}

#endif // CXX_LANGUAGE
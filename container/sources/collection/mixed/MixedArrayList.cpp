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

#include "EnhancedContainer/collection/mixed/MixedArrayList.h"

#include "EnhancedCore/defines.h"
#include "EnhancedCore/annotations.h"
#include "EnhancedCore/types.h"
#include "EnhancedCore/array.h"

using EnhancedContainer::Collection::Mixed::MixedArrayList0;

MixedArrayList0::MixedArrayListIterator0::MixedArrayListIterator0(const MixedArrayList0 *mixedArrayList) :
    mixedArrayList(mixedArrayList), indexer(mixedArrayList->elements), isFirst(true),
    end((const Node *) mixedArrayList->elements + mixedArrayList->getLength0()) {}

#ifdef CXX_11_OR_MORE

MixedArrayList0::MixedArrayListIterator0::~MixedArrayListIterator0() noexcept = default;

#else

MixedArrayList0::MixedArrayListIterator0::~MixedArrayListIterator0() noexcept {}

#endif // CXX_11_OR_MORE

$RetNotIgnored()
bool MixedArrayList0::MixedArrayListIterator0::hasNext0() const {
    return this->indexer != this->end;
}

void MixedArrayList0::MixedArrayListIterator0::next0() const {
    ++ this->indexer;
}

$RetNotIgnored()
bool MixedArrayList0::MixedArrayListIterator0::each0() const {
    if (this->isFirst) {
        this->isFirst = false;
        return !this->mixedArrayList->isEmpty0();
    }

    this->next0();
    return this->hasNext0();
}

$RetNotIgnored()
void *MixedArrayList0::MixedArrayListIterator0::get0() const {
    return (*this->indexer).value;
}

void MixedArrayList0::MixedArrayListIterator0::reset0() const {
    this->isFirst = true;
    this->indexer = this->mixedArrayList->elements;
}

$RetNotIgnored()
Size MixedArrayList0::MixedArrayListIterator0::count0() const {
    return this->mixedArrayList->getLength0();
}

MixedArrayList0::MixedArrayList0(const Size maxCount, const ElementOperator elementOperator) :
    maxCount(maxCount), length(0), elements(new Node[maxCount]),
    elementOperator(elementOperator), iterator(null) {}

MixedArrayList0::~MixedArrayList0() noexcept {
    while (this->length > 0) {
        this->remove0();
    }
    delete[] this->elements;
    delete this->iterator;
}

Size MixedArrayList0::getLength0() const {
    return this->length;
}

bool MixedArrayList0::isEmpty0() const {
    return this->length == 0;
}

void *MixedArrayList0::get0(const Size index) const {
    return this->elements[index].value;
}

bool MixedArrayList0::contain0(const void *const element) const {
    for (Size index = 0; index < this->length; ++ index) {
        if (this->elementOperator.elementEqual(this->elements[index].value, const_cast<void *&>(element))) {
            return true;
        }
    }

    return false;
}

void MixedArrayList0::add0(const void *const element) {
    if (this->length == this->maxCount) {
        this->expand0(this->maxCount >> 1);
    }

    this->elements[this->length] =
        {this->elementOperator.elementNew(const_cast<void *&>(element)), true};
    ++ this->length;
}

void MixedArrayList0::addReferenced0(const void *const element) {
    if (this->length == this->maxCount) {
        this->expand0(this->maxCount >> 1);
    }

    this->elements[this->length] = {const_cast<void *>(element), false};
    ++ this->length;
}

void MixedArrayList0::remove0() {
    if (this->elements[-- this->length].requiresRelease) {
        this->elementOperator.elementDelete(this->elements[this->length].value);
    }
}

void MixedArrayList0::expand0(const Size size) {
    Size count = this->maxCount + size;
    Node *array = new Node[count];

    arrayCopy(array, this->elements, count, sizeof(Node));
    delete[] this->elements;

    this->elements = array;
}

void MixedArrayList0::shrink0(const Size size) {
    Size count = this->maxCount - size;
    if (count < this->length) {
        return;
    }

    Node *array = new Node[count];

    arrayCopy(array, this->elements, count, sizeof(Node));
    delete[] this->elements;

    this->elements = array;
}
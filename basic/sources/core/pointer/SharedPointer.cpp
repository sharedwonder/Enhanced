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

#include "EnhancedBasic/core/pointer/SharedPointer.h"

#include "EnhancedCore/defines.h"
#include "EnhancedCore/types.h"
#include "EnhancedCore/annotations.h"

using BasicGenericImpl::core::pointer::SharedPointerImpl;

SharedPointerImpl::SharedPointerImpl(void *ptr, SharedPointerImpl::GenericOperator genericOperator) :
    pointer(ptr), referenceCount(new Size(1)), genericOperator(genericOperator) {}

SharedPointerImpl::SharedPointerImpl(const SharedPointerImpl &other) :
    pointer(other.pointer), referenceCount(other.referenceCount), genericOperator(other.genericOperator) {
    ++ (*other.referenceCount);
}

SharedPointerImpl::~SharedPointerImpl() noexcept {
    this->release0();
}

void SharedPointerImpl::release0() noexcept {
    if ((-- (*this->referenceCount)) == 0) {
        this->genericOperator.destroy(this->pointer);
        this->pointer = null;
        delete this->referenceCount;
    }
}

void SharedPointerImpl::assign0(void *value) noexcept {
    this->release0();
    this->referenceCount = new Size(1);
    this->pointer = value;
}

void SharedPointerImpl::assign0(const SharedPointerImpl &other) noexcept {
    this->release0();
    this->pointer = other.pointer;
    this->referenceCount = other.referenceCount;
    ++ (*this->referenceCount);
}

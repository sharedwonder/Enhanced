/*
 * Copyright (C) 2022 Liu Baihao. All rights reserved.
 *
 * This software is licensed under Enhanced License.
 * You may not use this file except in compliance with the License.
 * You should see a copy of Enhanced License in this software, if not, visit
 * <https://sharedwonder.github.io/enhanced-website/ENHANCED-LICENSE.txt>
 *
 * The Software is always provided "AS IS",
 * WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY.
 */

#pragma once

#include "enhanced/core/defines.h"
#include "enhanced/core/types.h"

#ifdef CXX_LANGUAGE

typedef void* Generic;
typedef Generic& GenericReference;

#define generic_cast(pointer) *reinterpret_cast<Generic*>(pointer)

#endif // CXX_LANGUAGE

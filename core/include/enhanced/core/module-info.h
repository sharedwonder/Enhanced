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

#include "module.h"

MODULE_INFO_START // Start defining module information.

/*!
 * This module is the core module of Enhanced.
 * It includes based function.
 */
MODULE(core)

MODULE_VERSION(core, 0, 1, 0, "dev", 1, 0.1)
MODULE_AUTHOR(core, "Liu Baihao")
MODULE_ABOUT(core, "The core module of Enhanced.")

MODULE_RELATIONS(
    core,
    EXPORTS_PACKAGE(enhanced::core)
)

MODULE_INFO_END // End defining module information.

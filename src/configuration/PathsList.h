﻿// Copyright (c) Wiesław Šoltés. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#pragma once

#include "utilities\ListT.h"
#include "Path.h"

namespace config
{
    class CPathsList : public util::CListT<CPath>
    {
    };
}

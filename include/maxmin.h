// license
// ---------------------------------------------------------------------------------------------- //
// Copyright (c) 2022, Casey Walker
// All rights reserved.
// 
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.
//
//
// maxmin.h
// ---------------------------------------------------------------------------------------------- //
// small header providing macros for max, min, and clamp

#ifndef CUTI_MAXMIN_H
#define CUTI_MAXMIN_H

#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x < y ? x : y)
#define CLAMP(lo, mid, hi) MAX(lo, MIN(hi, mid))

#endif // CUTI_MAXMIN_H
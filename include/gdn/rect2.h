/**************************************************************************/
/*  rect2.h                                                               */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             PANDEMONIUM ENGINE                               */
/*                        https://pandemoniumengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef GDNATIVE_RECT2_H
#define GDNATIVE_RECT2_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#ifndef PANDEMONIUM_CORE_API_PANDEMONIUM_RECT2_TYPE_DEFINED
#define PANDEMONIUM_CORE_API_PANDEMONIUM_RECT2_TYPE_DEFINED
typedef struct pandemonium_rect2 {
	uint8_t _dont_touch_that[16];
} pandemonium_rect2;
#endif

// reduce extern "C" nesting for VS2013
#ifdef __cplusplus
}
#endif

#include <gdn/gdnative.h>
#include <gdn/vector2.h>

#ifdef __cplusplus
extern "C" {
#endif

void GDAPI pandemonium_rect2_new_with_position_and_size(pandemonium_rect2 *r_dest, const pandemonium_vector2 *p_pos, const pandemonium_vector2 *p_size);
void GDAPI pandemonium_rect2_new(pandemonium_rect2 *r_dest, const pandemonium_real p_x, const pandemonium_real p_y, const pandemonium_real p_width, const pandemonium_real p_height);

pandemonium_string GDAPI pandemonium_rect2_as_string(const pandemonium_rect2 *p_self);

pandemonium_real GDAPI pandemonium_rect2_get_area(const pandemonium_rect2 *p_self);

pandemonium_bool GDAPI pandemonium_rect2_intersects(const pandemonium_rect2 *p_self, const pandemonium_rect2 *p_b);

pandemonium_bool GDAPI pandemonium_rect2_encloses(const pandemonium_rect2 *p_self, const pandemonium_rect2 *p_b);

pandemonium_bool GDAPI pandemonium_rect2_has_no_area(const pandemonium_rect2 *p_self);

pandemonium_rect2 GDAPI pandemonium_rect2_clip(const pandemonium_rect2 *p_self, const pandemonium_rect2 *p_b);

pandemonium_rect2 GDAPI pandemonium_rect2_merge(const pandemonium_rect2 *p_self, const pandemonium_rect2 *p_b);

pandemonium_bool GDAPI pandemonium_rect2_has_point(const pandemonium_rect2 *p_self, const pandemonium_vector2 *p_point);

pandemonium_rect2 GDAPI pandemonium_rect2_grow(const pandemonium_rect2 *p_self, const pandemonium_real p_by);

pandemonium_rect2 GDAPI pandemonium_rect2_grow_individual(const pandemonium_rect2 *p_self, const pandemonium_real p_left, const pandemonium_real p_top, const pandemonium_real p_right, const pandemonium_real p_bottom);

pandemonium_rect2 GDAPI pandemonium_rect2_grow_margin(const pandemonium_rect2 *p_self, const pandemonium_int p_margin, const pandemonium_real p_by);

pandemonium_rect2 GDAPI pandemonium_rect2_abs(const pandemonium_rect2 *p_self);

pandemonium_rect2 GDAPI pandemonium_rect2_expand(const pandemonium_rect2 *p_self, const pandemonium_vector2 *p_to);

pandemonium_bool GDAPI pandemonium_rect2_operator_equal(const pandemonium_rect2 *p_self, const pandemonium_rect2 *p_b);

pandemonium_vector2 GDAPI pandemonium_rect2_get_position(const pandemonium_rect2 *p_self);

pandemonium_vector2 GDAPI pandemonium_rect2_get_size(const pandemonium_rect2 *p_self);

void GDAPI pandemonium_rect2_set_position(pandemonium_rect2 *p_self, const pandemonium_vector2 *p_pos);

void GDAPI pandemonium_rect2_set_size(pandemonium_rect2 *p_self, const pandemonium_vector2 *p_size);

#ifdef __cplusplus
}
#endif

#endif // GDNATIVE_RECT2_H

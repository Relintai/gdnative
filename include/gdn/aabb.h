/**************************************************************************/
/*  aabb.h                                                                */
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

#ifndef GDNATIVE_AABB_H
#define GDNATIVE_AABB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define PANDEMONIUM_AABB_SIZE 24

#ifndef PANDEMONIUM_CORE_API_PANDEMONIUM_AABB_TYPE_DEFINED
#define PANDEMONIUM_CORE_API_PANDEMONIUM_AABB_TYPE_DEFINED
typedef struct {
	uint8_t _dont_touch_that[PANDEMONIUM_AABB_SIZE];
} pandemonium_aabb;
#endif

// reduce extern "C" nesting for VS2013
#ifdef __cplusplus
}
#endif

#include <gdn/gdnative.h>
#include <gdn/plane.h>
#include <gdn/vector3.h>

#ifdef __cplusplus
extern "C" {
#endif

void GDAPI pandemonium_aabb_new(pandemonium_aabb *r_dest, const pandemonium_vector3 *p_pos, const pandemonium_vector3 *p_size);

pandemonium_vector3 GDAPI pandemonium_aabb_get_position(const pandemonium_aabb *p_self);
void GDAPI pandemonium_aabb_set_position(const pandemonium_aabb *p_self, const pandemonium_vector3 *p_v);

pandemonium_vector3 GDAPI pandemonium_aabb_get_size(const pandemonium_aabb *p_self);
void GDAPI pandemonium_aabb_set_size(const pandemonium_aabb *p_self, const pandemonium_vector3 *p_v);

pandemonium_string GDAPI pandemonium_aabb_as_string(const pandemonium_aabb *p_self);

pandemonium_real GDAPI pandemonium_aabb_get_area(const pandemonium_aabb *p_self);

pandemonium_bool GDAPI pandemonium_aabb_has_no_area(const pandemonium_aabb *p_self);

pandemonium_bool GDAPI pandemonium_aabb_has_no_surface(const pandemonium_aabb *p_self);

pandemonium_bool GDAPI pandemonium_aabb_intersects(const pandemonium_aabb *p_self, const pandemonium_aabb *p_with);

pandemonium_bool GDAPI pandemonium_aabb_encloses(const pandemonium_aabb *p_self, const pandemonium_aabb *p_with);

pandemonium_aabb GDAPI pandemonium_aabb_merge(const pandemonium_aabb *p_self, const pandemonium_aabb *p_with);

pandemonium_aabb GDAPI pandemonium_aabb_intersection(const pandemonium_aabb *p_self, const pandemonium_aabb *p_with);

pandemonium_bool GDAPI pandemonium_aabb_intersects_plane(const pandemonium_aabb *p_self, const pandemonium_plane *p_plane);

pandemonium_bool GDAPI pandemonium_aabb_intersects_segment(const pandemonium_aabb *p_self, const pandemonium_vector3 *p_from, const pandemonium_vector3 *p_to);

pandemonium_bool GDAPI pandemonium_aabb_has_point(const pandemonium_aabb *p_self, const pandemonium_vector3 *p_point);

pandemonium_vector3 GDAPI pandemonium_aabb_get_support(const pandemonium_aabb *p_self, const pandemonium_vector3 *p_dir);

pandemonium_vector3 GDAPI pandemonium_aabb_get_longest_axis(const pandemonium_aabb *p_self);

pandemonium_int GDAPI pandemonium_aabb_get_longest_axis_index(const pandemonium_aabb *p_self);

pandemonium_real GDAPI pandemonium_aabb_get_longest_axis_size(const pandemonium_aabb *p_self);

pandemonium_vector3 GDAPI pandemonium_aabb_get_shortest_axis(const pandemonium_aabb *p_self);

pandemonium_int GDAPI pandemonium_aabb_get_shortest_axis_index(const pandemonium_aabb *p_self);

pandemonium_real GDAPI pandemonium_aabb_get_shortest_axis_size(const pandemonium_aabb *p_self);

pandemonium_aabb GDAPI pandemonium_aabb_expand(const pandemonium_aabb *p_self, const pandemonium_vector3 *p_to_point);

pandemonium_aabb GDAPI pandemonium_aabb_grow(const pandemonium_aabb *p_self, const pandemonium_real p_by);

pandemonium_vector3 GDAPI pandemonium_aabb_get_endpoint(const pandemonium_aabb *p_self, const pandemonium_int p_idx);

pandemonium_bool GDAPI pandemonium_aabb_operator_equal(const pandemonium_aabb *p_self, const pandemonium_aabb *p_b);

#ifdef __cplusplus
}
#endif

#endif // GDNATIVE_AABB_H

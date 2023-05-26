/**************************************************************************/
/*  color.cpp                                                             */
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

#include "gdn/color.h"

#include "core/math/color.h"
#include "core/variant/variant.h"

#ifdef __cplusplus
extern "C" {
#endif

static_assert(sizeof(pandemonium_color) == sizeof(Color), "Color size mismatch");

void GDAPI pandemonium_color_new_rgba(pandemonium_color *r_dest, const pandemonium_real p_r, const pandemonium_real p_g, const pandemonium_real p_b, const pandemonium_real p_a) {
	Color *dest = (Color *)r_dest;
	*dest = Color(p_r, p_g, p_b, p_a);
}

void GDAPI pandemonium_color_new_rgb(pandemonium_color *r_dest, const pandemonium_real p_r, const pandemonium_real p_g, const pandemonium_real p_b) {
	Color *dest = (Color *)r_dest;
	*dest = Color(p_r, p_g, p_b);
}

pandemonium_real pandemonium_color_get_r(const pandemonium_color *p_self) {
	const Color *self = (const Color *)p_self;
	return self->r;
}

void pandemonium_color_set_r(pandemonium_color *p_self, const pandemonium_real val) {
	Color *self = (Color *)p_self;
	self->r = val;
}

pandemonium_real pandemonium_color_get_g(const pandemonium_color *p_self) {
	const Color *self = (const Color *)p_self;
	return self->g;
}

void pandemonium_color_set_g(pandemonium_color *p_self, const pandemonium_real val) {
	Color *self = (Color *)p_self;
	self->g = val;
}

pandemonium_real pandemonium_color_get_b(const pandemonium_color *p_self) {
	const Color *self = (const Color *)p_self;
	return self->b;
}

void pandemonium_color_set_b(pandemonium_color *p_self, const pandemonium_real val) {
	Color *self = (Color *)p_self;
	self->b = val;
}

pandemonium_real pandemonium_color_get_a(const pandemonium_color *p_self) {
	const Color *self = (const Color *)p_self;
	return self->a;
}

void pandemonium_color_set_a(pandemonium_color *p_self, const pandemonium_real val) {
	Color *self = (Color *)p_self;
	self->a = val;
}

pandemonium_real pandemonium_color_get_h(const pandemonium_color *p_self) {
	const Color *self = (const Color *)p_self;
	return self->get_h();
}

pandemonium_real pandemonium_color_get_s(const pandemonium_color *p_self) {
	const Color *self = (const Color *)p_self;
	return self->get_s();
}

pandemonium_real pandemonium_color_get_v(const pandemonium_color *p_self) {
	const Color *self = (const Color *)p_self;
	return self->get_v();
}

pandemonium_string GDAPI pandemonium_color_as_string(const pandemonium_color *p_self) {
	pandemonium_string ret;
	const Color *self = (const Color *)p_self;
	memnew_placement(&ret, String(*self));
	return ret;
}

pandemonium_int GDAPI pandemonium_color_to_rgba32(const pandemonium_color *p_self) {
	const Color *self = (const Color *)p_self;
	return self->to_rgba32();
}

pandemonium_int GDAPI pandemonium_color_to_abgr32(const pandemonium_color *p_self) {
	const Color *self = (const Color *)p_self;
	return self->to_abgr32();
}

pandemonium_int GDAPI pandemonium_color_to_abgr64(const pandemonium_color *p_self) {
	const Color *self = (const Color *)p_self;
	return self->to_abgr64();
}

pandemonium_int GDAPI pandemonium_color_to_argb64(const pandemonium_color *p_self) {
	const Color *self = (const Color *)p_self;
	return self->to_argb64();
}

pandemonium_int GDAPI pandemonium_color_to_rgba64(const pandemonium_color *p_self) {
	const Color *self = (const Color *)p_self;
	return self->to_rgba64();
}

pandemonium_int GDAPI pandemonium_color_to_argb32(const pandemonium_color *p_self) {
	const Color *self = (const Color *)p_self;
	return self->to_argb32();
}

pandemonium_real GDAPI pandemonium_color_gray(const pandemonium_color *p_self) {
	const Color *self = (const Color *)p_self;
	return self->gray();
}

pandemonium_color GDAPI pandemonium_color_inverted(const pandemonium_color *p_self) {
	pandemonium_color dest;
	const Color *self = (const Color *)p_self;
	*((Color *)&dest) = self->inverted();
	return dest;
}

pandemonium_color GDAPI pandemonium_color_contrasted(const pandemonium_color *p_self) {
	pandemonium_color dest;
	const Color *self = (const Color *)p_self;
	*((Color *)&dest) = self->contrasted();
	return dest;
}

pandemonium_color GDAPI pandemonium_color_linear_interpolate(const pandemonium_color *p_self, const pandemonium_color *p_b, const pandemonium_real p_t) {
	pandemonium_color dest;
	const Color *self = (const Color *)p_self;
	const Color *b = (const Color *)p_b;
	*((Color *)&dest) = self->linear_interpolate(*b, p_t);
	return dest;
}

pandemonium_color GDAPI pandemonium_color_blend(const pandemonium_color *p_self, const pandemonium_color *p_over) {
	pandemonium_color dest;
	const Color *self = (const Color *)p_self;
	const Color *over = (const Color *)p_over;
	*((Color *)&dest) = self->blend(*over);
	return dest;
}

pandemonium_color GDAPI pandemonium_color_darkened(const pandemonium_color *p_self, const pandemonium_real p_amount) {
	pandemonium_color dest;
	const Color *self = (const Color *)p_self;
	*((Color *)&dest) = self->darkened(p_amount);
	return dest;
}

pandemonium_color GDAPI pandemonium_color_from_hsv(const pandemonium_color *p_self, const pandemonium_real p_h, const pandemonium_real p_s, const pandemonium_real p_v, const pandemonium_real p_a) {
	pandemonium_color dest;
	const Color *self = (const Color *)p_self;
	*((Color *)&dest) = self->from_hsv(p_h, p_s, p_v, p_a);
	return dest;
}

pandemonium_color GDAPI pandemonium_color_lightened(const pandemonium_color *p_self, const pandemonium_real p_amount) {
	pandemonium_color dest;
	const Color *self = (const Color *)p_self;
	*((Color *)&dest) = self->lightened(p_amount);
	return dest;
}

pandemonium_string GDAPI pandemonium_color_to_html(const pandemonium_color *p_self, const pandemonium_bool p_with_alpha) {
	pandemonium_string dest;
	const Color *self = (const Color *)p_self;

	memnew_placement(&dest, String(self->to_html(p_with_alpha)));
	return dest;
}

pandemonium_bool GDAPI pandemonium_color_operator_equal(const pandemonium_color *p_self, const pandemonium_color *p_b) {
	const Color *self = (const Color *)p_self;
	const Color *b = (const Color *)p_b;
	return *self == *b;
}

pandemonium_bool GDAPI pandemonium_color_operator_less(const pandemonium_color *p_self, const pandemonium_color *p_b) {
	const Color *self = (const Color *)p_self;
	const Color *b = (const Color *)p_b;
	return *self < *b;
}

#ifdef __cplusplus
}
#endif

/**************************************************************************/
/*  quaternion.cpp                                                              */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
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

#include "gdnative/quaternion.h"

#include "core/math/quaternion.h"
#include "core/variant/variant.h"

#ifdef __cplusplus
extern "C" {
#endif

static_assert(sizeof(godot_quaternion) == sizeof(Quaternion), "Quaternion size mismatch");

void GDAPI godot_quaternion_new(godot_quaternion *r_dest, const godot_real p_x, const godot_real p_y, const godot_real p_z, const godot_real p_w) {
	Quaternion *dest = (Quaternion *)r_dest;
	*dest = Quaternion(p_x, p_y, p_z, p_w);
}

void GDAPI godot_quaternion_new_with_axis_angle(godot_quaternion *r_dest, const godot_vector3 *p_axis, const godot_real p_angle) {
	const Vector3 *axis = (const Vector3 *)p_axis;
	Quaternion *dest = (Quaternion *)r_dest;
	*dest = Quaternion(*axis, p_angle);
}

void GDAPI godot_quaternion_new_with_basis(godot_quaternion *r_dest, const godot_basis *p_basis) {
	const Basis *basis = (const Basis *)p_basis;
	Quaternion *dest = (Quaternion *)r_dest;
	*dest = Quaternion(*basis);
}

void GDAPI godot_quaternion_new_with_euler(godot_quaternion *r_dest, const godot_vector3 *p_euler) {
	const Vector3 *euler = (const Vector3 *)p_euler;
	Quaternion *dest = (Quaternion *)r_dest;
	*dest = Quaternion(*euler);
}

godot_real GDAPI godot_quaternion_get_x(const godot_quaternion *p_self) {
	const Quaternion *self = (const Quaternion *)p_self;
	return self->x;
}

void GDAPI godot_quaternion_set_x(godot_quaternion *p_self, const godot_real val) {
	Quaternion *self = (Quaternion *)p_self;
	self->x = val;
}

godot_real GDAPI godot_quaternion_get_y(const godot_quaternion *p_self) {
	const Quaternion *self = (const Quaternion *)p_self;
	return self->y;
}

void GDAPI godot_quaternion_set_y(godot_quaternion *p_self, const godot_real val) {
	Quaternion *self = (Quaternion *)p_self;
	self->y = val;
}

godot_real GDAPI godot_quaternion_get_z(const godot_quaternion *p_self) {
	const Quaternion *self = (const Quaternion *)p_self;
	return self->z;
}

void GDAPI godot_quaternion_set_z(godot_quaternion *p_self, const godot_real val) {
	Quaternion *self = (Quaternion *)p_self;
	self->z = val;
}

godot_real GDAPI godot_quaternion_get_w(const godot_quaternion *p_self) {
	const Quaternion *self = (const Quaternion *)p_self;
	return self->w;
}

void GDAPI godot_quaternion_set_w(godot_quaternion *p_self, const godot_real val) {
	Quaternion *self = (Quaternion *)p_self;
	self->w = val;
}

godot_string GDAPI godot_quaternion_as_string(const godot_quaternion *p_self) {
	godot_string ret;
	const Quaternion *self = (const Quaternion *)p_self;
	memnew_placement(&ret, String(*self));
	return ret;
}

godot_real GDAPI godot_quaternion_length(const godot_quaternion *p_self) {
	const Quaternion *self = (const Quaternion *)p_self;
	return self->length();
}

godot_real GDAPI godot_quaternion_length_squared(const godot_quaternion *p_self) {
	const Quaternion *self = (const Quaternion *)p_self;
	return self->length_squared();
}

godot_quaternion GDAPI godot_quaternion_normalized(const godot_quaternion *p_self) {
	godot_quaternion dest;
	const Quaternion *self = (const Quaternion *)p_self;
	*((Quaternion *)&dest) = self->normalized();
	return dest;
}

godot_bool GDAPI godot_quaternion_is_normalized(const godot_quaternion *p_self) {
	const Quaternion *self = (const Quaternion *)p_self;
	return self->is_normalized();
}

godot_quaternion GDAPI godot_quaternion_inverse(const godot_quaternion *p_self) {
	godot_quaternion dest;
	const Quaternion *self = (const Quaternion *)p_self;
	*((Quaternion *)&dest) = self->inverse();
	return dest;
}

godot_real GDAPI godot_quaternion_dot(const godot_quaternion *p_self, const godot_quaternion *p_b) {
	const Quaternion *self = (const Quaternion *)p_self;
	const Quaternion *b = (const Quaternion *)p_b;
	return self->dot(*b);
}

godot_vector3 GDAPI godot_quaternion_xform(const godot_quaternion *p_self, const godot_vector3 *p_v) {
	godot_vector3 dest;
	const Quaternion *self = (const Quaternion *)p_self;
	const Vector3 *v = (const Vector3 *)p_v;
	*((Vector3 *)&dest) = self->xform(*v);
	return dest;
}

godot_quaternion GDAPI godot_quaternion_slerp(const godot_quaternion *p_self, const godot_quaternion *p_b, const godot_real p_t) {
	godot_quaternion dest;
	const Quaternion *self = (const Quaternion *)p_self;
	const Quaternion *b = (const Quaternion *)p_b;
	*((Quaternion *)&dest) = self->slerp(*b, p_t);
	return dest;
}

godot_quaternion GDAPI godot_quaternion_slerpni(const godot_quaternion *p_self, const godot_quaternion *p_b, const godot_real p_t) {
	godot_quaternion dest;
	const Quaternion *self = (const Quaternion *)p_self;
	const Quaternion *b = (const Quaternion *)p_b;
	*((Quaternion *)&dest) = self->slerpni(*b, p_t);
	return dest;
}

godot_quaternion GDAPI godot_quaternion_cubic_slerp(const godot_quaternion *p_self, const godot_quaternion *p_b, const godot_quaternion *p_pre_a, const godot_quaternion *p_post_b, const godot_real p_t) {
	godot_quaternion dest;
	const Quaternion *self = (const Quaternion *)p_self;
	const Quaternion *b = (const Quaternion *)p_b;
	const Quaternion *pre_a = (const Quaternion *)p_pre_a;
	const Quaternion *post_b = (const Quaternion *)p_post_b;
	*((Quaternion *)&dest) = self->cubic_slerp(*b, *pre_a, *post_b, p_t);
	return dest;
}

godot_quaternion GDAPI godot_quaternion_operator_multiply(const godot_quaternion *p_self, const godot_real p_b) {
	godot_quaternion raw_dest;
	Quaternion *dest = (Quaternion *)&raw_dest;
	const Quaternion *self = (const Quaternion *)p_self;
	*dest = *self * p_b;
	return raw_dest;
}

godot_quaternion GDAPI godot_quaternion_operator_add(const godot_quaternion *p_self, const godot_quaternion *p_b) {
	godot_quaternion raw_dest;
	Quaternion *dest = (Quaternion *)&raw_dest;
	const Quaternion *self = (const Quaternion *)p_self;
	const Quaternion *b = (const Quaternion *)p_b;
	*dest = *self + *b;
	return raw_dest;
}

godot_quaternion GDAPI godot_quaternion_operator_subtract(const godot_quaternion *p_self, const godot_quaternion *p_b) {
	godot_quaternion raw_dest;
	Quaternion *dest = (Quaternion *)&raw_dest;
	const Quaternion *self = (const Quaternion *)p_self;
	const Quaternion *b = (const Quaternion *)p_b;
	*dest = *self - *b;
	return raw_dest;
}

godot_quaternion GDAPI godot_quaternion_operator_divide(const godot_quaternion *p_self, const godot_real p_b) {
	godot_quaternion raw_dest;
	Quaternion *dest = (Quaternion *)&raw_dest;
	const Quaternion *self = (const Quaternion *)p_self;
	*dest = *self / p_b;
	return raw_dest;
}

godot_bool GDAPI godot_quaternion_operator_equal(const godot_quaternion *p_self, const godot_quaternion *p_b) {
	const Quaternion *self = (const Quaternion *)p_self;
	const Quaternion *b = (const Quaternion *)p_b;
	return *self == *b;
}

godot_quaternion GDAPI godot_quaternion_operator_neg(const godot_quaternion *p_self) {
	godot_quaternion raw_dest;
	Quaternion *dest = (Quaternion *)&raw_dest;
	const Quaternion *self = (const Quaternion *)p_self;
	*dest = -(*self);
	return raw_dest;
}

void GDAPI godot_quaternion_set_axis_angle(godot_quaternion *p_self, const godot_vector3 *p_axis, const godot_real p_angle) {
	Quaternion *self = (Quaternion *)p_self;
	const Vector3 *axis = (const Vector3 *)p_axis;
	self->set_axis_angle(*axis, p_angle);
}

#ifdef __cplusplus
}
#endif

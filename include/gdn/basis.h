/**************************************************************************/
/*  basis.h                                                               */
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

#ifndef GDNATIVE_BASIS_H
#define GDNATIVE_BASIS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define PANDEMONIUM_BASIS_SIZE 36

#ifndef PANDEMONIUM_CORE_API_PANDEMONIUM_BASIS_TYPE_DEFINED
#define PANDEMONIUM_CORE_API_PANDEMONIUM_BASIS_TYPE_DEFINED
typedef struct {
	uint8_t _dont_touch_that[PANDEMONIUM_BASIS_SIZE];
} pandemonium_basis;
#endif

// reduce extern "C" nesting for VS2013
#ifdef __cplusplus
}
#endif

#include <gdn/gdnative.h>
#include <gdn/quaternion.h>
#include <gdn/vector3.h>

#ifdef __cplusplus
extern "C" {
#endif

//void invert();
//void transpose();

pandemonium_basis GDAPI pandemonium_basis_inverse(const pandemonium_basis *p_self);
pandemonium_basis GDAPI pandemonium_basis_transposed(const pandemonium_basis *p_self);

pandemonium_real GDAPI pandemonium_basis_determinant(const pandemonium_basis *p_self);

//void from_z(const Vector3 &p_z);

//void rotate(const Vector3 &p_axis, real_t p_phi);
pandemonium_basis GDAPI pandemonium_basis_rotated(const pandemonium_basis *p_self, const pandemonium_vector3 *p_axis, const pandemonium_real p_phi);

//void rotate_local(const Vector3 &p_axis, real_t p_phi);
//Basis rotated_local(const Vector3 &p_axis, real_t p_phi) const;

//void rotate(const Vector3 &p_euler);
//Basis rotated(const Vector3 &p_euler) const;

//void rotate(const Quaternion &p_quat);
//Basis rotated(const Quaternion &p_quat) const;

//_FORCE_INLINE_ void rotatev(const Vector3 &p_euler) { rotate(p_euler); }
//_FORCE_INLINE_ Basis rotatedv(const Vector3 &p_euler) const { return rotated(p_euler); }
//_FORCE_INLINE_ void rotateq(const Quaternion &p_quat) { rotate(p_quat); }
//_FORCE_INLINE_ Basis rotatedq(const Quaternion &p_quat) const { return rotated(p_quat); }

//Vector3 get_rotation_euler() const;
//void get_rotation_axis_angle(Vector3 &p_axis, real_t &p_angle) const;
//void get_rotation_axis_angle_local(Vector3 &p_axis, real_t &p_angle) const;
//Quaternion get_rotation_quaternion() const;
//Vector3 get_rotation() const { return get_rotation_euler(); };

//void rotate_to_align(Vector3 p_start_direction, Vector3 p_end_direction);

//Vector3 rotref_posscale_decomposition(Basis &rotref) const;

//Vector3 get_euler_xyz() const;
//void set_euler_xyz(const Vector3 &p_euler);

//Vector3 get_euler_xzy() const;
//void set_euler_xzy(const Vector3 &p_euler);

//Vector3 get_euler_yzx() const;
//void set_euler_yzx(const Vector3 &p_euler);

//Vector3 get_euler_yxz() const;
//void set_euler_yxz(const Vector3 &p_euler);

//Vector3 get_euler_zxy() const;
//void set_euler_zxy(const Vector3 &p_euler);

//Vector3 get_euler_zyx() const;
//void set_euler_zyx(const Vector3 &p_euler);

pandemonium_vector3 GDAPI pandemonium_basis_get_euler(const pandemonium_basis *p_self);
//void set_euler(const Vector3 &p_euler) { set_euler_yxz(p_euler); }

pandemonium_quaternion GDAPI pandemonium_basis_get_quaternion(const pandemonium_basis *p_self);
void GDAPI pandemonium_basis_set_quaternion(pandemonium_basis *p_self, const pandemonium_quaternion *p_quaternion);

//void get_axis_angle(Vector3 &r_axis, real_t &r_angle) const;
//void set_axis_angle(const Vector3 &p_axis, real_t p_phi);

//void scale(const Vector3 &p_scale);
pandemonium_basis GDAPI pandemonium_basis_scaled(const pandemonium_basis *p_self, const pandemonium_vector3 *p_scale);

//void scale_local(const Vector3 &p_scale);
//Basis scaled_local(const Vector3 &p_scale) const;

//void scale_orthogonal(const Vector3 &p_scale);
//Basis scaled_orthogonal(const Vector3 &p_scale) const;

//void make_scale_uniform();
//float get_uniform_scale() const;

pandemonium_vector3 GDAPI pandemonium_basis_get_scale(const pandemonium_basis *p_self);
//Vector3 get_scale_abs() const;
//Vector3 get_scale_local() const;

void GDAPI pandemonium_basis_set_axis_angle_scale(pandemonium_basis *p_self, const pandemonium_vector3 *p_axis, pandemonium_real p_phi, const pandemonium_vector3 *p_scale);
void GDAPI pandemonium_basis_set_euler_scale(pandemonium_basis *p_self, const pandemonium_vector3 *p_euler, const pandemonium_vector3 *p_scale);
void GDAPI pandemonium_basis_set_quaternion_scale(pandemonium_basis *p_self, const pandemonium_quaternion *p_quaternion, const pandemonium_vector3 *p_scale);

pandemonium_real GDAPI pandemonium_basis_tdotx(const pandemonium_basis *p_self, const pandemonium_vector3 *p_with);
pandemonium_real GDAPI pandemonium_basis_tdoty(const pandemonium_basis *p_self, const pandemonium_vector3 *p_with);
pandemonium_real GDAPI pandemonium_basis_tdotz(const pandemonium_basis *p_self, const pandemonium_vector3 *p_with);

//bool is_equal_approx(const Basis &p_basis) const;
//bool is_equal_approx_ratio(const Basis &a, const Basis &b, real_t p_epsilon = UNIT_EPSILON) const;

pandemonium_bool GDAPI pandemonium_basis_operator_equal(const pandemonium_basis *p_self, const pandemonium_basis *p_b);

pandemonium_vector3 GDAPI pandemonium_basis_xform(const pandemonium_basis *p_self, const pandemonium_vector3 *p_v);
pandemonium_vector3 GDAPI pandemonium_basis_xform_inv(const pandemonium_basis *p_self, const pandemonium_vector3 *p_v);

//_FORCE_INLINE_ Vector3i xform(const Vector3i &p_vector) const;
//_FORCE_INLINE_ Vector3i xform_inv(const Vector3i &p_vector) const;

//Remove _vector postfix
pandemonium_basis GDAPI pandemonium_basis_operator_multiply_vector(const pandemonium_basis *p_self, const pandemonium_basis *p_b);
pandemonium_basis GDAPI pandemonium_basis_operator_add(const pandemonium_basis *p_self, const pandemonium_basis *p_b);
pandemonium_basis GDAPI pandemonium_basis_operator_subtract(const pandemonium_basis *p_self, const pandemonium_basis *p_b);
pandemonium_basis GDAPI pandemonium_basis_operator_multiply_scalar(const pandemonium_basis *p_self, const pandemonium_real p_b);

pandemonium_int GDAPI pandemonium_basis_get_orthogonal_index(const pandemonium_basis *p_self);
//void set_orthogonal_index(int p_index);

//void set_diagonal(const Vector3 &p_diag);

//bool is_orthogonal() const;
//bool is_diagonal() const;
//bool is_rotation() const;

pandemonium_basis GDAPI pandemonium_basis_slerp(const pandemonium_basis *p_self, const pandemonium_basis *p_b, const pandemonium_real p_t);
//_FORCE_INLINE_ Basis lerp(const Basis &p_to, const real_t &p_weight) const;
//void rotate_sh(real_t *p_values);

pandemonium_string GDAPI pandemonium_basis_as_string(const pandemonium_basis *p_self);

//_FORCE_INLINE_ void set(real_t xx, real_t xy, real_t xz, real_t yx, real_t yy, real_t yz, real_t zx, real_t zy, real_t zz) {
//_FORCE_INLINE_ void set(const Vector3 &p_x, const Vector3 &p_y, const Vector3 &p_z) {

//_FORCE_INLINE_ Vector3 get_column(int i) const {
//_FORCE_INLINE_ void set_column(int p_index, const Vector3 &p_value) {
//_FORCE_INLINE_ void set_columns(const Vector3 &p_x, const Vector3 &p_y, const Vector3 &p_z) {

pandemonium_vector3 GDAPI pandemonium_basis_get_row(const pandemonium_basis *p_self, const pandemonium_int p_row);
void GDAPI pandemonium_basis_set_row(pandemonium_basis *p_self, const pandemonium_int p_row, const pandemonium_vector3 *p_value);

pandemonium_vector3 GDAPI pandemonium_basis_get_axis(const pandemonium_basis *p_self, const pandemonium_int p_axis);
void GDAPI pandemonium_basis_set_axis(pandemonium_basis *p_self, const pandemonium_int p_axis, const pandemonium_vector3 *p_value);

//_FORCE_INLINE_ Vector3 get_main_diagonal() const {

//_FORCE_INLINE_ void set_zero() {

//_FORCE_INLINE_ Basis transpose_xform(const Basis &m) const {

//void orthonormalize();
pandemonium_basis GDAPI pandemonium_basis_orthonormalized(const pandemonium_basis *p_self);

//void orthogonalize();
//Basis orthogonalized() const;

//bool is_symmetric() const;
//Basis diagonalize();

//Basis get_normal_xform_basis() const { return inverse().transposed(); }
//Vector3 xform_normal_fast(const Vector3 &p_vector) const { return xform(p_vector).normalized(); }
//Vector3 xform_normal(const Vector3 &p_vector) const { return get_normal_xform_basis().xform_normal_fast(p_vector); }

//static Basis looking_at(const Vector3 &p_target, const Vector3 &p_up = Vector3(0, 1, 0));
//static Basis from_scale(const Vector3 &p_scale);

// p_elements is a pointer to an array of 3 (!!) vector3
void GDAPI pandemonium_basis_get_elements(const pandemonium_basis *p_self, pandemonium_vector3 *p_elements);

void GDAPI pandemonium_basis_new(pandemonium_basis *r_dest);
void GDAPI pandemonium_basis_new_with_rows(pandemonium_basis *r_dest, const pandemonium_vector3 *p_x_axis, const pandemonium_vector3 *p_y_axis, const pandemonium_vector3 *p_z_axis);
void GDAPI pandemonium_basis_new_with_axis_and_angle(pandemonium_basis *r_dest, const pandemonium_vector3 *p_axis, const pandemonium_real p_phi);
void GDAPI pandemonium_basis_new_with_euler(pandemonium_basis *r_dest, const pandemonium_vector3 *p_euler);
void GDAPI pandemonium_basis_new_with_euler_quaternion(pandemonium_basis *r_dest, const pandemonium_quaternion *p_euler);
//Basis(const Quaternion &p_quat, const Vector3 &p_scale) { set_quaternion_scale(p_quat, p_scale); }
//Basis(const Vector3 &p_euler, const Vector3 &p_scale) { set_euler_scale(p_euler, p_scale); }
//Basis(const Vector3 &p_axis, real_t p_phi, const Vector3 &p_scale) { set_axis_angle_scale(p_axis, p_phi, p_scale); }
//Basis(real_t xx, real_t xy, real_t xz, real_t yx, real_t yy, real_t yz, real_t zx, real_t zy, real_t zz) {

#ifdef __cplusplus
}
#endif

#endif // GDNATIVE_BASIS_H

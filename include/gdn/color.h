/**************************************************************************/
/*  color.h                                                               */
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

#ifndef GDNATIVE_COLOR_H
#define GDNATIVE_COLOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define PANDEMONIUM_COLOR_SIZE 16

#ifndef PANDEMONIUM_CORE_API_PANDEMONIUM_COLOR_TYPE_DEFINED
#define PANDEMONIUM_CORE_API_PANDEMONIUM_COLOR_TYPE_DEFINED
typedef struct {
	uint8_t _dont_touch_that[PANDEMONIUM_COLOR_SIZE];
} pandemonium_color;
#endif

// reduce extern "C" nesting for VS2013
#ifdef __cplusplus
}
#endif

#include <gdn/gdnative.h>
#include <gdn/string.h>

#ifdef __cplusplus
extern "C" {
#endif

pandemonium_real pandemonium_color_get_r(const pandemonium_color *p_self);
void pandemonium_color_set_r(pandemonium_color *p_self, const pandemonium_real r);

pandemonium_real pandemonium_color_get_g(const pandemonium_color *p_self);
void pandemonium_color_set_g(pandemonium_color *p_self, const pandemonium_real g);

pandemonium_real pandemonium_color_get_b(const pandemonium_color *p_self);
void pandemonium_color_set_b(pandemonium_color *p_self, const pandemonium_real b);

pandemonium_real pandemonium_color_get_a(const pandemonium_color *p_self);
void pandemonium_color_set_a(pandemonium_color *p_self, const pandemonium_real a);

pandemonium_bool GDAPI pandemonium_color_operator_equal(const pandemonium_color *p_self, const pandemonium_color *p_b);

pandemonium_int GDAPI pandemonium_color_to_rgba32(const pandemonium_color *p_self);
pandemonium_int GDAPI pandemonium_color_to_argb32(const pandemonium_color *p_self);
pandemonium_int GDAPI pandemonium_color_to_abgr32(const pandemonium_color *p_self);
pandemonium_int GDAPI pandemonium_color_to_rgba64(const pandemonium_color *p_self);
pandemonium_int GDAPI pandemonium_color_to_argb64(const pandemonium_color *p_self);
pandemonium_int GDAPI pandemonium_color_to_abgr64(const pandemonium_color *p_self);

pandemonium_real GDAPI pandemonium_color_gray(const pandemonium_color *p_self);
pandemonium_real pandemonium_color_get_h(const pandemonium_color *p_self);
pandemonium_real pandemonium_color_get_s(const pandemonium_color *p_self);
pandemonium_real pandemonium_color_get_v(const pandemonium_color *p_self);
//void set_hsv(float p_h, float p_s, float p_v, float p_alpha = 1.0);

//_FORCE_INLINE_ float &operator[](int idx) {
//_FORCE_INLINE_ const float &operator[](int idx) const {

//Color operator+(const Color &p_color) const;
//void operator+=(const Color &p_color);

//Color operator-() const;
//Color operator-(const Color &p_color) const;
//void operator-=(const Color &p_color);

//Color operator*(const Color &p_color) const;
//Color operator*(const real_t &rvalue) const;
//void operator*=(const Color &p_color);
//void operator*=(const real_t &rvalue);

//Color operator/(const Color &p_color) const;
//Color operator/(const real_t &rvalue) const;
//void operator/=(const Color &p_color);
//void operator/=(const real_t &rvalue);

//bool is_equal_approx(const Color &p_color) const;

//Color clamp(const Color &p_min = Color(0, 0, 0, 0), const Color &p_max = Color(1, 1, 1, 1)) const;

//void invert();
//void contrast();
pandemonium_color GDAPI pandemonium_color_inverted(const pandemonium_color *p_self);
pandemonium_color GDAPI pandemonium_color_contrasted(const pandemonium_color *p_self);

//_FORCE_INLINE_ float get_luminance() const {

pandemonium_color GDAPI pandemonium_color_linear_interpolate(const pandemonium_color *p_self, const pandemonium_color *p_b, const pandemonium_real p_t);

pandemonium_color GDAPI pandemonium_color_darkened(const pandemonium_color *p_self, const pandemonium_real p_amount);
pandemonium_color GDAPI pandemonium_color_lightened(const pandemonium_color *p_self, const pandemonium_real p_amount);

//_FORCE_INLINE_ uint32_t to_rgbe9995() const {

pandemonium_color GDAPI pandemonium_color_blend(const pandemonium_color *p_self, const pandemonium_color *p_over);

//_FORCE_INLINE_ Color to_linear() const {
//_FORCE_INLINE_ Color to_srgb() const {

//static Color hex(uint32_t p_hex);
//static Color hex64(uint64_t p_hex);
//static Color html(const String &p_color);
//static bool html_is_valid(const String &p_color);
//static Color named(const String &p_name);
pandemonium_string GDAPI pandemonium_color_to_html(const pandemonium_color *p_self, const pandemonium_bool p_with_alpha);
pandemonium_color GDAPI pandemonium_color_from_hsv(const pandemonium_color *p_self, const pandemonium_real p_h, const pandemonium_real p_s, const pandemonium_real p_v, const pandemonium_real p_a);
//static Color from_rgbe9995(uint32_t p_rgbe);

pandemonium_bool GDAPI pandemonium_color_operator_less(const pandemonium_color *p_self, const pandemonium_color *p_b);
pandemonium_string GDAPI pandemonium_color_as_string(const pandemonium_color *p_self);

//static _FORCE_INLINE_ Color color8(int r, int g, int b) {
//static _FORCE_INLINE_ Color color8(int r, int g, int b, int a) {

//_FORCE_INLINE_ void set_r8(int32_t r8) { r = (CLAMP(r8, 0, 255) / 255.0f); }
//_FORCE_INLINE_ int32_t get_r8() const { return int32_t(CLAMP(Math::round(r * 255.0f), 0.0f, 255.0f)); }
//_FORCE_INLINE_ void set_g8(int32_t g8) { g = (CLAMP(g8, 0, 255) / 255.0f); }
//_FORCE_INLINE_ int32_t get_g8() const { return int32_t(CLAMP(Math::round(g * 255.0f), 0.0f, 255.0f)); }
//_FORCE_INLINE_ void set_b8(int32_t b8) { b = (CLAMP(b8, 0, 255) / 255.0f); }
//_FORCE_INLINE_ int32_t get_b8() const { return int32_t(CLAMP(Math::round(b * 255.0f), 0.0f, 255.0f)); }
//_FORCE_INLINE_ void set_a8(int32_t a8) { a = (CLAMP(a8, 0, 255) / 255.0f); }
//_FORCE_INLINE_ int32_t get_a8() const { return int32_t(CLAMP(Math::round(a * 255.0f), 0.0f, 255.0f)); }

//_FORCE_INLINE_ void set_h(float p_h) { set_hsv(p_h, get_s(), get_v(), a); }
//_FORCE_INLINE_ void set_s(float p_s) { set_hsv(get_h(), p_s, get_v(), a); }
//_FORCE_INLINE_ void set_v(float p_v) { set_hsv(get_h(), get_s(), p_v, a); }

void GDAPI pandemonium_color_new_rgba(pandemonium_color *r_dest, const pandemonium_real p_r, const pandemonium_real p_g, const pandemonium_real p_b, const pandemonium_real p_a);
void GDAPI pandemonium_color_new_rgb(pandemonium_color *r_dest, const pandemonium_real p_r, const pandemonium_real p_g, const pandemonium_real p_b);

#ifdef __cplusplus
}
#endif

#endif // GDNATIVE_COLOR_H

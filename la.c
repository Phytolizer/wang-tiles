#include <math.h>
#include <stddef.h>

#define C_X 0
#define C_Y 1
#define C_Z 2
#define C_W 3

#define C_U 0
#define C_V 1

#define C_R 0
#define C_G 1
#define C_B 2
#define C_A 3

float lerpf(float a, float b, float t) {
	return a + t * (b - a);
}

typedef struct {
	float c[2];
} Vec2f;

typedef struct {
	float c[3];
} Vec3f;

typedef struct {
	float c[4];
} Vec4f;

typedef Vec3f RGB;
typedef Vec4f RGBA;
typedef Vec2f UV;

Vec2f vec2f(float x, float y) {
	Vec2f v = {{x, y}};
	return v;
}

///////////////////////////

Vec2f vec2fs(float x) {
	return vec2f(x, x);
}

Vec2f vec2f_sum(Vec2f a, Vec2f b) {
	for (size_t i = 0; i < 2; i++) {
		a.c[i] += b.c[i];
	}
	return a;
}

Vec2f vec2f_sub(Vec2f a, Vec2f b) {
	for (size_t i = 0; i < 2; i++) {
		a.c[i] -= b.c[i];
	}
	return a;
}

Vec2f vec2f_mul(Vec2f a, Vec2f b) {
	for (size_t i = 0; i < 2; i++) {
		a.c[i] *= b.c[i];
	}
	return a;
}

Vec2f vec2f_div(Vec2f a, Vec2f b) {
	for (size_t i = 0; i < 2; i++) {
		a.c[i] /= b.c[i];
	}
	return a;
}

Vec2f vec2f_max(Vec2f a, Vec2f b) {
	for (size_t i = 0; i < 2; i++) {
		if (a.c[i] < b.c[i]) {
			a.c[i] = b.c[i];
		}
	}
	return a;
}

Vec2f vec2f_min(Vec2f a, Vec2f b) {
	for (size_t i = 0; i < 2; i++) {
		if (a.c[i] > b.c[i]) {
			a.c[i] = b.c[i];
		}
	}
	return a;
}

float vec2f_sqrlen(Vec2f a) {
	float sqr_len = 0.0F;
	for (size_t i = 0; i < 2; i++) {
		sqr_len += a.c[i] * a.c[i];
	}
	return sqr_len;
}

float vec2f_len(Vec2f a) {
	return sqrtf(vec2f_sqrlen(a));
}

Vec2f vec2f_lerp(Vec2f a, Vec2f b, Vec2f t) {
	for (size_t i = 0; i < 2; i++) {
		a.c[i] = lerpf(a.c[i], b.c[i], t.c[i]);
	}
	return a;
}

Vec2f vec2f_sqrt(Vec2f a) {
	for (size_t i = 0; i < 2; i++) {
		a.c[i] = sqrtf(a.c[i]);
	}
	return a;
}

Vec2f vec2f_pow(Vec2f b, Vec2f e) {
	for (size_t i = 0; i < 2; i++) {
		b.c[i] = powf(b.c[i], e.c[i]);
	}
	return b;
}

///////////////////////////

Vec3f vec3f(float x, float y, float z) {
	Vec3f v = {{x, y, z}};
	return v;
}

Vec3f vec3fs(float x) {
	return vec3f(x, x, x);
}

Vec3f vec3f_sum(Vec3f a, Vec3f b) {
	for (size_t i = 0; i < 3; i++) {
		a.c[i] += b.c[i];
	}
	return a;
}

Vec3f vec3f_sub(Vec3f a, Vec3f b) {
	for (size_t i = 0; i < 3; i++) {
		a.c[i] -= b.c[i];
	}
	return a;
}

Vec3f vec3f_mul(Vec3f a, Vec3f b) {
	for (size_t i = 0; i < 3; i++) {
		a.c[i] *= b.c[i];
	}
	return a;
}

Vec3f vec3f_div(Vec3f a, Vec3f b) {
	for (size_t i = 0; i < 3; i++) {
		a.c[i] /= b.c[i];
	}
	return a;
}

Vec3f vec3f_max(Vec3f a, Vec3f b) {
	for (size_t i = 0; i < 3; i++) {
		if (a.c[i] < b.c[i]) {
			a.c[i] = b.c[i];
		}
	}
	return a;
}

Vec3f vec3f_min(Vec3f a, Vec3f b) {
	for (size_t i = 0; i < 3; i++) {
		if (a.c[i] > b.c[i]) {
			a.c[i] = b.c[i];
		}
	}
	return a;
}

float vec3f_sqrlen(Vec3f a) {
	float sqr_len = 0.0F;
	for (size_t i = 0; i < 3; i++) {
		sqr_len += a.c[i] * a.c[i];
	}
	return sqr_len;
}

float vec3f_len(Vec3f a) {
	return sqrtf(vec3f_sqrlen(a));
}

Vec3f vec3f_lerp(Vec3f a, Vec3f b, Vec3f t) {
	for (size_t i = 0; i < 3; i++) {
		a.c[i] = lerpf(a.c[i], b.c[i], t.c[i]);
	}
	return a;
}

Vec3f vec3f_sqrt(Vec3f a) {
	for (size_t i = 0; i < 3; i++) {
		a.c[i] = sqrtf(a.c[i]);
	}
	return a;
}

Vec3f vec3f_pow(Vec3f b, Vec3f e) {
	for (size_t i = 0; i < 3; i++) {
		b.c[i] = powf(b.c[i], e.c[i]);
	}
	return b;
}

///////////////////////////

Vec4f vec4f(float x, float y, float z, float w) {
	Vec4f v = {{x, y, z, w}};
	return v;
}

Vec4f vec4fs(float x) {
	return vec4f(x, x, x, x);
}

Vec4f vec4f_sum(Vec4f a, Vec4f b) {
	for (size_t i = 0; i < 4; i++) {
		a.c[i] += b.c[i];
	}
	return a;
}

Vec4f vec4f_sub(Vec4f a, Vec4f b) {
	for (size_t i = 0; i < 4; i++) {
		a.c[i] -= b.c[i];
	}
	return a;
}

Vec4f vec4f_mul(Vec4f a, Vec4f b) {
	for (size_t i = 0; i < 4; i++) {
		a.c[i] *= b.c[i];
	}
	return a;
}

Vec4f vec4f_div(Vec4f a, Vec4f b) {
	for (size_t i = 0; i < 4; i++) {
		a.c[i] /= b.c[i];
	}
	return a;
}

Vec4f vec4f_max(Vec4f a, Vec4f b) {
	for (size_t i = 0; i < 4; i++) {
		if (a.c[i] < b.c[i]) {
			a.c[i] = b.c[i];
		}
	}
	return a;
}

Vec4f vec4f_min(Vec4f a, Vec4f b) {
	for (size_t i = 0; i < 4; i++) {
		if (a.c[i] > b.c[i]) {
			a.c[i] = b.c[i];
		}
	}
	return a;
}

float vec4f_sqrlen(Vec4f a) {
	float sqr_len = 0.0F;
	for (size_t i = 0; i < 4; i++) {
		sqr_len += a.c[i] * a.c[i];
	}
	return sqr_len;
}

float vec4f_len(Vec4f a) {
	return sqrtf(vec4f_sqrlen(a));
}

Vec4f vec4f_lerp(Vec4f a, Vec4f b, Vec4f t) {
	for (size_t i = 0; i < 4; i++) {
		a.c[i] = lerpf(a.c[i], b.c[i], t.c[i]);
	}
	return a;
}

Vec4f vec4f_sqrt(Vec4f a) {
	for (size_t i = 0; i < 4; i++) {
		a.c[i] = sqrtf(a.c[i]);
	}
	return a;
}

Vec4f vec4f_pow(Vec4f b, Vec4f e) {
	for (size_t i = 0; i < 4; i++) {
		b.c[i] = powf(b.c[i], e.c[i]);
	}
	return b;
}

///////////////////////////

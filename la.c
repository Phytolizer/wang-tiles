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

Vec2f vec2f(float x, float y) {
	Vec2f v = {{x, y}};
	return v;
}

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

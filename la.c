#include "la.h"

#include <math.h>
#include <stddef.h>

static float lerpf(float a, float b, float t) {
    return a + (b - a) * t;
}

vec2f_t vec2f(float x, float y) {
    return (vec2f_t){{x, y}};
}

vec2f_t vec2fs(float x) {
    return vec2f(x, x);
}

vec2f_t vec2f_sum(vec2f_t a, vec2f_t b) {
    for (size_t i = 0; i < 2; i++) {
        a.c[i] += b.c[i];
    }
    return a;
}

vec2f_t vec2f_sub(vec2f_t a, vec2f_t b) {
    for (size_t i = 0; i < 2; i++) {
        a.c[i] -= b.c[i];
    }
    return a;
}

vec2f_t vec2f_mul(vec2f_t a, vec2f_t b) {
    for (size_t i = 0; i < 2; i++) {
        a.c[i] *= b.c[i];
    }
    return a;
}

vec2f_t vec2f_div(vec2f_t a, vec2f_t b) {
    for (size_t i = 0; i < 2; i++) {
        a.c[i] /= b.c[i];
    }
    return a;
}

vec2f_t vec2f_max(vec2f_t a, vec2f_t b) {
    for (size_t i = 0; i < 2; i++) {
        if (a.c[i] < b.c[i]) {
            a.c[i] = b.c[i];
        }
    }
    return a;
}

float vec2f_sqrlen(vec2f_t a) {
    float len = 0.0f;
    for (size_t i = 0; i < 2; i++) {
        len += a.c[i] * a.c[i];
    }
    return len;
}

float vec2f_len(vec2f_t a) {
    return sqrtf(vec2f_sqrlen(a));
}

vec2f_t vec2f_lerp(vec2f_t a, vec2f_t b, vec2f_t t) {
    for (size_t i = 0; i < 2; i++) {
        a.c[i] = lerpf(a.c[i], b.c[i], t.c[i]);
    }
    return a;
}

vec2f_t vec2f_sqrt(vec2f_t a) {
    for (size_t i = 0; i < 2; i++) {
        a.c[i] = sqrtf(a.c[i]);
    }
    return a;
}

vec2f_t vec2f_pow(vec2f_t b, vec2f_t e) {
    for (size_t i = 0; i < 2; i++) {
        b.c[i] = powf(b.c[i], e.c[i]);
    }
    return b;
}

//////////////////////////

vec3f_t vec3f(float x, float y, float z) {
    return (vec3f_t){{x, y, z}};
}

vec3f_t vec3fs(float x) {
    return vec3f(x, x, x);
}

vec3f_t vec3f_sum(vec3f_t a, vec3f_t b) {
    for (size_t i = 0; i < 3; i++) {
        a.c[i] += b.c[i];
    }
    return a;
}

vec3f_t vec3f_sub(vec3f_t a, vec3f_t b) {
    for (size_t i = 0; i < 3; i++) {
        a.c[i] -= b.c[i];
    }
    return a;
}

vec3f_t vec3f_mul(vec3f_t a, vec3f_t b) {
    for (size_t i = 0; i < 3; i++) {
        a.c[i] *= b.c[i];
    }
    return a;
}

vec3f_t vec3f_div(vec3f_t a, vec3f_t b) {
    for (size_t i = 0; i < 3; i++) {
        a.c[i] /= b.c[i];
    }
    return a;
}

vec3f_t vec3f_max(vec3f_t a, vec3f_t b) {
    for (size_t i = 0; i < 3; i++) {
        if (a.c[i] < b.c[i]) {
            a.c[i] = b.c[i];
        }
    }
    return a;
}

float vec3f_sqrlen(vec3f_t a) {
    float len = 0.0f;
    for (size_t i = 0; i < 3; i++) {
        len += a.c[i] * a.c[i];
    }
    return len;
}

float vec3f_len(vec3f_t a) {
    return sqrtf(vec3f_sqrlen(a));
}

vec3f_t vec3f_lerp(vec3f_t a, vec3f_t b, vec3f_t t) {
    for (size_t i = 0; i < 3; i++) {
        a.c[i] = lerpf(a.c[i], b.c[i], t.c[i]);
    }
    return a;
}

vec3f_t vec3f_sqrt(vec3f_t a) {
    for (size_t i = 0; i < 3; i++) {
        a.c[i] = sqrtf(a.c[i]);
    }
    return a;
}

vec3f_t vec3f_pow(vec3f_t b, vec3f_t e) {
    for (size_t i = 0; i < 3; i++) {
        b.c[i] = powf(b.c[i], e.c[i]);
    }
    return b;
}

//////////////////////////

vec4f_t vec4f(float x, float y, float z, float w) {
    return (vec4f_t){{x, y, z, w}};
}

vec4f_t vec4fs(float x) {
    return vec4f(x, x, x, x);
}

vec4f_t vec4f_sum(vec4f_t a, vec4f_t b) {
    for (size_t i = 0; i < 4; i++) {
        a.c[i] += b.c[i];
    }
    return a;
}

vec4f_t vec4f_sub(vec4f_t a, vec4f_t b) {
    for (size_t i = 0; i < 4; i++) {
        a.c[i] -= b.c[i];
    }
    return a;
}

vec4f_t vec4f_mul(vec4f_t a, vec4f_t b) {
    for (size_t i = 0; i < 4; i++) {
        a.c[i] *= b.c[i];
    }
    return a;
}

vec4f_t vec4f_div(vec4f_t a, vec4f_t b) {
    for (size_t i = 0; i < 4; i++) {
        a.c[i] /= b.c[i];
    }
    return a;
}

vec4f_t vec4f_max(vec4f_t a, vec4f_t b) {
    for (size_t i = 0; i < 4; i++) {
        if (a.c[i] < b.c[i]) {
            a.c[i] = b.c[i];
        }
    }
    return a;
}

float vec4f_sqrlen(vec4f_t a) {
    float len = 0.0f;
    for (size_t i = 0; i < 4; i++) {
        len += a.c[i] * a.c[i];
    }
    return len;
}

float vec4f_len(vec4f_t a) {
    return sqrtf(vec4f_sqrlen(a));
}

vec4f_t vec4f_lerp(vec4f_t a, vec4f_t b, vec4f_t t) {
    for (size_t i = 0; i < 4; i++) {
        a.c[i] = lerpf(a.c[i], b.c[i], t.c[i]);
    }
    return a;
}

vec4f_t vec4f_sqrt(vec4f_t a) {
    for (size_t i = 0; i < 4; i++) {
        a.c[i] = sqrtf(a.c[i]);
    }
    return a;
}

vec4f_t vec4f_pow(vec4f_t b, vec4f_t e) {
    for (size_t i = 0; i < 4; i++) {
        b.c[i] = powf(b.c[i], e.c[i]);
    }
    return b;
}

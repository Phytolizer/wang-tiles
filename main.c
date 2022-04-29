#include "./la.c"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
#include <stdbool.h>
#include <stdint.h>

#define TILE_WIDTH 512
#define TILE_HEIGHT 512
#define TILESET_WIDTH (TILE_WIDTH * 4)
#define TILESET_HEIGHT (TILE_HEIGHT * 4)

typedef RGB (*FragShader)(UV uv);
typedef uint32_t RGBA32;

static RGB stripes(UV uv) {
	const float n = 20.0F;
	Vec3f v = vec3f(sinf(uv.c[C_U] * n), sinf((uv.c[C_U] + uv.c[C_V]) * n), cosf(uv.c[C_V] * n));
	return vec3f_mul(vec3f_sum(v, vec3fs(1.0F)), vec3fs(0.5F));
}

static RGB japan(UV uv) {
	float r = 0.25F;
	bool a = vec2f_sqrlen(vec2f_sub(vec2fs(0.5F), uv)) > r * r;
	return vec3f(1.0F, (float)a, (float)a);
}

static RGBA32 make_rgba32(float r, float g, float b) {
	return (uint32_t)(r * 255) | (uint32_t)(g * 255) << 8 | (uint32_t)(b * 255) << 16 |
			UINT32_C(0xFF000000);
}

static void generate_image32(
		uint32_t* pixels, size_t width, size_t height, size_t stride, FragShader shader) {
	for (size_t y = 0; y < height; y++) {
		for (size_t x = 0; x < width; x++) {
			float u = (float)x / (float)width;
			float v = (float)y / (float)height;
			RGB pixel = shader(vec2f(u, v));
			pixels[y * stride + x] = make_rgba32(pixel.c[C_R], pixel.c[C_G], pixel.c[C_B]);
		}
	}
}

RGBA32 tile[TILE_WIDTH * TILE_HEIGHT];

int main(void) {
	generate_image32(tile, TILE_WIDTH, TILE_HEIGHT, TILE_WIDTH, japan);
	if (!stbi_write_png(
				"output.png", TILE_WIDTH, TILE_HEIGHT, 4, tile, TILE_WIDTH * sizeof(RGBA32))) {
		fprintf(stderr, "Failed to write output.png\n");
		return 1;
	}
}

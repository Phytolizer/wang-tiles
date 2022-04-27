#include "./la.c"

#define TILE_WIDTH 128
#define TILE_HEIGHT 128
#define TILESET_WIDTH (TILE_WIDTH * 4)
#define TILESET_HEIGHT (TILE_HEIGHT * 4)

RGB stripes(UV uv) {
	const float n = 20.0F;
	return vec3f((sinf(uv.c[C_U] * n) + 1.0F) * 0.5F,
			(sinf((uv.c[C_U] + uv.c[C_V]) * n) + 1.0F) * 0.5F, (cosf(uv.c[C_V] * n) + 1.0F) * 0.5F);
}

int main(void) {}

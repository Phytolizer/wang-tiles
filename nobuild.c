#include "nobuild.h"

#include <stdio.h>

const char* sources[] = {
        "la",
        "stb_image_write",
        "wang",
};

#define CFLAGS "-O2", "-Wall", "-Wextra", "-Wpedantic", "-std=c99"

int main(int argc, char** argv) {
    REBUILD_SELF(argc, argv);

    MKDIRS("build", "obj");
    const char** objects = malloc(sizeof(char*) * (sizeof sources / sizeof *sources + 1));
    size_t i = 0;
    FOREACH_ARRAY(const char*, source, sources, {
        objects[i] = PATH("build", "obj", CONCAT(source, ".o"));
        CMD("cc", CFLAGS, "-c", CONCAT(source, ".c"), "-o", objects[i]);
        i++;
    });
    objects[i] = NULL;
    MKDIRS("build", "bin");
    char** final_cmd =
            collect_args("vpvvv", "cc", objects, "-lm", "-o", PATH("build", "bin", "wang"));
    echo_cmd(final_cmd);
    nobuild_exec(final_cmd);

    if (argc > 1 && strcmp(argv[1], "run") == 0) {
        CMD(PATH("build", "bin", "wang"));
    }
}

CFLAGS := -Wall -Wextra -Wpedantic \
					-std=c11 -Werror=implicit-function-declaration -Wmissing-prototypes -Wswitch-enum \
					-ggdb3 -Og \
					-isystem 3rd
LIBS := -lm
.PHONY: all
all: main
main: main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

.PHONY: clean
clean:
	rm -vf *.o main

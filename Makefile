LIBS := -lm
.PHONY: all
all: main
main: main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

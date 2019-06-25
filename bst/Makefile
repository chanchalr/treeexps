CPPFLAGS = -Wall -g -I headers
CC = gcc
DEPS = headers/*.h
src = $(wildcard src/*.c)
obj = $(patsubst src/%.c,build/%.o,$(src))
headers = $(wildcard headers/*.c)
tree: $(obj)
	$(CC) -o $@ $^ $(CFLAGS)
build/%.o: src/%.c $(headers)
	$(CC) -c -o $@ $< $(CFLAGS) $(CPPFLAGS)
clean:
	rm -f build/*.o tree


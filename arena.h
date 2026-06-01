#ifndef ARENA_H
#define ARENA_H

typedef struct
{
	unsigned char* buffer;
	size_t capacity;
	size_t used;
}Arena;

void arena_init(Arena *a, size_t size);

#endif

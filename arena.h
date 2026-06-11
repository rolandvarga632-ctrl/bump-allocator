#ifndef ARENA_H
#define ARENA_H
#include<stddef.h>

typedef struct
{
	unsigned char* buffer;
	size_t capacity;
	size_t used;
}Arena;

void arena_init(Arena *a, size_t size);
void* arena_alloc(Arena *from, size_t size);
void arena_destroy(Arena *a);
void arena_reset(Arena *a);

#endif

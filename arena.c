#include<stdlib.h>

void arena_init(Arena *a, size_t size)
{
	a->buffer = malloc(size);
	a->capacity = size;
	a->used = 0;
}

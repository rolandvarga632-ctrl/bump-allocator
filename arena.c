#include<stdlib.h>
#include"arena.h"



void arena_init(Arena *a, size_t size)
{
	if ( size == 0)
	{
		a->buffer = NULL;
		a->capacity = 0;
		a->used = 0;
	}else {

	a->buffer = malloc(size);
	a->capacity = size;
	a->used = 0;

	}
}

void* arena_alloc(Arena *from, size_t size)
{
	if (size == 0) return NULL;

	size_t aligned = (from->used + 7) & ~7;
	if (aligned + size > from->capacity) return NULL;

	unsigned char *cursor = from->buffer + aligned;
	from->used = aligned + size;
	

	return (void*)cursor; 
}

void arena_destroy(Arena *a)
{
	free(a->buffer);
	a->capacity = 0;
	a->used = 0;
}

void arena_reset(Arena *a)
{
	a->used = 0;
}

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
	if (from->used + size > from->capacity) return NULL;
	
	unsigned char *cursor = from->buffer + from->used;
	from->used += size;
	

	return (void*)cursor; 
}

void arena_destroy(Arena *a)
{
	free(a->buffer);
	a->capacity = 0;
	a->used = 0;
}

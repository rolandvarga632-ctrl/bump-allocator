#include"arena.h"
#include<stdio.h>

int main()
{
	Arena a;
	arena_init(&a,1024);

	if (a.buffer == NULL)
	{
		printf("Hiba\n");
	}
	
	char *str = arena_alloc(&a,3*sizeof(char));
	*str = 'A';
	str[1] = 'B';
	str[2] = '\0';
	
	printf("%p\n",str);
	printf("%s\n",str);
	 
	arena_destroy(&a);

	return 0;
}

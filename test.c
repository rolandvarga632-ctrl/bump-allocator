#include"arena.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
	Arena a;
	arena_init(&a,1024);

	if (a.buffer == NULL)
	{
		printf("Hiba\n");
		return 1;
	}

	char *str = arena_alloc(&a,2);
	str[0] = 'K';
	str[1] = '\0';

	int *nums = arena_alloc(&a,8*sizeof(int));
	int *num2 = arena_alloc(&a,8*sizeof(int));
	char *strs = arena_alloc(&a,7);
	double *pi = arena_alloc(&a,sizeof(double));
	*pi = 3.1454678;

	for (int i = 0; i < 8; i++){ nums[i] = (i+1)*10;num2[i] = (i+2)*10;}
	for (int i = 0; i < 6; i++){ strs[i] = i + 'A';}
	strs[6] = '\0';

	arena_reset(&a);

	char *str2 = arena_alloc(&a,2);
	str2[0] = 'C';
	str2[1] = '\0';

	arena_destroy(&a);
	return 0;
}

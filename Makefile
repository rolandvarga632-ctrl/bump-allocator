all:
	@gcc -Wall arena.c test.c -o allocator -g && ./allocator
	@valgrind --leak-check=full --track-origins=yes ./allocator


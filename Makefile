buggy: buggy.c
	gcc -Wall -std=c99 -o buggy buggy.c

codecheck:
	infer -- gcc -o buggy buggy.c

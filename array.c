#include <stdio.h>
#include <stdlib.h>

typedef struct structArray Array;
void createArray(Array *a, size_t initialSize);
void freeArray(Array *a);

typedef struct structArray
{
	int *array;
} Array;

// Method for initializing array
void createArray(Array *a, size_t initialSize)
{
	a->array = malloc(sizeof(int) * initialSize);
}

// Frees array after it's of no more use.
void freeArray(Array *a)
{
	free(a->array);
	a->array = NULL;
}
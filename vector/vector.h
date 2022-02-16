#ifndef vector_h
#define vector_h

#include <stddef.h>

#define MAX_SIZE 5

typedef int elem_t;

typedef struct{
	size_t size;
	size_t max_size;
	elem_t* data;
}vector;

vector* vector_create(size_t element_size);
void vector_destroy(vector* v);

int vector_delete(vector* v, int n);
int vector_add(vector* v, int n, elem_t data);
void vector_push(vector* v, elem_t data);
elem_t vector_get(vector* v, int n);
size_t vector_size(vector* v);

void vector_show(vector* v);
void vector_swap(vector* v, elem_t i, elem_t j);

#endif
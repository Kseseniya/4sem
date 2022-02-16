#include "vector.h"
#include <stdio.h>
#include <stdlib.h>


vector* vector_create(size_t element_size)
{
	vector* v = (vector*) malloc(sizeof(vector));
	v->size = 0;
	v->max_size = MAX_SIZE;
	v->data = (elem_t*)malloc(MAX_SIZE * sizeof(elem_t));
	return v;
}

void vector_destroy(vector* v)
{
	free(v->data);
	v->size = 0;
	v->max_size = 0;
	free(v);
}

void vector_push(vector* v, elem_t data)
{
	if(v->max_size == v->size)
	{
		v->max_size = v->max_size * 2;
		v->data = realloc(v->data, (v->max_size) * sizeof(elem_t));
	}
	v->size ++;
	v->data[v->size - 1] = data;
}

int vector_delete(vector* v, int n)
{
	if(n < 0 || n > (v->size - 1) || v->size <= 0)
	{
		return 1;
	}

	for (int i = n; i < (v->size - 1); ++i)
	{
		v->data[i] = v->data[i+1];
	}

	v->size --;
	return 0;
}

int vector_add(vector* v, int n, elem_t data)
{
	if(n < 0 || n > v->size  || v->size <= 0)
	{
		printf("bad position\n");
		return 1;
	}

	if (v->max_size == v->size)
	{
		v->max_size = v->max_size * 2;
		v->data = realloc(v->data, (v->max_size) * sizeof(elem_t));
	}

	v->size ++;

	for(int i = v->size - 1; i > n; i--)
	{
		v->data[i] = v->data[i - 1];
	}

	v->data[n] = data;
	return 0;
}

void vector_show(vector* v)
{
	for (int i = 0; i < v->size; ++i)
	{
		printf("%d ", v->data[i]);
	}

	printf("\n");
}

void vector_swap(vector* v, elem_t i, elem_t j)
{
	if(i < 0 || i > (v->size - 1))
	{
		printf("bad position\n");
		return;
	}
	if(j < 0 || j > (v->size - 1))
	{
		printf("bad position\n");
		return;
	}
	elem_t tmp = v->data[i];
	v->data[i] = v->data[j];
	v->data[j] = tmp;
}

elem_t vector_get(vector* v, int n)
{
	if(n < 0 || n > (v->size - 1))
	{
		printf("bad position\n");
		return 0;
	}

	return v->data[n];
}

size_t vector_size(vector* v)
{
	return v->size;
}
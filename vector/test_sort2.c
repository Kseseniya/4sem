#include <stdlib.h>
#include "vector.h"

int main(int argc, char const *argv[])
{
	vector* v = vector_create(sizeof(elem_t));
	/*list* l = ...;
	cont *p = ffgg ? v : l;

	p->get(p,j);
	cont_m list/vector_create

	p->m.get(p, j);
	cont_m* m;
	list;

	struct cont_m {
		int (*get) (cont*p, int i);
		...;
	}
	*/

	for (int i = 0; i < 6; ++i)
	{
		vector_push(v, rand());
	}

	vector_show(v);
	int swap;

	for (int i = (vector_size(v) - 1); i >= 0; --i)
	{
		swap = 0;

		for (int j = 0; j < i; ++j)
		{
			if(vector_get(v, j) > vector_get(v, j + 1))
			{
				vector_swap(v, j, j + 1);
				swap = 1;
			}
		}

		if(swap == 0)
		{
			break;
		}
	}
	vector_show(v);
	return 0;
}

/* TO DO:

fix vector_create// OK

fix vector_add //OK
fix vector_delete //OK
fix vector_swap //OK

create vector_get //OK
create vector_push//OK
create vector_size//OK
create vector_head
create vector_tail

rewrite test_sort2.c //OK
*/
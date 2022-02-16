#include "view.h"

int main(int argc, char const *argv[])
{
	view* v;
	if(argc == 1)
	{
		v = view::get("text");
	}
	else
	{
		v = view::get(argv[1]);
	}
	return 0;
}
#include <iostream>
#include <intrin.h>

#include "Dict.h"

int main()
{
	Dict s1({"dima", "mama", "papa"});
	Dict s2({ "dima", "mama", "ded" });

	auto tmp = s2.Intersect(s1);

	return 0;
}
#include <iostream>
#include <intrin.h>

#include "Set.h"

int main()
{
	Set s1({"dima", "mama", "papa"});
	Set s2({ "dima", "mama", "ded" });

	auto tmp = s2.Intersect(s1);

	return 0;
}
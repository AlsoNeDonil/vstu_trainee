#include <iostream>
#include <intrin.h>

#include "Set.h"

int main()
{
	Set s1({ 1, 5, 3, 5, 1, 2, 8, 1 });
	Set s2({ 1, 2, 3, 4, 5, 6, 7, 8 });

	auto tmp = s2.Intersect(s1);

	return 0;
}
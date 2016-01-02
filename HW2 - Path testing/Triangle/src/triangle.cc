#include "triangle.h"

// Returns type of the triangle
TriangleType Triangle(int a, int b, int c)
{
	TriangleType type;

	if ((a < 1 || a > 200) ||
		(b < 1 || b > 200) ||
		(c < 1 || c > 200))
	{
		type = OUT_OF_RANGE;
	}
	else if ((a + b <= c) ||
			(b + c <= a) ||
			(c + a <= b))
	{
		type = NOT_A_TRIANGLE;
	}
	else if ((a == b) &&
			(b == c))
	{
		type = EQUILATERAL;
	}
	else if ((a == b) ||
			(b == c) ||
			(c == a))
	{
		type = ISOSCELES;
	}
	else
	{
		type = SCALENE;
	}

	return type;
}
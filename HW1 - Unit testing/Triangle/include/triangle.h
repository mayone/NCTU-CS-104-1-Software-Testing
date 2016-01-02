#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

const int LOWER_BOUND = 1;
const int UPPER_BOUND = 200;
const int VALID_VALUE = UPPER_BOUND / 2;

enum TriangleType {
	EQUILATERAL,
	ISOSCELES,
	SCALENE,
	NOT_A_TRIANGLE,
	OUT_OF_RANGE
};

// Returns type of the triangle
TriangleType Triangle(int a, int b, int c);

#endif  // __TRIANGLE_H__

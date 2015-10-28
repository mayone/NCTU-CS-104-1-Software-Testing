#include <limits.h>
#include "triangle.h"
#include "gtest/gtest.h"


// Robust Boundary Value Testing
TEST(TriangleTest, BoundaryValue) {
	TriangleType EXPECT_TYPE;
	if (UPPER_BOUND & 1)
		EXPECT_TYPE = NOT_A_TRIANGLE;
	else
		EXPECT_TYPE = ISOSCELES;

	EXPECT_EQ(OUT_OF_RANGE, Triangle(LOWER_BOUND-1, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(ISOSCELES, Triangle(LOWER_BOUND, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(ISOSCELES, Triangle(LOWER_BOUND+1, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(EXPECT_TYPE, Triangle(UPPER_BOUND-1, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(UPPER_BOUND, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(OUT_OF_RANGE, Triangle(UPPER_BOUND+1, VALID_VALUE, VALID_VALUE));

	EXPECT_EQ(OUT_OF_RANGE, Triangle(VALID_VALUE, LOWER_BOUND-1, VALID_VALUE));
	EXPECT_EQ(ISOSCELES, Triangle(VALID_VALUE, LOWER_BOUND, VALID_VALUE));
	EXPECT_EQ(ISOSCELES, Triangle(VALID_VALUE, LOWER_BOUND+1, VALID_VALUE));
	EXPECT_EQ(EXPECT_TYPE, Triangle(VALID_VALUE, UPPER_BOUND-1, VALID_VALUE));
	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(VALID_VALUE, UPPER_BOUND, VALID_VALUE));
	EXPECT_EQ(OUT_OF_RANGE, Triangle(VALID_VALUE, UPPER_BOUND+1, VALID_VALUE));

	EXPECT_EQ(OUT_OF_RANGE, Triangle(VALID_VALUE, VALID_VALUE, LOWER_BOUND-1));
	EXPECT_EQ(ISOSCELES, Triangle(VALID_VALUE, VALID_VALUE, LOWER_BOUND));
	EXPECT_EQ(ISOSCELES, Triangle(VALID_VALUE, VALID_VALUE, LOWER_BOUND+1));
	EXPECT_EQ(EXPECT_TYPE, Triangle(VALID_VALUE, VALID_VALUE, UPPER_BOUND-1));
	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(VALID_VALUE, VALID_VALUE, UPPER_BOUND));
	EXPECT_EQ(OUT_OF_RANGE, Triangle(VALID_VALUE, VALID_VALUE, UPPER_BOUND+1));

	EXPECT_EQ(EQUILATERAL, Triangle(VALID_VALUE, VALID_VALUE, VALID_VALUE));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
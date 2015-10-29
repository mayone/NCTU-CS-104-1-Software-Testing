#include "nextDate.h"
#include "gtest/gtest.h"


// Robust Boundary Value Testing
TEST(NextDateTest, BoundaryValue_Robust) {
	// Tests year
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_LOWER-1, 8, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_LOWER, 8, 26), NextDate(Date(YEAR_LOWER, 8, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_LOWER, 8, 26), NextDate(Date(YEAR_LOWER, 8, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_LOWER+1, 8, 26), NextDate(Date(YEAR_LOWER+1, 8, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 26), NextDate(Date(YEAR_VALID, 8, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_UPPER-1, 8, 26), NextDate(Date(YEAR_UPPER-1, 8, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_UPPER, 8, 26), NextDate(Date(YEAR_UPPER, 8, 25))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_UPPER+1, 8, 25))));
	// Tests month
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_VALID, 0, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 1, 26), NextDate(Date(YEAR_VALID, 1, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 2, 26), NextDate(Date(YEAR_VALID, 2, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 26), NextDate(Date(YEAR_VALID, 8, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 11, 26), NextDate(Date(YEAR_VALID, 11, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 12, 26), NextDate(Date(YEAR_VALID, 12, 25))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_VALID, 13, 25))));
	// Tests day
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_VALID, 8, 0))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 2), NextDate(Date(YEAR_VALID, 8, 1))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 3), NextDate(Date(YEAR_VALID, 8, 2))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 16), NextDate(Date(YEAR_VALID, 8, 15))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 31), NextDate(Date(YEAR_VALID, 8, 30))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 9, 1), NextDate(Date(YEAR_VALID, 8, 31))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_VALID, 8, 32))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_VALID, 6, 31))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_VALID, 2, 30))));
}

// Equivalence Class Testing
// Y: 1900, 1993, 1994, 2000
// M: Feb, Jul, Aug, Dec
// D: 15, 29, 30, 31
TEST(NextDateTest, EquivalenceClass_WeakNormal) {
	EXPECT_TRUE(EQUAL(Date(1900, 2, 16), NextDate(Date(1900, 2, 15))));
	EXPECT_TRUE(EQUAL(Date(1993, 7, 30), NextDate(Date(1993, 7, 29))));
	EXPECT_TRUE(EQUAL(Date(1994, 8, 31), NextDate(Date(1994, 8, 30))));
	EXPECT_TRUE(EQUAL(Date(2001, 1, 1), NextDate(Date(2000, 12, 31))));

}
TEST(NextDateTest, EquivalenceClass_WeakRobust) {
	// Lower bound
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(1811, 2, 15))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(1900, 0, 15))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(1900, 2, 0))));
	// Upper bound
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(2013, 2, 15))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(1900, 13, 15))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(1900, 2, 30))));
}
TEST(NextDateTest, EquivalenceClass_StrongNormal) {
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(1900, 2, 31))));

	EXPECT_TRUE(EQUAL(Date(1900, 8, 1), NextDate(Date(1900, 7, 31))));
	EXPECT_TRUE(EQUAL(Date(1900, 9, 1), NextDate(Date(1900, 8, 31))));
	EXPECT_TRUE(EQUAL(Date(1901, 1, 1), NextDate(Date(1900, 12, 31))));

	EXPECT_TRUE(EQUAL(Date(1900, 2, 16), NextDate(Date(1900, 2, 15))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(1900, 2, 29))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(1900, 2, 30))));
	// Leap year
	EXPECT_TRUE(EQUAL(Date(1900, 3, 1), NextDate(Date(1900, 2, 28))));
	EXPECT_TRUE(EQUAL(Date(1993, 3, 1), NextDate(Date(1993, 2, 28))));
	EXPECT_TRUE(EQUAL(Date(2000, 2, 29), NextDate(Date(2000, 2, 28))));
}
TEST(NextDateTest, EquivalenceClass_StrongRobust) {
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_LOWER-1, MONTH_LOWER-1, 25))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_LOWER-1, 8, DAY_LOWER-1))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(1993, MONTH_LOWER-1, DAY_LOWER-1))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_LOWER-1, MONTH_LOWER-1, DAY_LOWER-1))));

	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_UPPER+1, MONTH_UPPER+1, 25))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_UPPER+1, 8, 32))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(1993, MONTH_UPPER+1, 32))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_UPPER+1, MONTH_UPPER+1, 32))));
}

// Edge Testing
TEST(NextDateTest, Edge_WeakNormal) {
	// valid
	EXPECT_TRUE(EQUAL(Date(YEAR_LOWER, MONTH_LOWER, DAY_LOWER+1), NextDate(Date(YEAR_LOWER, MONTH_LOWER, DAY_LOWER))));
	EXPECT_TRUE(EQUAL(Date(1993, MONTH_LOWER, DAY_LOWER+1), NextDate(Date(1993, MONTH_LOWER, DAY_LOWER))));
	EXPECT_TRUE(EQUAL(Date(YEAR_LOWER, 8, DAY_LOWER+1), NextDate(Date(YEAR_LOWER, 8, DAY_LOWER))));
	EXPECT_TRUE(EQUAL(Date(YEAR_LOWER, MONTH_LOWER, 26), NextDate(Date(YEAR_LOWER, MONTH_LOWER, 25))));

	EXPECT_TRUE(EQUAL(Date(YEAR_VALID+1, 1, 1), NextDate(Date(YEAR_VALID, 12, 31))));
	EXPECT_TRUE(EQUAL(Date(YEAR_UPPER, 9, 1), NextDate(Date(YEAR_UPPER, 8, 31))));
	EXPECT_TRUE(EQUAL(Date(YEAR_UPPER, MONTH_UPPER, 26), NextDate(Date(YEAR_UPPER, MONTH_UPPER, 25))));
	// invalid
	// Feb
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_VALID, 2, 30))));
	// 30 days month
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_VALID, 6, 31))));
	// over 2012
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_UPPER, MONTH_UPPER, 31))));
}

// Decision Table-Based Testing
TEST(NextDateTest, DecisionTable) {
	EXPECT_TRUE(EQUAL(Date(2001, 4, 16), NextDate(Date(2001, 4, 15))));
	EXPECT_TRUE(EQUAL(Date(2001, 5, 1), NextDate(Date(2001, 4, 30))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(2001, 4, 31))));

	EXPECT_TRUE(EQUAL(Date(2001, 1, 16), NextDate(Date(2001, 1, 15))));
	EXPECT_TRUE(EQUAL(Date(2001, 2, 1), NextDate(Date(2001, 1, 31))));

	EXPECT_TRUE(EQUAL(Date(2001, 12, 16), NextDate(Date(2001, 12, 15))));
	EXPECT_TRUE(EQUAL(Date(2002, 1, 1), NextDate(Date(2001, 12, 31))));

	EXPECT_TRUE(EQUAL(Date(2001, 2, 16), NextDate(Date(2001, 2, 15))));
	EXPECT_TRUE(EQUAL(Date(2004, 2, 29), NextDate(Date(2004, 2, 28))));
	EXPECT_TRUE(EQUAL(Date(2001, 3, 1), NextDate(Date(2001, 2, 28))));
	EXPECT_TRUE(EQUAL(Date(2004, 3, 1), NextDate(Date(2004, 2, 29))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(2001, 2, 29))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(2001, 2, 30))));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
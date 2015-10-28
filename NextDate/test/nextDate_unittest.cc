#include "nextDate.h"
#include "gtest/gtest.h"


// Robust Boundary Value Testing
TEST(NextDateTest, BoundaryValue_Robust) {
	// Tests year
	EXPECT_EQ(invalidDate, NextDate(Date(YEAR_LOWER-1, 8, 25)));
	EXPECT_EQ(Date(YEAR_LOWER, 8, 26), NextDate(Date(YEAR_LOWER, 8, 25)));
	EXPECT_EQ(Date(YEAR_LOWER+1, 8, 26), NextDate(Date(YEAR_LOWER+1, 8, 25)));
	EXPECT_EQ(Date(YEAR_VALID, 8, 26), NextDate(Date(YEAR_VALID, 8, 25)));
	EXPECT_EQ(Date(YEAR_UPPER-1, 8, 26), NextDate(Date(YEAR_UPPER-1, 8, 25)));
	EXPECT_EQ(Date(YEAR_UPPER, 8, 26), NextDate(Date(YEAR_UPPER, 8, 25)));
	EXPECT_EQ(invalidDate, NextDate(Date(YEAR_UPPER+1, 8, 25)));
	// Tests month
	EXPECT_EQ(invalidDate, NextDate(Date(YEAR_VALID, 0, 25)));
	EXPECT_EQ(Date(YEAR_VALID, 1, 26), NextDate(Date(YEAR_VALID, 1, 25)));
	EXPECT_EQ(Date(YEAR_VALID, 2, 26), NextDate(Date(YEAR_VALID, 2, 25)));
	EXPECT_EQ(Date(YEAR_VALID, 8, 26), NextDate(Date(YEAR_VALID, 8, 25)));
	EXPECT_EQ(Date(YEAR_VALID, 11, 26), NextDate(Date(YEAR_VALID, 11, 25)));
	EXPECT_EQ(Date(YEAR_VALID, 12, 26), NextDate(Date(YEAR_VALID, 12, 25)));
	EXPECT_EQ(invalidDate, NextDate(Date(YEAR_VALID, 13, 25)));
	// Tests day
	EXPECT_EQ(invalidDate, NextDate(Date(YEAR_VALID, 8, 0)));
	EXPECT_EQ(Date(YEAR_VALID, 8, 2), NextDate(Date(YEAR_VALID, 8, 1)));
	EXPECT_EQ(Date(YEAR_VALID, 8, 3), NextDate(Date(YEAR_VALID, 8, 2)));
	EXPECT_EQ(Date(YEAR_VALID, 8, 16), NextDate(Date(YEAR_VALID, 8, 15)));
	EXPECT_EQ(Date(YEAR_VALID, 8, 31), NextDate(Date(YEAR_VALID, 8, 30)));
	EXPECT_EQ(Date(YEAR_VALID, 9, 1), NextDate(Date(YEAR_VALID, 8, 31)));
	EXPECT_EQ(invalidDate, NextDate(Date(YEAR_VALID, 8, 32)));
	EXPECT_EQ(invalidDate, NextDate(Date(YEAR_VALID, 6, 31)));
	EXPECT_EQ(invalidDate, NextDate(Date(YEAR_VALID, 2, 30)));
}

// Equivalence Class Testing


// Edge Testing


// Decision Table-Based Testing


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
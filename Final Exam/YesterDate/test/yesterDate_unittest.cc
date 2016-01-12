#include <cstdlib>
#include "yesterDate.h"
#include "gtest/gtest.h"

// Robust Boundary Value Testing
TEST(YesterDateTest, BoundaryValue_Robust) {
	// Tests year
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_LOWER-1, 8, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_LOWER, 8, 24), YesterDate(Date(YEAR_LOWER, 8, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_LOWER, 8, 24), YesterDate(Date(YEAR_LOWER, 8, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_LOWER+1, 8, 24), YesterDate(Date(YEAR_LOWER+1, 8, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 24), YesterDate(Date(YEAR_VALID, 8, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_UPPER-1, 8, 24), YesterDate(Date(YEAR_UPPER-1, 8, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_UPPER, 8, 24), YesterDate(Date(YEAR_UPPER, 8, 25))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_UPPER+1, 8, 25))));
	// Tests month
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_VALID, 0, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 1, 24), YesterDate(Date(YEAR_VALID, 1, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 2, 24), YesterDate(Date(YEAR_VALID, 2, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 24), YesterDate(Date(YEAR_VALID, 8, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 11, 24), YesterDate(Date(YEAR_VALID, 11, 25))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 12, 24), YesterDate(Date(YEAR_VALID, 12, 25))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_VALID, 13, 25))));
	// Tests day
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_VALID, 8, 0))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 7, 31), YesterDate(Date(YEAR_VALID, 8, 1))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 1), YesterDate(Date(YEAR_VALID, 8, 2))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 14), YesterDate(Date(YEAR_VALID, 8, 15))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 29), YesterDate(Date(YEAR_VALID, 8, 30))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 30), YesterDate(Date(YEAR_VALID, 8, 31))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_VALID, 8, 32))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_VALID, 6, 31))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_VALID, 2, 30))));
}

// Decision Table-Based Testing
TEST(YesterDateTest, DecisionTable) {
	EXPECT_TRUE(EQUAL(Date(2001, 3, 31), YesterDate(Date(2001, 4, 1))));
	EXPECT_TRUE(EQUAL(Date(2001, 4, 14), YesterDate(Date(2001, 4, 15))));
	EXPECT_TRUE(EQUAL(Date(2001, 4, 29), YesterDate(Date(2001, 4, 30))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(2001, 4, 31))));

	EXPECT_TRUE(EQUAL(Date(2000, 12, 31), YesterDate(Date(2001, 1, 1))));
	EXPECT_TRUE(EQUAL(Date(2001, 1, 14), YesterDate(Date(2001, 1, 15))));
	EXPECT_TRUE(EQUAL(Date(2001, 1, 30), YesterDate(Date(2001, 1, 31))));

	EXPECT_TRUE(EQUAL(Date(2001, 12, 14), YesterDate(Date(2001, 12, 15))));
	EXPECT_TRUE(EQUAL(Date(2001, 12, 30), YesterDate(Date(2001, 12, 31))));

	EXPECT_TRUE(EQUAL(Date(2001, 2, 14), YesterDate(Date(2001, 2, 15))));
	EXPECT_TRUE(EQUAL(Date(2004, 2, 27), YesterDate(Date(2004, 2, 28))));
	EXPECT_TRUE(EQUAL(Date(2001, 2, 27), YesterDate(Date(2001, 2, 28))));
	EXPECT_TRUE(EQUAL(Date(2004, 2, 28), YesterDate(Date(2004, 2, 29))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(2001, 2, 29))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(2001, 2, 30))));
	EXPECT_TRUE(EQUAL(Date(2001, 2, 28), YesterDate(Date(2001, 3, 1))));
	EXPECT_TRUE(EQUAL(Date(2004, 2, 29), YesterDate(Date(2004, 3, 1))));
}

TEST(YesterDateTest, C0_Coverage) {
	// Date out of range
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_LOWER-1, 8, 25))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_VALID, 0, 25))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_VALID, 8, 0))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(1900, 2, 29))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(2000, 2, 30))));
	// Yester date out of range
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_LOWER, MONTH_LOWER, DAY_LOWER))));
	// Yester year
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID-1, MONTH_UPPER, 31), YesterDate(Date(YEAR_VALID, MONTH_LOWER, DAY_LOWER))));
	// Yester month
	EXPECT_TRUE(EQUAL(Date(1900, 2, 28), YesterDate(Date(1900, 3, 1))));
	EXPECT_TRUE(EQUAL(Date(2000, 2, 29), YesterDate(Date(2000, 3, 1))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 5, 31), YesterDate(Date(YEAR_VALID, 6, 1))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 6, 30), YesterDate(Date(YEAR_VALID, 7, 1))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 31), YesterDate(Date(YEAR_VALID, 9, 1))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 9, 30), YesterDate(Date(YEAR_VALID, 10, 1))));
	// Yester day
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 25), YesterDate(Date(YEAR_VALID, 8, 26))));
}

TEST(YesterDateTest, C1_Coverage) {
	// Just the same as C0 since every branch is traversed.
	// Date out of range
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_LOWER-1, 8, 25))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_VALID, 0, 25))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_VALID, 8, 0))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(1900, 2, 29))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(2000, 2, 30))));
	// Yester date out of range
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_LOWER, MONTH_LOWER, DAY_LOWER))));
	// Yester year
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID-1, MONTH_UPPER, 31), YesterDate(Date(YEAR_VALID, MONTH_LOWER, DAY_LOWER))));
	// Yester month
	EXPECT_TRUE(EQUAL(Date(1900, 2, 28), YesterDate(Date(1900, 3, 1))));
	EXPECT_TRUE(EQUAL(Date(2000, 2, 29), YesterDate(Date(2000, 3, 1))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 5, 31), YesterDate(Date(YEAR_VALID, 6, 1))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 6, 30), YesterDate(Date(YEAR_VALID, 7, 1))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 31), YesterDate(Date(YEAR_VALID, 9, 1))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 9, 30), YesterDate(Date(YEAR_VALID, 10, 1))));
	// Yester day
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 25), YesterDate(Date(YEAR_VALID, 8, 26))));
}

TEST(YesterDateTest, C2_Coverage) {
	// Just the same as C0 and C1 since there is no loop.
	// Date out of range
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_LOWER-1, 8, 25))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_VALID, 0, 25))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_VALID, 8, 0))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(1900, 2, 29))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(2000, 2, 30))));
	// Yester date out of range
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_LOWER, MONTH_LOWER, DAY_LOWER))));
	// Yester year
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID-1, MONTH_UPPER, 31), YesterDate(Date(YEAR_VALID, MONTH_LOWER, DAY_LOWER))));
	// Yester month
	EXPECT_TRUE(EQUAL(Date(1900, 2, 28), YesterDate(Date(1900, 3, 1))));
	EXPECT_TRUE(EQUAL(Date(2000, 2, 29), YesterDate(Date(2000, 3, 1))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 5, 31), YesterDate(Date(YEAR_VALID, 6, 1))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 6, 30), YesterDate(Date(YEAR_VALID, 7, 1))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 31), YesterDate(Date(YEAR_VALID, 9, 1))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 9, 30), YesterDate(Date(YEAR_VALID, 10, 1))));
	// Yester day
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 25), YesterDate(Date(YEAR_VALID, 8, 26))));
}

TEST(YesterDateTest, MCDC_Coverage) {
	// Date out of range
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_LOWER-1, 8, 25))));		// TF FF FF
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_UPPER+1, 8, 25))));		// FT FF FF
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(1900, MONTH_LOWER-1, 25))));	// FF TF FF
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(1900, MONTH_UPPER+1, 25))));	// FF FT FF
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(1900, 8, 0))));				// FF FF TF
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(1900, 6, 31))));				// FF FF FT
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(2001, 2, 29))));
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(1900, 2, 30))));
	// Yester date out of range
	EXPECT_TRUE(EQUAL(invalidDate, YesterDate(Date(YEAR_LOWER, MONTH_LOWER, DAY_LOWER))));
	// Yester year
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID-1, MONTH_UPPER, 31), YesterDate(Date(YEAR_VALID, MONTH_LOWER, DAY_LOWER))));
	// Yester month
	EXPECT_TRUE(EQUAL(Date(1900, 2, 28), YesterDate(Date(1900, 3, 1))));
	EXPECT_TRUE(EQUAL(Date(2000, 2, 29), YesterDate(Date(2000, 3, 1))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 5, 31), YesterDate(Date(YEAR_VALID, 6, 1))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 6, 30), YesterDate(Date(YEAR_VALID, 7, 1))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 31), YesterDate(Date(YEAR_VALID, 9, 1))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 9, 30), YesterDate(Date(YEAR_VALID, 10, 1))));
	// Yester day
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 25), YesterDate(Date(YEAR_VALID, 8, 26))));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	if (argc > 1) {
		switch (atoi(argv[1])) {
			case 0:
				::testing::GTEST_FLAG(filter) = "*.C0_Coverage";
				break;
			case 1:
				::testing::GTEST_FLAG(filter) = "*.C1_Coverage";
				break;
			case 2:
				::testing::GTEST_FLAG(filter) = "*.C2_Coverage";
				break;
			case 3:
				::testing::GTEST_FLAG(filter) = "*.MCDC_Coverage";
				break;
			default:
				break;
		}
	}
	return RUN_ALL_TESTS();
}
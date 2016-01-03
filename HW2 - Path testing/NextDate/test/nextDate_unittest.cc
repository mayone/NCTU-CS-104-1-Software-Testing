#include <cstdlib>
#include "nextDate.h"
#include "gtest/gtest.h"

TEST(NextDateTest, C0_Coverage) {
	// Date out of range
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_LOWER-1, 8, 25))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_VALID, 0, 25))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_VALID, 8, 0))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(1900, 2, 29))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(2000, 2, 30))));
	// Next date out of range
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_UPPER, MONTH_UPPER, 31))));
	// Next year
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID+1, 1, 1), NextDate(Date(YEAR_VALID, MONTH_UPPER, 31))));
	// Next month
	EXPECT_TRUE(EQUAL(Date(1900, 3, 1), NextDate(Date(1900, 2, 28))));
	EXPECT_TRUE(EQUAL(Date(2000, 3, 1), NextDate(Date(2000, 2, 29))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 6, 1), NextDate(Date(YEAR_VALID, 5, 31))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 7, 1), NextDate(Date(YEAR_VALID, 6, 30))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 9, 1), NextDate(Date(YEAR_VALID, 8, 31))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 10, 1), NextDate(Date(YEAR_VALID, 9, 30))));
	// Next day
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 26), NextDate(Date(YEAR_VALID, 8, 25))));
}

TEST(NextDateTest, C1_Coverage) {
	// Just the same as C0 since every branch is traversed.
	// Date out of range
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_LOWER-1, 8, 25))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_VALID, 0, 25))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_VALID, 8, 0))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(1900, 2, 29))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(2000, 2, 30))));
	// Next date out of range
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_UPPER, MONTH_UPPER, 31))));
	// Next year
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID+1, 1, 1), NextDate(Date(YEAR_VALID, MONTH_UPPER, 31))));
	// Next month
	EXPECT_TRUE(EQUAL(Date(1900, 3, 1), NextDate(Date(1900, 2, 28))));
	EXPECT_TRUE(EQUAL(Date(2000, 3, 1), NextDate(Date(2000, 2, 29))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 6, 1), NextDate(Date(YEAR_VALID, 5, 31))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 7, 1), NextDate(Date(YEAR_VALID, 6, 30))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 9, 1), NextDate(Date(YEAR_VALID, 8, 31))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 10, 1), NextDate(Date(YEAR_VALID, 9, 30))));
	// Next day
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 26), NextDate(Date(YEAR_VALID, 8, 25))));
}

TEST(NextDateTest, C2_Coverage) {
	// Just the same as C0 and C1 since there is no loop.
	// Date out of range
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_LOWER-1, 8, 25))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_VALID, 0, 25))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_VALID, 8, 0))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(1900, 2, 29))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(2000, 2, 30))));
	// Next date out of range
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_UPPER, MONTH_UPPER, 31))));
	// Next year
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID+1, 1, 1), NextDate(Date(YEAR_VALID, MONTH_UPPER, 31))));
	// Next month
	EXPECT_TRUE(EQUAL(Date(1900, 3, 1), NextDate(Date(1900, 2, 28))));
	EXPECT_TRUE(EQUAL(Date(2000, 3, 1), NextDate(Date(2000, 2, 29))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 6, 1), NextDate(Date(YEAR_VALID, 5, 31))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 7, 1), NextDate(Date(YEAR_VALID, 6, 30))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 9, 1), NextDate(Date(YEAR_VALID, 8, 31))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 10, 1), NextDate(Date(YEAR_VALID, 9, 30))));
	// Next day
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 26), NextDate(Date(YEAR_VALID, 8, 25))));
}

TEST(NextDateTest, MCDC_Coverage) {
	// Date out of range
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_LOWER-1, 8, 25))));		// TF FF FF
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_UPPER+1, 8, 25))));		// FT FF FF
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(1900, MONTH_LOWER-1, 25))));	// FF TF FF
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(1900, MONTH_UPPER+1, 25))));	// FF FT FF
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(1900, 8, 0))));				// FF FF TF
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(1900, 6, 31))));				// FF FF FT
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(2001, 2, 29))));
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(1900, 2, 30))));
	// Next date out of range
	EXPECT_TRUE(EQUAL(invalidDate, NextDate(Date(YEAR_UPPER, MONTH_UPPER, 31))));
	// Next year
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID+1, 1, 1), NextDate(Date(YEAR_VALID, MONTH_UPPER, 31))));
	// Next month
	EXPECT_TRUE(EQUAL(Date(1900, 3, 1), NextDate(Date(1900, 2, 28))));
	EXPECT_TRUE(EQUAL(Date(2000, 3, 1), NextDate(Date(2000, 2, 29))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 6, 1), NextDate(Date(YEAR_VALID, 5, 31))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 7, 1), NextDate(Date(YEAR_VALID, 6, 30))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 9, 1), NextDate(Date(YEAR_VALID, 8, 31))));
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 10, 1), NextDate(Date(YEAR_VALID, 9, 30))));
	// Next day
	EXPECT_TRUE(EQUAL(Date(YEAR_VALID, 8, 26), NextDate(Date(YEAR_VALID, 8, 25))));
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
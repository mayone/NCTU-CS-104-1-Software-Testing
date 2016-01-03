#include <cstdlib>
#include "commission.h"
#include "gtest/gtest.h"

TEST(CommissionTest, C0_Coverage) {
	// terminated
	EXPECT_EQ(0.0f, Commission(-1, 20, 20));
	// invalid
	EXPECT_EQ(-1.0f, Commission(0, 20, 20));
	EXPECT_EQ(-1.0f, Commission(71, 20, 20));
	EXPECT_EQ(-1.0f, Commission(20, 0, 20));
	EXPECT_EQ(-1.0f, Commission(20, 81, 20));
	EXPECT_EQ(-1.0f, Commission(20, 20, 0));
	EXPECT_EQ(-1.0f, Commission(20, 20, 91));
	// sales <= 1000
	EXPECT_EQ(10.0f, Commission(1, 1, 1));
	// sales > 1000 && sales <= 1800
	EXPECT_EQ(121.75f, Commission(1, 20, 20));
	// sales > 1800
	EXPECT_EQ(260.0f, Commission(20, 20, 20));
}

TEST(CommissionTest, C1_Coverage) {
	// Just the same as C0 since every branch is traversed.
	// terminated
	EXPECT_EQ(0.0f, Commission(-1, 20, 20));
	// invalid
	EXPECT_EQ(-1.0f, Commission(0, 20, 20));
	EXPECT_EQ(-1.0f, Commission(71, 20, 20));
	EXPECT_EQ(-1.0f, Commission(20, 0, 20));
	EXPECT_EQ(-1.0f, Commission(20, 81, 20));
	EXPECT_EQ(-1.0f, Commission(20, 20, 0));
	EXPECT_EQ(-1.0f, Commission(20, 20, 91));
	// sales <= 1000
	EXPECT_EQ(10.0f, Commission(1, 1, 1));
	// sales > 1000 && sales <= 1800
	EXPECT_EQ(121.75f, Commission(1, 20, 20));
	// sales > 1800
	EXPECT_EQ(260.0f, Commission(20, 20, 20));
}

TEST(CommissionTest, C2_Coverage) {
	// Just the same as C0 and C1 since there is no loop.
	// terminated
	EXPECT_EQ(0.0f, Commission(-1, 20, 20));
	// invalid
	EXPECT_EQ(-1.0f, Commission(0, 20, 20));
	EXPECT_EQ(-1.0f, Commission(71, 20, 20));
	EXPECT_EQ(-1.0f, Commission(20, 0, 20));
	EXPECT_EQ(-1.0f, Commission(20, 81, 20));
	EXPECT_EQ(-1.0f, Commission(20, 20, 0));
	EXPECT_EQ(-1.0f, Commission(20, 20, 91));
	// sales <= 1000
	EXPECT_EQ(10.0f, Commission(1, 1, 1));
	// sales > 1000 && sales <= 1800
	EXPECT_EQ(121.75f, Commission(1, 20, 20));
	// sales > 1800
	EXPECT_EQ(260.0f, Commission(20, 20, 20));
}

TEST(CommissionTest, MCDC_Coverage) {
	// Just the same as C1 since all conditions are considered.
	// terminated
	EXPECT_EQ(0.0f, Commission(-1, 20, 20));
	// invalid
	EXPECT_EQ(-1.0f, Commission(0, 20, 20));	// TF FF FF
	EXPECT_EQ(-1.0f, Commission(71, 20, 20));	// FT FF FF
	EXPECT_EQ(-1.0f, Commission(20, 0, 20));	// FF TF FF
	EXPECT_EQ(-1.0f, Commission(20, 81, 20));	// FF FT FF
	EXPECT_EQ(-1.0f, Commission(20, 20, 0));	// FF FF TF
	EXPECT_EQ(-1.0f, Commission(20, 20, 91));	// FF FF FT
	// sales <= 1000
	EXPECT_EQ(10.0f, Commission(1, 1, 1));
	// sales > 1000 && sales <= 1800
	EXPECT_EQ(121.75f, Commission(1, 20, 20));
	// sales > 1800
	EXPECT_EQ(260.0f, Commission(20, 20, 20));
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
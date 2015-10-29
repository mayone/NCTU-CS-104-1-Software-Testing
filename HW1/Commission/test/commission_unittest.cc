#include "commission.h"
#include "gtest/gtest.h"


// Robust Boundary Value Testing
TEST(CommissionTest, BoundaryValue_Robust) {
	// Tests locks
	EXPECT_EQ(-1.0f, Commission(-2, 20, 20));
	EXPECT_EQ(0.0f, Commission(-1, 20, 20));
	EXPECT_EQ(-1.0f, Commission(0, 20, 20));
	EXPECT_EQ(121.75f, Commission(1, 20, 20));
	EXPECT_EQ(128.5f, Commission(2, 20, 20));
	EXPECT_EQ(260.0f, Commission(20, 20, 20));
	EXPECT_EQ(701.0f, Commission(69, 20, 20));
	EXPECT_EQ(710.0f, Commission(70, 20, 20));
	EXPECT_EQ(-1.0f, Commission(71, 20, 20));
	// Tests stocks 
	EXPECT_EQ(-1.0f, Commission(20, 0, 20));
	EXPECT_EQ(164.5f, Commission(20, 1, 20));
	EXPECT_EQ(169.0f, Commission(20, 2, 20));
	EXPECT_EQ(614.0f, Commission(20, 79, 20));
	EXPECT_EQ(620.0f, Commission(20, 80, 20));
	EXPECT_EQ(-1.0f, Commission(20, 81, 20));
	// Tests barrels
	EXPECT_EQ(-1.0f, Commission(20, 20, 0));
	EXPECT_EQ(178.75f, Commission(20, 20, 1));
	EXPECT_EQ(182.5f, Commission(20, 20, 2));
	EXPECT_EQ(605.0f, Commission(20, 20, 89));
	EXPECT_EQ(610.0f, Commission(20, 20, 90));
	EXPECT_EQ(-1.0f, Commission(20, 20, 91));
}

// Equivalence Class Testing
//TEST(CommissionTest, EquivalenceClass_WeakNormal) {}
//TEST(CommissionTest, EquivalenceClass_WeakRobust) {}
//TEST(CommissionTest, EquivalenceClass_StrongRobust) {}

// Edge Testing
//TEST(CommissionTest, Edge_WeakNormal) {}

// Decision Table-Based Testing
//TEST(CommissionTest, DecisionTable) {}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
#include "commission.h"
#include "gtest/gtest.h"


// Robust Boundary Value Testing
TEST(TriangleTest, BoundaryValue_Robust) {
}

// Equivalence Class Testing
TEST(TriangleTest, EquivalenceClass_WeakNormal) {
}
TEST(TriangleTest, EquivalenceClass_WeakRobust) {
}
TEST(TriangleTest, EquivalenceClass_StrongRobust) {
}

// Edge Testing
TEST(TriangleTest, Edge_WeakNormal) {
}

// Decision Table-Based Testing
TEST(TriangleTest, DecisionTable) {
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
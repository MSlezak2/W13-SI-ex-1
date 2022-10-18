#pragma once
#include <gtest/gtest.h>
#include "../HistogramLibrary/Range.h"

namespace RangeTest
{
	// Example, feel free to modify
	struct RangeTest : public ::testing::Test {
		RangeTest() {
			range1 = new Range(1, 5);
		}

		~RangeTest()
		{
			delete range1;
		}

		Range* range1;
	};

	TEST_F(RangeTest, FromLesserThan0) {
		EXPECT_THROW(Range(-1,5), std::exception);
	}

	TEST_F(RangeTest, FromGreaterThanTo) {
		EXPECT_THROW(Range(5, 1), std::exception);
	}

	TEST_F(RangeTest, WordLengthInRange) {
		std::string testString = "test";
		EXPECT_TRUE(range1->isInRange(testString));
	}

	TEST_F(RangeTest, WordLengthEqualsFrom) {
		std::string testString = "t";
		EXPECT_TRUE(range1->isInRange(testString));
	}

	TEST_F(RangeTest, WordLengthEqualsTo) {
		std::string testString = "test1";
		EXPECT_TRUE(range1->isInRange(testString));
	}

	TEST_F(RangeTest, WordLengthOutOfRange) {
		std::string testString = "test11";
		EXPECT_FALSE(range1->isInRange(testString));
	}

	TEST_F(RangeTest, RangeToString) {
		EXPECT_EQ(range1->toString(), "1 - 5");
	}

	int main(int argc, char* argv[]) {
		testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	}
}


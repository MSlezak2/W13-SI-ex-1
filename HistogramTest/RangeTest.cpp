#pragma once
#include <gtest/gtest.h>
#include "../HistogramLibrary/Range.h"

namespace RangeTest
{
	// Example, feel free to modify
	struct RangeTestF : public ::testing::Test {
		RangeTestF() {
			range1 = new Range(1, 2);
		}

		~RangeTestF()
		{
			delete range1;
		}

		Range* range1;
	};


	TEST_F(RangeTestF, TestRangeToString) {
		// Example, feel free to modify
		EXPECT_EQ(range1->toString(), "1 - 2");

	}

	int main(int argc, char* argv[]) {
		testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	}
}


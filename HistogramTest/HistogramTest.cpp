#pragma once
#include <gtest/gtest.h>
#include <stdexcept>
#include "../HistogramLibrary/Histogram.h"

namespace HistogramTest 
{
	class HistogramTest : public ::testing::Test {
	protected:
		Histogram histogram;
		std::vector<Range> ranges = histogram.generateRanges(2,3);
	};

	TEST_F(HistogramTest, GenerateRangesPositiveArguments) {
		std::vector<Range> targetHistogram = { Range(1,2), Range(3,4) };
			
		std::vector<Range> generatedHistogram = histogram.generateRanges(2, 2);

		EXPECT_EQ(generatedHistogram, targetHistogram);
	}

	TEST_F(HistogramTest, GenerateRangesNegativeStep) {
		EXPECT_THROW(histogram.generateRanges(-2, 2) , std::invalid_argument);
	}

	TEST_F(HistogramTest, GenerateRangesNegativeAmount) {
		EXPECT_THROW(histogram.generateRanges(2, -2), std::invalid_argument);
	}

	TEST_F(HistogramTest, GenerateWordsWithinRanges) {
		std::string text = "A BCD EFGHI";
		std::map<Range, int> generatedHistogram = histogram.generate(text,ranges);

		std::map<Range, int> targetHistogram = { {Range(1,2), 1},{Range(3,4), 1}, {Range(5,6), 1} };

		EXPECT_EQ(generatedHistogram, targetHistogram);
	}

	TEST_F(HistogramTest, GenerateWordsOutOfRanges) {
		std::string text = "A BCD EFGHI JKLMNOU";
	
		EXPECT_ANY_THROW(histogram.generate(text, ranges));
	}

	TEST_F(HistogramTest, GenerateEmptyText) {
		std::string text = "";

		std::map<Range, int> generatedHistogram = histogram.generate(text, ranges);

		EXPECT_EQ(generatedHistogram.size(), 0);
	}

	TEST_F(HistogramTest, EmptyHistogram) {
		EXPECT_EQ(histogram.draw(), "");
	}
}
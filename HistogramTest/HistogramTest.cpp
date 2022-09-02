#pragma once
#include <gtest/gtest.h>
#include "../HistogramLibrary/Histogram.h"

namespace HistogramTest 
{
	TEST(HistogramTest, TestNameHistogram) {
		// Example, feel free to modify
		Histogram histogram = Histogram();
		EXPECT_EQ(histogram.draw(), "");
	}
}
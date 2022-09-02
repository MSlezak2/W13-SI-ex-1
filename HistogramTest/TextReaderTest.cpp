#pragma once
#include <gtest/gtest.h>
#include "../HistogramLibrary/TextReader.h"
#include <sstream>

namespace TextReaderTests
{
	class TextReaderTest : public ::testing::Test {
	protected:
		std::string dirWithTestFilesPath{
			"C:\\Academy\\Programs\\Module 2 - ALGORITHMS\\SI - week 13\\ex-1\\histogram-cpp-starter-main\\Histogram\\"
		}; // TODO: Use relational path instead

		std::string getLineNumberN(std::stringstream& ss, int lineNumber) {
			std::string line{};
			for (int i = 0; i < lineNumber; i++) {
				std::getline(ss, line);
			}
			return line;
		}

		std::string getLastLine(std::stringstream& ss) {
			std::string line{};
			while (std::getline(ss, line)) {}
			return line;
		}

	};

	TEST_F(TextReaderTest, ReadEmptyFile) {
		// Example, feel free to modify
		std::string fileName = dirWithTestFilesPath + "empty.txt";
		TextReader textReader(fileName);

		std::string readString = textReader.read();

		EXPECT_TRUE(readString.empty());
	}

	TEST_F(TextReaderTest, ReadRegularFile) {
		// Example, feel free to modify
		std::string fileName = dirWithTestFilesPath + "test.txt";
		TextReader textReader(fileName);

		std::string readString = textReader.read();
		std::string expectedString = "Harry Potter and the Sorcerer's Stone";

		EXPECT_EQ(readString, expectedString);
	}

	TEST_F(TextReaderTest, ReadLargeFile) {
		// Example, feel free to modify
		std::string fileName = dirWithTestFilesPath + "text.txt";
		TextReader textReader(fileName);

		std::string wholeText = textReader.read();
		std::stringstream ss(wholeText);
		std::string string1;
		std::getline(ss, string1);
		std::string string2 = TextReaderTest::getLineNumberN(ss, 19);
		std::string string3 = TextReaderTest::getLastLine(ss);

		std::string expectedString1 = "SORTING HAT SONG"; //first line
		std::string expectedString2 = "So kind Helga Hufflepuff would teach all the rest"; //middle line
		std::string expectedString3 = "Unite all the houses and we'll fight as one."; //last line

		EXPECT_EQ(string1, expectedString1);
		EXPECT_EQ(string2, expectedString2);
		EXPECT_EQ(string3, expectedString3);
	}
}
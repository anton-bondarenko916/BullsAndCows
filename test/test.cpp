#include "src/functions.h"
#include <gtest/gtest.h>

using namespace std;

int number, randomNumber, bulls, cows, numOfMoves = 0, result;
string a;

TEST(TestLogic1, TestTrue1){
	bulls = 0;
	cows = 0;
	number = 1234;
	randomNumber = 1234;
	logic(number, randomNumber, bulls, cows, numOfMoves);
	ASSERT_TRUE(bulls == 4);
}

TEST(TestLogic2, TestTrue2){
	bulls = 0;
	number = 1235;
	randomNumber = 1234;
	logic(number, randomNumber, bulls, cows, numOfMoves);
	ASSERT_TRUE(bulls == 3);
}

TEST(TestLogic3, TestTrue3){
	cows = 0;
	number = 6425;
	randomNumber = 1234;
	logic(number, randomNumber, bulls, cows, numOfMoves);
	ASSERT_TRUE(cows == 2);
}

TEST(TestLogic4, TestTrue4){
	cows = 0;
	number = 3421;
	randomNumber = 1234;
	logic(number, randomNumber, bulls, cows, numOfMoves);
	ASSERT_TRUE(cows == 4);
}

TEST(TestLogic5, TestResult1){
	bulls = 0;
	number = 2345;
	randomNumber = 1234;
	result = logic(number, randomNumber, bulls, cows, numOfMoves);
	ASSERT_TRUE(result == 0);
}

TEST(TestLogic6, TestResult2){
	bulls = 0;
	number = 1234;
	randomNumber = 1234;
	result = logic(number, randomNumber, bulls, cows, numOfMoves);
	ASSERT_TRUE(result == 2);
}

TEST(TestLogic7, TestResult3){
	bulls = 0;
	number = 1243256345;
	randomNumber = 1234;
	result = logic(number, randomNumber, bulls, cows, numOfMoves);
	ASSERT_TRUE(result == 1);
}

TEST(TestCreate, Test){
	result = create();
	ASSERT_GT(result, 1000);
}

TEST(TestToInt, Test1){
	a = "1234";
	input = 1234;
	result = toInt(a);
	ASSERT_EQ(input, result);
}

TEST(TestToInt, Test2){
	a = "asddc";
	input = 0;
	result = toInt(a);
	ASSERT_EQ(input, result);
}

int test(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

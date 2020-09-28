#include "testing.hpp"
#include "../src/functions.h"

struct TestCreateRand: TestCase {
  void run(){
    int b;
    b = create();
    ASSERT_RELATION(b, >, 1000);
    ASSERT_RELATION(b, <, 10000);
  }
};

struct TestLogicFourBulls: TestCase {
  void run(){
    int b, bulls, cows, count;
    b = logic(2222, 2222, bulls, cows, count);
    ASSERT_EQUAL(b, 2);
    ASSERT_EQUAL(bulls, 4);
  }
};

struct TestLogicTwoBulls: TestCase {
  void run(){
    int b, bulls, cows, count;
    b = logic(8796, 8722, bulls, cows, count);
    ASSERT_EQUAL(b, 0);
    ASSERT_EQUAL(bulls, 2);
    ASSERT_EQUAL(cows, 0);
  }
};

struct TestLogicError: TestCase {
  void run(){
    int b, bulls, cows, count;
    b = logic(0, 2222, bulls, cows, count);
    ASSERT_EQUAL(b, 1);
    ASSERT_EQUAL(bulls, 0);
    ASSERT_EQUAL(cows, 0);
  }
};

struct TestLogicNG: TestCase {
  void run(){
    int b, bulls, cows, count;
    b = logic(8796, 2222, bulls, cows, count);
    ASSERT_EQUAL(b, 0);
    ASSERT_EQUAL(bulls, 0);
    ASSERT_EQUAL(cows, 0);
  }
};

struct TestLogicTwoCows: TestCase {
  void run(){
    int b, bulls, cows, count;
    b = logic(8796, 9622, bulls, cows, count);
    ASSERT_EQUAL(b, 0);
    ASSERT_EQUAL(bulls, 0);
    ASSERT_EQUAL(cows, 2);
  }
};

struct TestLogicFourCows: TestCase {
  void run(){
    int b, bulls, cows, count;
    b = logic(8796, 7869, bulls, cows, count);
    ASSERT_EQUAL(b, 0);
    ASSERT_EQUAL(bulls, 0);
    ASSERT_EQUAL(cows, 4);
  }
};

REGISTER_TEST(TestCreateRand, "number bigger 1000 and smaller 1000");
REGISTER_TEST(TestLogicFourBulls, "four bulls");
REGISTER_TEST(TestLogicTwoBulls, "two bulls");
REGISTER_TEST(TestLogicError, "fnput error");
REGISTER_TEST(TestLogicNG, "noone guessed");
REGISTER_TEST(TestLogicTwoCows, "two cows");
REGISTER_TEST(TestLogicFourCows, "two cows");



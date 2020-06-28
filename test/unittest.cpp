#include "testing.hpp"

struct testCreateRandom: TestCase {
  
  
  int created = 0, createdCopy = 0;
  int massiv[20] = {
    1234, 8796, 8963, 3024, 4023, 7812, 4697, 1034, 7063, 6378,
    9854, 4560, 7632, 1058, 2075, 3096, 4058, 7965, 4568, 3067,
  };

  void randomize() {
    srand(time(NULL));
    created = rand() % 19 + 0;
    createdCopy = massiv[created];
  }

  int create() {
    randomize();
    return createdCopy;
  }
  
  void run() override {
    
    int b;
    b = create();
    ASSERT_RELATION(b, >, 1000 );
    ASSERT_RELATION(b, <, 10000 );
  }
};

struct testLogic: TestCase {

  int massivEntered[4] = {0, 0, 0, 0}, massivRandom[4] = {0, 0, 0, 0};
  int n = 4, bulls = 0, cows = 0;

  void intToArray(int a, int massiv[4]) {   
	  for (int i = 3; i > -1; i--) {
		  massiv[i] = a % 10;
		  a /= 10;
	  }
  }

  void countBulls(int &bulls) {
  	for (int i = 0; i < 4; i++) {
  		if (massivEntered[i] == massivRandom[i]) {
  			bulls++;
		  }
	  }
  }

  void countCows(int &cows) {
	  for (int i = 0; i < 4; i++) {
		  for (int j = 0; j < 4; j++) {
		    if (massivEntered[i] == massivRandom[j] && i != j) {
			  	cows++;
			  }
		  }
	  }
  }

  int logic(int number, int randomNumber, int &bulls, int &cows, int &numOfMoves) {   
	  bulls = 0;
	  cows = 0;
	  if (number < 1000 || number > 9999) {
		  return 1;
	  } else {
		  intToArray(number, massivEntered);
		  intToArray(randomNumber, massivRandom);
		  countBulls(bulls);
		  countCows(cows);
		  numOfMoves++; 
		  if (bulls == 4) {
			  return 2;
		  } else {
			  return 0;
			}
    }
  }
  
  
  void run() override {
    int number, randomNumber, bulls = 0, cows, nom, b;
    b = logic(1111, 1111, bulls, cows, nom);
    ASSERT_EQUAL(b, 2);
    ASSERT_EQUAL(bulls, 4);
    
    bulls = 0;
    b = logic(0, 4657, bulls, cows, nom);
    ASSERT_EQUAL(b, 1);
    ASSERT_EQUAL(bulls, 0);
    
    cows = 0;
    b = logic(8963, 4657, bulls, cows, nom);
    ASSERT_EQUAL(b, 0);
    ASSERT_EQUAL(cows, 1);
    
    cows = 0;
    b = logic(1111, 4589, bulls, cows, nom);
    ASSERT_EQUAL(b, 0);
    ASSERT_EQUAL(cows, 0);
  }
};

REGISTER_TEST(testCreateRandom, "createRandomNumber");
REGISTER_TEST(testLogic, "testing logic");

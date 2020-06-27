#include "functions.h"





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

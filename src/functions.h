#include "input.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <stdlib.h>
#include <string>

using namespace std;
using namespace sf;

int logic(int number, int randomNumber, int &bulls, int &cows, int &numOfMoves);
void menu();
int create();
void gameMenu(RenderWindow &window);
void won(RenderWindow &window);

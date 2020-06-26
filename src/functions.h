#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <random>
#include <ctime>


using namespace std;
using namespace sf;

int main();
int logic(int number, int randomNumber, int &bulls, int &cows, int &numOfMoves);
int create();
int toInt(string a);
void menu();
void gameMenu(RenderWindow &window);

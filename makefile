CC=g++

CPPFLAGS=-c -Wall -Wextra -Werror -std=c++11

OBJ=createRandomNumber.o gameMenu.o logic.o main.o menu.o won.o

SRC=./src

BIN=./bin

TEST=./test

all : PROG clean

PROG : createRandomNumber gameMenu logic main menu won BullsAndCows clean

createRandomNumber :
	$(CC) $(CPPFLAGS) $(SRC)/createRandomNumber.cpp
	
gameMenu :
	$(CC) $(CPPFLAGS) $(SRC)/gameMenu.cpp
	
logic :
	$(CC) $(CPPFLAGS) $(SRC)/logic.cpp

main :
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp
	
menu :
	$(CC) $(CPPFLAGS) $(SRC)/menu.cpp

won :
	$(CC) $(CPPFLAGS) $(SRC)/won.cpp
	
BullsAndCows :
	$(CC) $(OBJ) -o $(BIN)/bullsandcows -lsfml-graphics -lsfml-window -lsfml-system

Test :
	$(CC) --std=c++11 -c $(TEST)/unittest.cpp
	$(CC) unittest.o -o $(BIN)/test
	rm -rf *.o
	
clean :
	rm -rf *.o













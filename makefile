CC=g++

CPPFLAGS=-c -Wall -Wextra -Werror

OBJ=createRandomNumber.o gameMenu.o logic.o main.o menu.o stringToInt.o won.o

SRC=./src

BIN=./bin

TEST=./test

all : PROG clean

PROG : createRandomNumber gameMenu logic main menu stringToInt won BullsAndCows clean

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
	
stringToInt :
	$(CC) $(CPPFLAGS) $(SRC)/stringToInt.cpp
	
won :
	$(CC) $(CPPFLAGS) $(SRC)/won.cpp
	
BullsAndCows :
	$(CC) $(OBJ) -o $(BIN)/bullsandcows -lsfml-graphics -lsfml-window -lsfml-system

clean :
	rm -rf *.o

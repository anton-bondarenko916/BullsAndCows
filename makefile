.PHONY: clean all test run
CC = g++
CPPFLAGS = -c -Wall -Werror -Wextra  -std=c++11
OBJ = createRandomNumber.o gameMenu.o logic.o main.o menu.o won.o
SRC = ./src
BIN = ./bin
BUILD = ./build
TEST = ./test

all: $(BIN)/bullsandcows

$(BIN)/bullsandcows: $(BUILD)/createRandomNumber.o $(BUILD)/gameMenu.o $(BUILD)/logic.o $(BUILD)/main.o $(BUILD)/menu.o $(BUILD)/won.o 
	$(CC) $(BUILD)/createRandomNumber.o $(BUILD)/gameMenu.o $(BUILD)/logic.o $(BUILD)/main.o $(BUILD)/menu.o $(BUILD)/won.o -o $(BIN)/bullsandcows -lsfml-graphics -lsfml-window -lsfml-system
	
test: $(TEST)/unittest.cpp $(BUILD)/createRandomNumber.o $(BUILD)/logic.o
	g++ -o $(BIN)/testing $(TEST)/unittest.cpp $(BUILD)/createRandomNumber.o $(BUILD)/logic.o
	
$(BUILD)/createRandomNumber.o: $(SRC)/createRandomNumber.cpp
	$(CC) $(CPPFLAGS) $(SRC)/createRandomNumber.cpp -o $(BUILD)/createRandomNumber.o
	
$(BUILD)/gameMenu.o: $(SRC)/gameMenu.cpp
	$(CC) $(CPPFLAGS) $(SRC)/gameMenu.cpp -o $(BUILD)/gameMenu.o
	
$(BUILD)/logic.o: $(SRC)/logic.cpp
	$(CC) $(CPPFLAGS) $(SRC)/logic.cpp -o $(BUILD)/logic.o

$(BUILD)/main.o: $(SRC)/main.cpp
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp -o $(BUILD)/main.o
	
$(BUILD)/menu.o: $(SRC)/menu.cpp
	$(CC) $(CPPFLAGS) $(SRC)/menu.cpp -o $(BUILD)/menu.o

$(BUILD)/won.o: $(SRC)/won.cpp
	$(CC) $(CPPFLAGS) $(SRC)/won.cpp -o $(BUILD)/won.o
	



clean:
	@rm -f build/*.o
	@rm -f bin/bullsandcows
	@rm -f bin/testing
	
run:
	@./bin/bullsandcows
	
runtest:
	./bin/testing


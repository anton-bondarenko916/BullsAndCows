#ifndef __INPUT_H__
#define __INPUT_H__

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace sf;

class Input {

public:
  Input(int size) {
    input1.setCharacterSize(size);
    input1.setFillColor(Color::Black);
    input1.setString("_");
  }

  void setFont(Font &fonts) { input1.setFont(fonts); }

  void setPosition(Vector2f point) { input1.setPosition(point); }

  void output(RenderWindow &window) { window.draw(input1); }

  void enteringNumber(Event input) {
    int enteredNumber = input.text.unicode;
    if ((enteredNumber > 47 && enteredNumber < 58) || enteredNumber == 8) {
      count = fourDigit.str().length();
      if (count <= clamp) {
        enteringLogic(enteredNumber);
      } else if (count > clamp && enteredNumber == 8) {
        deletingNumber();
      }
    }
  }

  void outputText(string &a) { a = number; }

private:
  Text input1;
  ostringstream fourDigit;
  int clamp = 3;
  string number;
  int count = 0;
  int countCurrent = 0;

  void deletingNumber() {
    string currentText = fourDigit.str();
    string newText = "";
    countCurrent = currentText.length() - 1;
    for (int i = 0; i < countCurrent; i++) {
      newText += currentText[i];
    }
    fourDigit.str("");
    fourDigit << newText;
    input1.setString(fourDigit.str() + "_");
  }

  void enteringLogic(int enteredNumber) {
    if (enteredNumber != 8) {
      fourDigit << static_cast<char>(enteredNumber);
    } else if (enteredNumber == 8) {
      if (count > 0) {
        deletingNumber();
      }
    }
    input1.setString(fourDigit.str() + "_");
    number = fourDigit.str();
  }
};
#endif

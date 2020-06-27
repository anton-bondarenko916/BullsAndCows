#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace sf;

class Input {

public:
  Input(int size, Color color) {
    input1.setCharacterSize(size);
	  input1.setFillColor(color);
	  input1.setString("_");
  }
	    
  void setFont(Font &fonts) { input1.setFont(fonts); }

  void setPosition(Vector2f point) { input1.setPosition(point); }
		   
  void output(RenderWindow &window) { window.draw(input1); }
		    
	void enteringNumber(Event input) {
    int enteredNumber = input.text.unicode;
		if ((enteredNumber > 47 && enteredNumber < 58) || enteredNumber == 8) {
		  if (fourDigit.str().length() <= clamp) {
			  enteringLogic(enteredNumber);
			} else if (fourDigit.str().length() > clamp && enteredNumber == 8) {
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

	void deletingNumber() {
	  string currentText = fourDigit.str();
	  string newText = "";
	  for (int i = 0; i < currentText.length() - 1; i++) {
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
      if (fourDigit.str().length() > 0) {
			  deletingNumber();
			}
    }
		input1.setString(fourDigit.str() + "_");
		number = fourDigit.str();
  }
};

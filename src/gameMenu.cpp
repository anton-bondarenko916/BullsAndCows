#include "functions.h"


void gameMenu(RenderWindow &window) 
{
    bool pressed = false;
    string enter;
    int number, randomNumber, bulls = 0, cows = 0, numOfMoves = 0, result;
    string bullsString, cowsString;
    

    Texture buttonOk, buttonExitTexture, bgTexture;
    bgTexture.loadFromFile("../images/fon2.png");
    buttonOk.loadFromFile("../images/okButton.png");
    buttonExitTexture.loadFromFile("../images/buttonexit.png");

    Sprite bgSprite(bgTexture), buttonOkSprite(buttonOk);
    Sprite buttonExitSprite(buttonExitTexture);
    bgSprite.setPosition(0, 0);
    buttonOkSprite.setPosition(620,43);
    buttonExitSprite.setPosition(875, 425);
    
    Font arial;
    arial.loadFromFile("../fonts/arial.ttf");
    
    Text text("", arial, 48), text1("Number of moves: ", arial, 25);
    Text enterText("Enter 4-digit number:", arial, 25);
    Text bullsText("BULLS:", arial, 30), cowsText("COWS:", arial, 30);
    Text enteredText("Entered number: ", arial, 30);
    Text numberOfBullsText("0", arial, 48), numberOfCowsText("0", arial, 48);
    
    numberOfCowsText.setFillColor(Color::Black);
    numberOfCowsText.setPosition(940, 175);
    numberOfCowsText.setStyle(Text::Bold);
    
    numberOfBullsText.setFillColor(Color::Black);
    numberOfBullsText.setPosition(50, 175);
    numberOfBullsText.setStyle(Text::Bold);
    
    enteredText.setFillColor(Color::Black);
    enteredText.setPosition(435, 150);
    enteredText.setStyle(Text::Bold);
    
    cowsText.setFillColor(Color::Black);
    cowsText.setPosition(900, 125);
    cowsText.setStyle(Text::Bold);
    
    bullsText.setFillColor(Color::Black);
    bullsText.setPosition(10, 125);
    bullsText.setStyle(Text::Bold);
    
    enterText.setFillColor(Color::Black);
    enterText.setPosition(425, 0);
    enterText.setStyle(Text::Bold);
    
    text1.setFillColor(Color::Black);
    text1.setPosition(450, 450);
    text1.setStyle(Text::Bold);
    
    text.setFillColor(Color::Black);
    text.setStyle(Text::Bold);
    text.setPosition(500, 200);
    
    Input input1(24, Color::Black);
    input1.setFont(arial);
    input1.setPosition({510, 55});
    
    
    randomNumber = create();
    


    while (window.isOpen()) {
        buttonOkSprite.setColor(Color::White);
        buttonExitSprite.setColor(Color::White);
        if (IntRect(620, 43, 53, 53).contains(Mouse::getPosition(window))) {
            buttonOkSprite.setColor(Color::Green);
        }
        if (IntRect(875, 425, 130, 47).contains(Mouse::getPosition(window))) {
            buttonExitSprite.setColor(Color::Red);
        }
    
    
    

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::TextEntered) {
                input1.enteringNumber(event); 
            }
            if (event.type == Event::MouseButtonReleased) {
                if (event.mouseButton.button == Mouse::Left) {
                    if (IntRect(620, 43, 53, 53).contains(Mouse::getPosition(window))) {
                        result = 0;
                        input1.outputText(enter);
                        text.setString(enter);          
                        number = toInt(enter);
                        result = logic(number, randomNumber, bulls, cows, numOfMoves);
                        switch (result) 
                        {   
                            case 0:
                                text.setString(enter);
                                break;
                            case 1:
                                text.setString("*error*");
                                break; 
                            case 2:
                                won(window);
                                break;
                        }
                        bullsString = to_string(bulls);
                        numberOfBullsText.setString(bullsString);
                        cowsString = to_string(cows);
                        numberOfCowsText.setString(cowsString);
                        text1.setString("Number of moves: " + to_string(numOfMoves));
                         
                   } if (IntRect(875, 425, 130, 47).contains(Mouse::getPosition(window))) {
                        window.close();
                    } 
                 } 
            }
    
    
            window.clear();
            window.draw(bgSprite);
            window.draw(buttonOkSprite);
            window.draw(text);
            window.draw(text1);
            window.draw(enterText);
            window.draw(bullsText);
            window.draw(cowsText);
            window.draw(enteredText);
            window.draw(numberOfBullsText);
            window.draw(numberOfCowsText);
            window.draw(buttonExitSprite);
            input1.output(window);
            window.display();
        }
  }
}

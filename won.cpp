#include "functions.h"



void won(RenderWindow &window) 
{
    Texture bg3Texture, buttonRepeatTexture, buttonExitTexture;
    bg3Texture.loadFromFile("images/fon3.png");
    buttonRepeatTexture.loadFromFile("images/buttonRepeat.png");
    buttonExitTexture.loadFromFile("images/buttonexit.png");
    
    Sprite bg3Sprite(bg3Texture), buttonRepeatSprite(buttonRepeatTexture);
    Sprite buttonExitSprite(buttonExitTexture);
    bg3Sprite.setPosition(0, 0);
    buttonRepeatSprite.setPosition(485, 250);
    buttonExitSprite.setPosition(485, 310);
    
    while (window.isOpen()) {
        buttonRepeatSprite.setColor(Color::White);
        buttonExitSprite.setColor(Color::White);
        if (IntRect(485, 250, 130, 47).contains(Mouse::getPosition(window))) {
            buttonRepeatSprite.setColor(Color::Green);
        }
        if (IntRect(485, 310, 130, 47).contains(Mouse::getPosition(window))) {
            buttonExitSprite.setColor(Color::Red);
        }
        
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            } if (event.type == Event::MouseButtonReleased) {
                if (event.mouseButton.button == Mouse::Left) {
                    if (IntRect(485, 250, 130, 47).contains(Mouse::getPosition(window))) {
                        gameMenu(window);                         
                    } if (IntRect(485, 310, 130, 47).contains(Mouse::getPosition(window))) {
                        window.close();
                    } 
                 } 
            }
           
        }
            window.clear();
            window.draw(bg3Sprite);
            window.draw(buttonRepeatSprite);
            window.draw(buttonExitSprite);
            window.display();
    
    }
}

#include "functions.h"

using namespace sf;

void menu() {
    
  RenderWindow window(sf::VideoMode(1024, 500), "Bulls And Cows");
    
  int position = 0;
    
  Texture bgTexture, buttonPlay, buttonExit;
  bgTexture.loadFromFile("../images/fon.jpg");
  buttonPlay.loadFromFile("../images/buttonplay.png");
  buttonExit.loadFromFile("../images/buttonexit.png");

  Sprite bgSprite(bgTexture), buttonPlaySprite(buttonPlay),
  Sprite buttonExitSprite(buttonExit);
  bgSprite.setPosition(0, 0);
  buttonPlaySprite.setPosition(475, 300);
  buttonExitSprite.setPosition(475, 375);

  while (window.isOpen()) {
    position = 0;
    buttonPlaySprite.setColor(Color::White);
    buttonExitSprite.setColor(Color::White);
    if (IntRect(475, 300, 130, 47).contains(Mouse::getPosition(window))) {
      buttonPlaySprite.setColor(Color::Yellow);
      position = 1;
    }
    if (IntRect(475, 375, 130, 47).contains(Mouse::getPosition(window))) {
      buttonExitSprite.setColor(Color::Yellow);
      position = 2;
    }
    if (Mouse::isButtonPressed(Mouse::Left)) {
      if (position == 1) {
        gameMenu(window);
      }
      if (position == 2)
        window.close();
    }

    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
      window.clear();
      window.draw(bgSprite);
      window.draw(buttonPlaySprite);
      window.draw(buttonExitSprite);
      window.display();
    }
  }
}

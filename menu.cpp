#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;

void menu()
{
    
    RenderWindow window(sf::VideoMode(1024, 500), "Bulls And Cows");
    
    Texture bgTexture, buttonPlay, buttonExit;
    bgTexture.loadFromFile("images/fon.jpg");
    buttonPlay.loadFromFile("images/buttonplay.png");
    buttonExit.loadFromFile("images/buttonexit.png");

    Sprite bgSprite(bgTexture), buttonPlaySprite(buttonPlay),
    buttonExitSprite(buttonExit);
    bgSprite.setPosition(0, 0);
    buttonPlaySprite.setPosition(475, 300);
    buttonExitSprite.setPosition(475, 375);
  
  

    while (window.isOpen()) 
    {
        buttonPlaySprite.setColor(Color::White);
        buttonExitSprite.setColor(Color::White);  
          
        Event event;
        while (window.pollEvent(event)) 
        {
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

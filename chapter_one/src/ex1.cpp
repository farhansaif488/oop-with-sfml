#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640,480),"SFML APPLICAION");
    sf::CircleShape shape;
    
    shape.setRedius(40,f);
    shape.setPosition(100.f,100.f);
    shape.setFillColor(sf::Color::Cyan);
    
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.Close();
            }
            window.clear();
            window.draw(shape);
            window.display();
        }
    }
}
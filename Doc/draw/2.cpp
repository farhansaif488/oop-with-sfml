#include <SFML/Graphics.hpp>

int main()
{
    //create the window
    sf::RenderWindow window(sf::VideoMode(800,600),"Game window",sf::Style::Default);


    //shape declarartion

    sf::CircleShape shape(100.f,100,500);
    shape.setFillColor(sf::Color::Green);

    //run the code as long as the window is open
    while(window.isOpen())
    {
        //check all the windows event that were triggred since the last iteration of the loop.
        sf::Event event;
        while(window.pollEvent(event))
        {
            //close requested event: we close the window
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }


        //clear the window with black color 

        window.clear(sf::Color::Black);
        window.draw(shape);
        window.display();
    }
}
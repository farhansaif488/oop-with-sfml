#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600),"Thas saif",sf::Style::Default);

    window.setPosition(sf::Vector2i(10,50));//position the window with respect to desktop
    window.setTitle("Saif Made a window!");
    //window.setKeyRepeatEnabled(); 	
    //doesnt work

    while(window.isOpen())
    {
        //check all the windows events that
        //were triggered since the last iteration
        //of the loop

        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if(event.type == sf::Event::KeyPressed)
            {
                std::cout<<"KeyPressed"<<std::endl;
            }
            if (event.type == sf::Event::Resized)
            {
                std::cout << "new width: " << event.size.width << std::endl;
                std::cout << "new height: " << event.size.height << std::endl;
            }
            window.clear();
            window.display();
        }
    }


    return 0;
}
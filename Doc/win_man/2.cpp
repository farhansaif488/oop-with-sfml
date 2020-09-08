//Events

//remember sf::Event is a union,which means it shares the same memory space 
//with otehr members of its class

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

        while(window.pollEvent(event))//pollevent is a function which can produce valid events
        {
            if(event.type == sf::Event::Closed ||(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                window.close();
            }
            /*if(event.type == sf::Event::KeyPressed)
            {
                std::cout<<"KeyPressed"<<std::endl;
            }*/
            else if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Space)
                {
                    std::cout << "the Space key was pressed"<<std::endl;
                    std::cout << "control :"<< event.key.control <<std::endl;
                    std::cout << "alt:"<< event.key.alt<<std::endl;
                    std::cout << "shift:"<< event.key.shift <<std::endl;
                    std::cout << "system"<< event.key.system <<std::endl;
                }
            }

            //Resizing the window and showing on console
            if (event.type == sf::Event::Resized)
            {
                std::cout << "new width: " << event.size.width << std::endl;
                std::cout << "new height: " << event.size.height << std::endl;
            }

            //text enetring and showing on console
            if(event.type == sf::Event::TextEntered)
            {
                if(event.text.unicode <128)
                {
                    std::cout<<"ASCII character typed   :   "<<static_cast<char>(event.text.unicode)<<std::endl;
                }
            }
          
        }
        window.clear();
        window.display();
    }


    return 0;
}
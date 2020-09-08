//Graphics
//minimal api documentation
//author : Farhan Saif
//date : 8th spet;2020

//goal :: our aim is to create modular code from the
//        existing code of previous folder "win_man"
//        
// functions will be:
//                
//  create_window();
//  window_loop();
//  event_loop();
//  and a class for making an object from those 3
//  then we will approach graphics

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

void xwindow(int x,int y,int rx,int ry,string s)
{
    sf::RenderWindow window(sf::VideoMode(x,y),s,sf::Style::Default);

    window.setPosition(sf::Vector2i(rx,ry));//position the window with respect to desktop
    //window.setKeyRepeatEnabled(); 	
    //doesnt work


    //checking a graphics undr keyboard control
    sf::CircleShape shape(100.f);
   shape.setFillColor(sf::Color::Green);
    
    
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
                /*if(event.key.code == sf::Keyboard::Space)
                {
                    std::cout << "the Space key was pressed"<<std::endl;
                    std::cout << "control :"<< event.key.control <<std::endl;
                    std::cout << "alt:"<< event.key.alt<<std::endl;
                    std::cout << "shift:"<< event.key.shift <<std::endl;
                    std::cout << "system"<< event.key.system <<std::endl;
                }*/
                if(event.key.code == sf::Keyboard::Space)
                {
                    //sf::CircleShape shape(100.f);
                    //shape.setFillColor(sf::Color::Green);
                    window.clear();
                    
                    window.display();
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
        window.draw(shape);
        window.display();
    }

}

int main()
{
    for(auto i=0;i<3;i++)
    {
        xwindow(800,500,400,500,"Title");
    }
}









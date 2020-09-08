#include <SFML/Graphics.hpp>


   sf::CircleShape create_object()
    {
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Red);
        return shape;
    }

class A{
    public:

    void create_window(int f)
    {
         //create the window
    sf::RenderWindow window(sf::VideoMode(800,600),"Game window",sf::Style::Default);


    //shape declarartion
    
    sf::CircleShape shape;
    if(f==1) shape = create_object();

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

        window.clear(sf::Color::Yellow);
       // create_object(window);
        if(f==1)window.draw(shape);
        window.display();
    }

    }
};


int main()
{
   A obj;
   obj.create_window(1);
}
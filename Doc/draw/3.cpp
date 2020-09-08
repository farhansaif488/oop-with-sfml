#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    //window for rendering 

    sf::RenderWindow window(sf::VideoMode(800,600),"Texture Experiments",sf::Style::Default);

    //create a new render-texture

    sf::Texture texture;
    sf::CircleShape  shape(100.f);
    shape.setFillColor(sf::Color::Yellow);
    if (!texture.loadFromFile("kwomi.jpg", sf::IntRect(10, 10, 32, 32)))
    {
        return -1;
    }

    //the window loop

    while(window.isOpen())
    {
        //Event Processing
        //..
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        //Clear the whole texture with redd color
       // texture.clear(sf::Color::Red);
        //Draw stuff to the texture
        texture.draw(shape);
        //here,we are done drawing the texture
        texture.display();
        //now ,start rendering it to the window
        window.clear();
        //Draw the texture
        //Bring the texture with sprite
        sf::Sprite sprite(texture.getTexture());
        window.draw(sprite);
        //End the current frame and display its content on screen;
        window.display();
    }
    
}
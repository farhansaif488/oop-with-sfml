#include "../include/Game.h"

Game::Game():mWindow(sf::VideoMode(640,480),"SFML APPLICATION",sf::Style::Default)
,mPlayer(){
        mPlayer.setRadius(40.f);
        mPlayer.setPosition(100.f,100.f);
        mPlayer.setFillColor(sf::Color::Cyan);
    }


void Game::processEvents()
{
    //code
    sf::Event event;

    while(mWindow.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            mWindow.close();
        }
        
    }
}

void Game::update()
{
    //code
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}

void Game::run()
{
    while(mWindow.isOpen())
    {
        processEvents();
        update();
        render();
    }
}
int main()
{
    Game game;
    game.run();
}
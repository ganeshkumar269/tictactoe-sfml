#include <SFML/Graphics.hpp>
#include <time.h>
#include "tictactoe.cpp"
int main(){
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(300,300),"TicTacToe",sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape rs(sf::Vector2f(100,100));
    sf::RectangleShape x(sf::Vector2f(70,70));
    sf::CircleShape    o(35);
    sf::Texture textureForX;
    textureForX.loadFromFile("resources/letterX.png");
    x.setTexture(&textureForX);
    x.setFillColor(sf::Color::White);
    o.setFillColor(sf::Color::Black);
    x.setOutlineColor(sf::Color::White);
    o.setOutlineColor(sf::Color::White);
    x.setOutlineThickness(-3.0f);
    o.setOutlineThickness(-3.0f);
    rs.setFillColor(sf::Color::Black);
    rs.setOutlineColor(sf::Color::White);
    rs.setOutlineThickness(-3.0f);
    sf::Vector2i mousePos(0,0);
    x.setPosition(sf::Vector2f(-100,100));
    o.setPosition(sf::Vector2f(-100,100));
    int arr[3][3]={0};
    float deltaTime=0, delayTime=3;
    sf::Clock clock;
    while(window.isOpen()){
        deltaTime = clock.restart().asSeconds();
        delayTime+=deltaTime;
        sf::Event evnt;
        while(window.pollEvent(evnt)){
            switch(evnt.type){
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                    window.close();
            }
        }
        if(delayTime > 2.0){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                delayTime=0;
                mousePos = sf::Mouse::getPosition(window);
                mousePos.x/=100;
                mousePos.y/=100;
                int i=mousePos.y;
                int j=mousePos.x;
                arr[i][j]=-1;
                std::cout<<"Your Move: ("<<i<<","<<j<<")"<<std::endl;
                prettyprint(arr);
                if(gameOver(arr))
                    break;
                if(isFull(arr)){
                    std::cout<<"Woah , It's a tie!"<<std::endl;
                    break;
                }
                int r=returnOptimal(arr);
                i=r/3;
                j=r%3;
                arr[i][j]=1;
                std::cout<<"Computer Move: ("<<i<<","<<j<<")"<<std::endl;
                prettyprint(arr);
                if(gameOver(arr))
                    break;
            }
        }
        window.clear();

        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            rs.setOutlineColor(sf::Color::White);
            if(i==mousePos.x && j == mousePos.y)
                rs.setOutlineColor(sf::Color::Cyan);
            rs.setPosition(sf::Vector2f((float)i*100,(float)j*100));
            window.draw(rs);
            if(arr[j][i] == -1){
                x.setPosition(sf::Vector2f((float)(i*100+15),(float)(j*100+15)));
                window.draw(x);
            }
            else if(arr[j][i] == 1){
                o.setPosition(sf::Vector2f((float)(i*100+15),(float)(j*100+15)));
                window.draw(o);
            }
        }
        window.display();

    }
}

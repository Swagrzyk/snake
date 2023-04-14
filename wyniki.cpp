#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "wyniki.h"
using namespace std;
using namespace sf;
int* score_top10(int bw);

void wynikix(int w)
{
	RenderWindow okno(VideoMode(800, 600, 32), "Najlepsze 10 wynikow");
    sf::RectangleShape rectangle( sf::Vector2f( 780, 580) ); // tworzymy prostok¹t
    rectangle.setPosition( 10, 10);
    rectangle.setOutlineColor( Color::Black );
    rectangle.setOutlineThickness( 2 );
    Texture texture;
    if(!texture.loadFromFile("../grafika/snakex.jpg") ) {
        std::cout<<"nie wczytano grafiki "<<std::endl;
    }
    rectangle.setTexture( & texture );

okno.draw(rectangle);
    int * wyn;
    wyn = score_top10(w);
    Font f;
    f.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");

    Text txt[10];

    for (int i = 0; i < 10; i++)
    {
        txt[i].setString(" "+to_string(i+1) + ". " + to_string(wyn[i]));
        txt[i].setCharacterSize(20);
        if ((wyn[10] - 1) == i)
            txt[i].setFillColor(Color::Red);
        else
            txt[i].setFillColor(Color::White);
        txt[i].setFont(f);
        txt[i].setPosition(4, i * 30 + 10);
        okno.draw(txt[i]);

    }

    while (okno.isOpen())
    {

        sf::Event zd;
        while (okno.pollEvent(zd))

        {
            if (zd.type == Event::Closed)

                okno.close();
        }
        okno.display();



    }

}
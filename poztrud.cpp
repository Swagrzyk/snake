#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "poztrud.h"

using namespace sf;
using namespace std;

int poztrudx()
{
	RenderWindow okno(VideoMode(800, 600, 32), "Wybor poziomu trudnosci");
	Font f;
	f.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");
	Text t;
    Text x;
    Text u;
    Text z;
    /// ramka
    sf::RectangleShape rectangle( sf::Vector2f( 780, 580) ); // tworzymy prostok¹t
    rectangle.setPosition( 10, 10);
    rectangle.setOutlineColor( Color::Black );
    rectangle.setOutlineThickness( 2 );
    Texture texture;
    if(!texture.loadFromFile("../grafika/sanke.jpg") ) {
       std::cout<<"nie wczytano grafiki "<<std::endl;
    }
    rectangle.setTexture( & texture );
///info
    x.setFont(f);
    x.setCharacterSize(15);
    x.setString("Latwy- poziom pierwszy z 1  przeszkoda ");
    x.setPosition( 20, 500 );
    x.setFillColor(sf::Color::Black);
    x.setOutlineColor(Color::White );
    x.setOutlineThickness(1.5);
    x.setLetterSpacing(1.5);
    //
    z.setFont(f);
    z.setCharacterSize(15);
    z.setString("Sredni- poziom drugi z 2  przeszkodami ");
    z.setPosition( 20, 520 );
    z.setFillColor(sf::Color::Black);
    z.setOutlineColor(Color::White );
    z.setOutlineThickness(1.5);
    z.setLetterSpacing(1.5);
    //
    u.setFont(f);
    u.setCharacterSize(15);
    u.setString("Trudny- poziom trzeci z 3  przeszkodami ");
    u.setPosition( 20, 540 );
    u.setFillColor(sf::Color::Black);
    u.setOutlineColor(Color::White );
    u.setOutlineThickness(1.5);
    u.setLetterSpacing(1.5);
    ///
    t.setFont(f);
    t.setCharacterSize(60);
    t.setString("Snake");
    t.setPosition( 300, 4 );

    t.setFillColor(sf::Color::Black);
    t.setOutlineColor(sf::Color::White);
    t.setOutlineThickness(10);
    t.setLetterSpacing(2);
    t.setOutlineColor(sf::Color::Blue);
    t.setOutlineThickness(2);
    t.setLetterSpacing(1.5);
///pozycjonowanie
	Text poz[3];
	poz[0].setString("Latwy");
	poz[0].setFillColor(Color::White);
    poz[0].setOutlineColor(Color::White);
    poz[0].setOutlineThickness(3);
    poz[0].setLetterSpacing(1.5);
	poz[0].setFont(f);
	poz[0].setPosition(350, 134);
	poz[0].setCharacterSize(30);

	poz[1].setString("Sredni");
	poz[1].setFillColor(Color::White);
    poz[1].setOutlineColor(Color::White);
    poz[1].setOutlineThickness(3);
    poz[1].setLetterSpacing(1.5);
	poz[1].setFont(f);
	poz[1].setPosition(350, 184);
	poz[1].setCharacterSize(30);

	poz[2].setString("Trudny");
	poz[2].setFillColor(Color::White);
    poz[2].setOutlineColor(Color::White);
    poz[2].setOutlineThickness(3);
    poz[2].setLetterSpacing(1.5);
	poz[2].setFont(f);
	poz[2].setPosition(350, 234);
	poz[2].setCharacterSize(30);
    ///myszka
	while (okno.isOpen())
	{
		okno.clear();
		if (Mouse::getPosition(okno).y > 132 && Mouse::getPosition(okno).y < 174 && Mouse::getPosition(okno).x < 440 && Mouse::getPosition(okno).x > 340)
		{
			poz[0].setFillColor(Color::Red);
		}
		else
		{
            poz[0].setFillColor(Color::Black);;
		}
		if (Mouse::getPosition(okno).y > 182 && Mouse::getPosition(okno).y < 224 && Mouse::getPosition(okno).x < 460 && Mouse::getPosition(okno).x > 340)
		{
			poz[1].setFillColor(Color::Red);
		}
		else
		{
            poz[1].setFillColor(Color::Black);;
		}
		if (Mouse::getPosition(okno).y > 232 && Mouse::getPosition(okno).y < 284 && Mouse::getPosition(okno).x < 460 && Mouse::getPosition(okno).x > 340)
		{
			poz[2].setFillColor(Color::Red);
		}
		else
		{
            poz[2].setFillColor(Color::Black);
		}

        okno.draw( rectangle );
        okno.draw(t);
        okno.draw(x);
        okno.draw(u);
        okno.draw(z);

		okno.draw(poz[0]);
		okno.draw(poz[1]);
		okno.draw(poz[2]);
		sf::Event zd;
		while (okno.pollEvent(zd))
		{
			if (zd.type == Event::Closed)
			{
				okno.close();
				return 0;
			}

			if (zd.type == Event::MouseButtonPressed && zd.mouseButton.button == Mouse::Left)
			{
				if (Mouse::getPosition(okno).y > 132 && Mouse::getPosition(okno).y < 174 && Mouse::getPosition(okno).x < 560 && Mouse::getPosition(okno).x > 245)
				{
					okno.close();
					return 1;
				}
				if (Mouse::getPosition(okno).y > 182 && Mouse::getPosition(okno).y < 224 && Mouse::getPosition(okno).x < 720 && Mouse::getPosition(okno).x > 245)
				{
					okno.close();
					return 2;
				}
				if (Mouse::getPosition(okno).y > 232 && Mouse::getPosition(okno).y < 284 && Mouse::getPosition(okno).x < 780 && Mouse::getPosition(okno).x > 245)
				{
					okno.close();
					return 3;
				}
			}
		}

		okno.display();
	}
}
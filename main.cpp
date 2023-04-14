
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include "klasy.h"
#include "poztrud.h"
#include "wyniki.h"
#include "scoretop10.h"

using namespace std;
using namespace sf;

int* score_top10x(int bw);
void wynikix(int w);
int poztrudx();


void debug_display(RenderWindow * rw, Waz w, Obiekty ob, int lev )
{
    sf::RectangleShape rectangle( sf::Vector2f( 600, 596) ); // tworzymy prostok¹t

    rectangle.setPosition( 2, 2);
    rectangle.setFillColor(sf::Color::Green);

    rectangle.setOutlineColor( Color::White );
    rectangle.setOutlineThickness( 2 );
    sf::RectangleShape xyz( sf::Vector2f( 600, 596) ); // tworzymy prostok¹t

    xyz.setPosition( 602, 2);
    xyz.setFillColor(sf::Color::Red);

    xyz.setOutlineColor( Color::White );
    xyz.setOutlineThickness( 2 );
    sf::RectangleShape xyzz( sf::Vector2f( 600, 66) ); // tworzymy prostok¹t

    xyzz.setPosition( 602, 2);
    xyzz.setFillColor(sf::Color::Red);

    xyzz.setOutlineColor( Color::White );
    xyzz.setOutlineThickness( 2 );
    RectangleShape waz;


    rw->clear();
    rw->draw(rectangle);
    rw->draw(xyz);
    rw->draw(xyzz);
    waz.setSize({ 6,6 });
    waz.setFillColor(Color::Red);
    int d = w.getDl();
    XY * xy = w.getPoz();
    for (int i = 0; i < d; i++)
    {
        waz.setPosition(xy[i].x * 6, xy[i].y * 6);
        rw->draw(waz);
    }
    waz.setFillColor(Color::White);
    waz.setPosition(ob.jedzenie.x * 6, ob.jedzenie.y * 6);
    rw->draw(waz);
    waz.setFillColor(Color::Blue);
    for (int i = 0; i <= 2; i++)
    {
        waz.setPosition(ob.przeszkody[i].x * 6, ob.przeszkody[i].y * 6);
        rw->draw(waz);
    }




    Font f;
    f.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");
    Text txt;
    txt.setString("Punkty: " + to_string(w.getDl() - 1));
    txt.setFillColor(sf::Color::Blue);
    txt.setCharacterSize(20);
    txt.setFont(f);
    txt.setPosition(650, 20);
    rw->draw(txt);

}


bool update(Waz* w, Obiekty* ob, int lev)
{
    srand(time(0));
    if (w->czyzje(*ob))
    {
        w->moveWhenEat();
        los:
        ob->jedzenie.x = rand() % 100;
        ob->jedzenie.y = rand() % 100;
        for (int i = 0; i <= 2; i++)
        {
            if (ob->jedzenie.x == ob->przeszkody[i].x && ob->jedzenie.y == ob->przeszkody[i].y) goto los; // Zapobieganie wylosowaniu jedzenia w miejscu przeszkód
        }
    }
    else w->move();
    if (w->koniecGry(*ob))
    {
        return false;
    }
    return true;
}

int main()
{
	Waz waz;
    Obiekty obj;
    srand(time(0));
	int level = poztrudx();
    do
    {
        obj.przeszkody[0].x = rand() % 100;
        obj.przeszkody[0].y = rand() % 100;
    } while (obj.przeszkody[0].y == 50);
    if (level > 1)
        do
        {
            obj.przeszkody[1].x = rand() % 100;
            obj.przeszkody[1].y = rand() % 100;
        } while (obj.przeszkody[1].y == 50);
    if (level > 2)
        do
        {
            obj.przeszkody[2].x = rand() % 100;
            obj.przeszkody[2].y = rand() % 100;
        } while (obj.przeszkody[2].y == 50);
	RenderWindow okno(VideoMode(800, 600, 32), "Gra Snake");
    while (okno.isOpen())

    {
        sf::Event zd;

        while (okno.pollEvent(zd))
        {
            if (zd.type == Event::Closed)
                okno.close();
            if (zd.type == Event::KeyPressed && zd.key.code == Keyboard::W)
                waz.turn(Kierunek::UP);
            else if (zd.type == Event::KeyPressed && zd.key.code == Keyboard::A)
                waz.turn(Kierunek::LEFT);
            else if (zd.type == Event::KeyPressed && zd.key.code == Keyboard::D)
                waz.turn(Kierunek::RIGHT);
            else if (zd.type == Event::KeyPressed && zd.key.code == Keyboard::S)
                waz.turn(Kierunek::DOWN);
        }

        if (update(&waz, &obj, level))
        {
            okno.close();
           wynikix(waz.getDl() - 1);
        }

        debug_display(&okno, waz, obj, level);

        okno.display();

        if (level == 1)
            Sleep(50);
        else if (level == 2)
            Sleep(30);
        else Sleep(20);

    }

}
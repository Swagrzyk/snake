#include "klasy.h"
Waz::Waz()
{
	poz = new XY[1];
	poz[0] = { 50, 50 };
	kier = Kierunek::LEFT;
	dl = 1;
}
void Waz::turn(Kierunek k)
{
	if (kier == Kierunek::DOWN && k == Kierunek::UP) return;
	if (kier == Kierunek::UP && k == Kierunek::DOWN) return;
	if (kier == Kierunek::LEFT && k == Kierunek::RIGHT) return;
	if (kier == Kierunek::RIGHT && k == Kierunek::LEFT) return;
	kier = k;
}

void Waz::move()
{
	for (int i = (dl - 1); i >= 0; i--)
	{
		poz[i + 1].x = poz[i].x;
		poz[i + 1].y = poz[i].y;
	}
	if (kier == Kierunek::DOWN)
	{
		poz[0].y += 1;
		if (poz[0].y > 99) poz[0].y = 0;
	}
	else if (kier == Kierunek::UP)
	{
		poz[0].y -= 1;
		if (poz[0].y < 0) poz[0].y = 99;
	}
	else if (kier == Kierunek::LEFT)
	{
		poz[0].x -= 1;
		if (poz[0].x < 0) poz[0].x = 99;
	}
	else if (kier == Kierunek::RIGHT)
	{
		poz[0].x += 1;
		if (poz[0].x > 99) poz[0].x = 0;
	}
}
void Waz::moveWhenEat()
{
	dl++;
	XY* nowapoz = new XY[dl*2];
	for (int i = 1; i < dl; i++)
	{
		nowapoz[i].x = poz[i - 1].x;
		nowapoz[i].y = poz[i - 1].y;
	}
	if (kier == Kierunek::DOWN)
	{
		nowapoz[0].x = nowapoz[1].x;
		if (nowapoz[1].y >= 99) nowapoz[0].y = 0;
		else nowapoz[0].y = nowapoz[1].y + 1;
	}
	else if (kier == Kierunek::UP)
	{
		nowapoz[0].x = nowapoz[1].x;
		if (nowapoz[1].y <= 0) nowapoz[0].y = 99;
		else nowapoz[0].y = nowapoz[1].y - 1;
	}
	else if (kier == Kierunek::LEFT)
	{
		nowapoz[0].y = nowapoz[1].y;
		if (nowapoz[1].x <= 0) nowapoz[0].x = 99;
		else nowapoz[0].x = nowapoz[1].x - 1;
	}
	else if (kier == Kierunek::RIGHT)
	{
		nowapoz[0].y = nowapoz[1].y;
		if (nowapoz[1].x >= 99) nowapoz[0].x = 0;
		else nowapoz[0].x = nowapoz[1].x + 1;
	}
	poz = nowapoz;
}

bool Waz::koniecGry(Obiekty o)
{
	if (poz[0].x == o.przeszkody[0].x && poz[0].y == o.przeszkody[0].y)
		return false;
	if (poz[0].x == o.przeszkody[1].x && poz[0].y == o.przeszkody[1].y)
		return false;
	if (poz[0].x == o.przeszkody[2].x && poz[0].y == o.przeszkody[2].y)
		return false;
	for (int i = 1; i < dl; i++)
	{
		if (poz[0].x == poz[i].x && poz[0].y == poz[i].y)
		{
			return false;
		}
	}
}

bool Waz::czyzje(Obiekty o)
{
	XY next = poz[0];
	if (kier == Kierunek::DOWN)
	{
		next.y += 1;
		if (next.y > 99) next.y = 0;
	}
	else if (kier == Kierunek::UP)
	{
		next.y -= 1;
		if (next.y < 0) next.y = 99;
	}
	else if (kier == Kierunek::LEFT)
	{
		next.x -= 1;
		if (next.x < 0) next.x = 99;
	}
	else if (kier == Kierunek::RIGHT)
	{
		next.x += 1;
		if (next.x > 99) next.x = 0;
	}
	if (next.x == o.jedzenie.x && next.y == o.jedzenie.y)
		return true;
	return false;
}

Obiekty::Obiekty()
{
	przeszkody[0] = { -1, -1 };
	przeszkody[1] = { -1, -1 };
	przeszkody[2] = { -1, -1 };
	jedzenie = { 75, 75 };
}
#ifndef SNAKE__KLASY_H
#define SNAKE__KLASY_H
struct XY
{
	int x; int y;
};
enum class Kierunek {UP, DOWN, LEFT, RIGHT};

class Obiekty
{
public:
	XY przeszkody[3];
	XY jedzenie;
	Obiekty();
};

class Waz
{
public:
    int* score_top10(int bw);
	Waz();
	void turn(Kierunek k);
	void move();
	void moveWhenEat();
	inline XY* getPoz()
	{
		return poz;
	}
	inline int getDl()
	{
		return dl;
	}
	bool koniecGry(Obiekty o);
	bool czyzje(Obiekty o);

private:
	XY* poz;
	int dl;
	Kierunek kier;
};
#endif //SNAKE__KLASY_H
#include <fstream>
#include "scoretop10.h"
using namespace std;

int* score_top10(int bw)
{
	static int wyniki[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
	ifstream input("wyniki.info");
	for (int i = 0; i < 10; i++)
		input >> wyniki[i];
	for (int j = 0; j < 10; j++)
	{
		if (wyniki[j] < bw)
		{
			for (int k = 9; k > j; k--)
			{
				wyniki[k] = wyniki[k - 1];
			}
			wyniki[j] = bw;
			wyniki[10] = j + 1;
			break;
		}
	}
	input.close();
	ofstream output("wyniki.info", ofstream::trunc);
	for (int i = 0; i < 10; i++)
		output << wyniki[i] << '\n';
	output.close();
	return wyniki;
}
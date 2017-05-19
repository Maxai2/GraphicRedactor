#include <iostream>
#include <Windows.h>
#include "Functions.h"

using namespace std;

HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	while (abs(menu(0)) % 2 == 0)
	{
		color();
		symbols();

		draw();
	}

	SetConsoleCursorPosition(hand, { 0, 23 });
	cout << "Bye!)" << endl;
}
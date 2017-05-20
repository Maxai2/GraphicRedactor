#include <iostream>
#include <Windows.h>
#include <math.h>
#include <conio.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void color()
{
	SetConsoleCursorPosition(h, { 12, 0 });
	cout << "Colors: ";
	for (int i = 1; i < 16; i++)
	{
		SetConsoleTextAttribute(h, i);
		cout << i << " ";
	}
}

void symbols()
{
	SetConsoleCursorPosition(h, { 0, 3 });
	SetConsoleTextAttribute(h, 7);
	cout << "Symbols:";
	short row = 5;
	for (int i = 34; i <= 126; i++)
	{
		if (i == 34 || i == 36 || 40 <= i && i <= 43 || 45 <= i && i <= 47)
		{
			SetConsoleCursorPosition(h, { 2, row });
			cout << char(i) << endl;
			row++;
		}
		else if (i == 60 || i == 62 || i == 64 || i == 92 || i == 94 || i == 95 || i == 124 || i == 126)
		{
			SetConsoleCursorPosition(h, { 2, row });
			cout << char(i) << endl;
			row++;
		}
	}
}

int menu(int sel)
{
	int key;

	while (true)
	{
		for (short i = 0; i < 3; i++)
		{
			SetConsoleCursorPosition(h, { 0, i });

			for (int j = 0; j < 5; j++)
			{
				cout << " ";
			}
		}

		SetConsoleCursorPosition(h, { 0, 0 });

		if (abs(sel) % 2 == 0)
			SetConsoleTextAttribute(h, 10);
		cout << "New\n";

		SetConsoleTextAttribute(h, 7);
		if (abs(sel) % 2 == 1)
			SetConsoleTextAttribute(h, 10);
		cout << "Exit";
		SetConsoleTextAttribute(h, 7);

		key = getch();
		if (key == 0)
			key = getch();

		if (key == 72) // Up
			sel--;
		else if (key == 80) // Down
			sel++;
		else if (key == 13)
			return sel;
	}
}

void clear()
{
	for (short i = 0; i < 3; i++)
	{
		SetConsoleCursorPosition(h, { 0, i });

		for (int j = 0; j < 5; j++)
		{
			cout << " ";
		}
	}

	for (short i = 4; i < 22; i++)
	{
		SetConsoleCursorPosition(h, { 13, i });

		for (int j = 13; j < 60; j++)
		{
			cout << " ";
		}
	}
}

void frame()
{
	short rowS = 3, rowF = 22, colS = 12, colF = 61;

	for (short i = rowS; i < rowF; i++)
	{
		SetConsoleCursorPosition(h, { colS, i });

		for (short j = colS; j < colF; j++)
		{
			if (i == rowS || i == rowF - 1)
				cout << char(178);
			else if (rowS + 1 <= i && i <= rowF - 2 && (j == colS || j == colF - 1))
			{
				SetConsoleCursorPosition(h, { j, i });
				cout << char(178);
			}
		}
	}
}

int cColor()
{
	SetConsoleCursorPosition(h, { 20, 1 });
	int col;

	for (int i = 20; i < 46; i++)
		cout << " ";

	SetConsoleCursorPosition(h, { 20, 1 });
	SetConsoleTextAttribute(h, 7);
	cout << "Input number of color: ";
	cin >> col;

	return col;
}

char cSymbol()
{
	int key, sel = 0;
	short row = 5;
	int sym[17] = { 34, 36, 40, 41, 42, 43, 45, 46, 47, 60, 62, 64, 92, 94, 95, 124, 126 };

	while (true)
	{
		symbols();

		SetConsoleCursorPosition(h, { 2, row });

		if (sym[sel] % 2 == 0)
		{
			SetConsoleTextAttribute(h, 4);
			cout << char(sym[sel]);
		}

		SetConsoleCursorPosition(h, { 2, row });

		SetConsoleTextAttribute(h, 7);
		if (sym[sel] % 2 == 1)
		{
			SetConsoleTextAttribute(h, 4);
			cout << char(sym[sel]);
		}
		SetConsoleTextAttribute(h, 7);

		key = getch();
		if (key == 0)
			key = getch();

		if (key == 72 && row >= 6) // Up
		{
			sel--;
			row--;
		}
		else if (key == 80 && row <= 20) // Down
		{
			sel++;
			row++;
		}
		else if (key == 13)
			return sym[sel];
	}
}

short dRow, dCol;

void press()
{
	SetConsoleCursorPosition(h, { 63, 3 });
	cout << "Press to: ";
	SetConsoleCursorPosition(h, { 63, 4 });
	cout << "c - color";
	SetConsoleCursorPosition(h, { 63, 5 });
	cout << "s - symbol";
	SetConsoleCursorPosition(h, { 63, 6 });
	cout << "enter - select";
	SetConsoleCursorPosition(h, { 63, 7 });
	cout << "l - line";
	SetConsoleCursorPosition(h, { 63, 8 });
	cout << "q - square";
	SetConsoleCursorPosition(h, { 63, 9 });
	cout << "t - triangle";
	SetConsoleCursorPosition(h, { 63, 10 });
	cout << "space - input";
	SetConsoleCursorPosition(h, { 63, 11 });
	cout << "backspace - erase";
	SetConsoleCursorPosition(h, { 63, 12 });
	cout << "esc - menu";
}

void menuClr()
{
	for (short i = 2; i < 15; i++)
	{
		SetConsoleCursorPosition(h, { 63, i });
		cout << "\t\t\t\t";
	}
}

void clrUpMenu()
{
	for (short i = 14; i < 67; i++)
	{
		SetConsoleCursorPosition(h, { i, 2 });

		cout << " ";
	}
}

void line(short row, short col, int color, int symbol)
{
	int key = 0, dot = 0;
	short sRow = 0, sCol = 0, fRow = 0, fCol = 0;

	menuClr();

	while (true)
	{
		while (dot != 2)
		{
			if (dot == 0)
			{
				SetConsoleCursorPosition(h, { 14, 2 });
				cout << "Select the start of the line";
			}
			else
			{
				SetConsoleCursorPosition(h, { 14, 2 });
				cout << "Select the finish of the line";
			}

			SetConsoleCursorPosition(h, { col, row });

			key = getch();
			if (key == 0)
				key = getch();

			if (key == 72 && row > 4) // Up
				row--;
			else if (key == 80 && row < 20) // Down
				row++;
			else if (key == 75 && col > 13) // Left
				col--;
			else if (key == 77 && col < 59) // Right
				col++;
			else if (key == 32) // enter 13 space 32
			{
				SetConsoleTextAttribute(h, color);
				//putch(cSymbol());
				cout << char(symbol);
				if (dot == 0)
				{
					sRow = row; sCol = col;
				}
				else
				{
					fRow = row; fCol = col;
				}

				if (dot == 1)
				{
					if (sRow == fRow)
					{
						SetConsoleCursorPosition(h, { col, sRow });

						if (sCol <= fCol)
						{
							for (short j = sCol; j <= fCol; j++)
							{
								SetConsoleCursorPosition(h, { j, row });
								cout << char(symbol);
							}
						}
						else if (sCol >= fCol)
						{
							for (short j = fCol; j <= sCol; j++)
							{
								SetConsoleCursorPosition(h, { j, row });
								cout << char(symbol);
							}
						}
					}
					else if (sCol == fCol)
					{
						SetConsoleCursorPosition(h, { sCol, row });

						if (sRow <= fRow)
						{
							for (short j = sRow; j <= fRow; j++)
							{
								SetConsoleCursorPosition(h, { col, j });
								cout << char(symbol);
							}
						}
						else if (sRow >= fRow)
						{
							for (short j = fRow; j <= sRow; j++)
							{
								SetConsoleCursorPosition(h, { col, j });
								cout << char(symbol);
							}
						}
					}

					dot++;
				}
				else
					dot++;
			}
			else if (key == 27) // esc
				break;
		}

		for (short i = 14; i < 44; i++)
		{
			SetConsoleCursorPosition(h, { i, 2 });

			cout << " ";
		}

		char ans;
		SetConsoleCursorPosition(h, { 14, 2 });
		cout << "One more?(y/n): ";
		cin >> ans;

		if (ans == 'n')
			break;
		else
			dot = 0;
	}

	dRow = row;
	dCol = col;

	clrUpMenu();
}

void square(short row, short col, int color, int symbol)
{
	menuClr();

	int width = 0, length = 0, key;
	bool done = false;

	while (true)
	{
		SetConsoleCursorPosition(h, { 14, 2 });
		cout << "Input the upper left coordinate of the square";

		SetConsoleCursorPosition(h, { col, row });

		key = getch();
		if (key == 0)
			key = getch();

		if (key == 72 && row > 4) // Up
			row--;
		else if (key == 80 && row < 20) // Down
			row++;
		else if (key == 75 && col > 13) // Left
			col--;
		else if (key == 77 && col < 59) // Right
			col++;
		else if (key == 32) // enter 13 space 32
		{
			clrUpMenu();

			SetConsoleTextAttribute(h, 7);
			SetConsoleCursorPosition(h, { 14, 2 });
			cout << "Input width: ";
			cin >> width;
			SetConsoleCursorPosition(h, { 30, 2 });
			cout << "length: ";
			cin >> length;

			width--; length--;

			SetConsoleTextAttribute(h, color);
			for (short i = row; i <= row + width; i++)
			{
				SetConsoleCursorPosition(h, { col, i });

				for (short j = col; j <= col + length; j++)
				{
					if ((i == row || i == row + width) && 4 <= i && i <= 20 && 13 <= j && j <= 59)
					{
						SetConsoleCursorPosition(h, { j, i });

						cout << char(symbol);
					}
					else if (row < i && i < row + width && (j == col || j == col + length) && 4 <= i && i <= 20 && 13 <= j && j <= 59)
					{
						SetConsoleCursorPosition(h, { j, i });

						cout << char(symbol);
					}
				}
			}
			done = true;
		}

		if (done)
		{
			clrUpMenu();

			char ans;
			SetConsoleCursorPosition(h, { 14, 2 });
			cout << "One more?(y/n): ";
			cin >> ans;

			if (ans == 'n')
				break;
			else
				done = false;
		}
	}

	clrUpMenu();
}

void triangle(short row, short col, int color, int symbol)
{
	int key = 0, dir = 0;
	bool done = true;

	while (true)
	{
		menuClr();

		SetConsoleCursorPosition(h, { 65, 3 });
		cout << "^";
		SetConsoleCursorPosition(h, { 65, 4 });
		cout << "|";
		SetConsoleCursorPosition(h, { 63, 5 });
		cout << "<-";
		SetConsoleCursorPosition(h, { 66, 5 });
		cout << "->";
		SetConsoleCursorPosition(h, { 65, 6 });
		cout << "|";
		SetConsoleCursorPosition(h, { 65, 7 });
		cout << "v";

		SetConsoleCursorPosition(h, { 14, 2 });
		cout << "Select the direction of triangle";

		SetConsoleCursorPosition(h, { 65, 5 });

		key = getch();
		if (key == 224)
			key = getch();

		if (key == 72) // Up
			dir = 8;
		else if (key == 80) // Down
			dir = 2;
		else if (key == 75) // Left
			dir = 4;
		else if (key == 77) // Right
			dir = 6;

		menuClr();

		SetConsoleCursorPosition(h, { 63, 5 });
		if (dir == 8)
			cout << "Direction: Up";
		else if (dir == 2)
			cout << "Direction: Down";
		else if (dir == 4)
			cout << "Direction: Left";
		else
			cout << "Direction: Right";

		clrUpMenu();

		SetConsoleCursorPosition(h, { 14, 2 });
		cout << "Input the height of triangle: ";
		short height = 0;
		cin >> height;

		SetConsoleCursorPosition(h, { 63, 6 });
		cout << "Height: " << height;

		clrUpMenu();

		SetConsoleCursorPosition(h, { 14, 2 });
		cout << "Input the coordinate of the triangle top dot";

		SetConsoleTextAttribute(h, color);

		while (done)
		{
			SetConsoleCursorPosition(h, { col, row });
			key = getch();
			if (key == 224)
				key = getch();

			if (key == 72 && row > 4) // Up
				row--;
			else if (key == 80 && row < 20) // Down
				row++;
			else if (key == 75 && col > 13) // Left
				col--;
			else if (key == 77 && col < 59) // Right
				col++;
			else if (key == 32) // enter 13 space 32
			{
				switch (dir)
				{
				case 8:
					for (short i = 0; i < height; i++)
					{
						for (short j = col - i; j <= col + i; j++)
						{
							SetConsoleCursorPosition(h, { j, row + i });

							if (3 < row && row < 17 && 12 < j && j < 60)
								if (i == 0 || i == height - 1 || j == col - i || j == col + i)
									cout << char(symbol);
						}
					}
				break;

				case 2:
					for (short i = 0; i < height; i++)
					{
						for (short j = col - i; j <= col + i; j++)
						{
							SetConsoleCursorPosition(h, { j, row - i });

							if (3 < row && row < 21 && 12 < j && j < 60)
								if (i == 0 || i == height - 1 || j == col - i || j == col + i)
									cout << char(symbol);
						}
					}
				break;

				case 4:
					for (short i = 0; i < height * 2 - 1; i++)
					{
						for (short j = col; j < col + height; j++)
						{
							SetConsoleCursorPosition(h, { j, row - (height - 1) + i });

							if (3 < row && row < 21 && 12 < j && j < 60)
							{
								if (j == col + height - 1 || i == (height * 2 - 1) / 2 && j == col)
									cout << char(symbol);
								else if (0 < i && i < (height * 2 - 1) / 2 && j == col + height - 1 - i)
									cout << char(symbol);
								else if ((height * 2 - 1) / 2 < i && i < height * 2 && j == col + (i - height + 1))
									cout << char(symbol);
							}
						}
					}
				break;

				case 6:
					for (short i = 0; i < height * 2 - 1; i++)
					{
						for (short j = col - height; j <= col; j++)
						{
							SetConsoleCursorPosition(h, { j, row - (height - 1) + i });

							//if (3 < row && row < 21 && 12 < j && j < 60)
							//{
								if (j == col - height || i == row && j == col)
									cout << char(symbol);
/*								else if (0 < i && i < (height * 2 - 1) / 2 && j == col + height - 1 - i)
									cout << char(symbol);
								else if ((height * 2 - 1) / 2 < i && i < height * 2 && j == col + (i - height + 1))
									cout << char(symbol);
							}*/
						}
					}
				break;

				}
				done = false;
			}
		}

		clrUpMenu();

		char ans;
		SetConsoleCursorPosition(h, { 14, 2 });
		cout << "One more?(y/n): ";
		cin >> ans;

		if (ans == 'n')
			break;
		else
			done = true;
	}
}

void draw()
{
	clear();
	frame();
	press();

	short row = 4, col = 13;
	int key, color = 7, symbol = 42;

	while (true)
	{
		SetConsoleCursorPosition(h, { col, row });

		key = getch();
		if (key == 0)
			key = getch();

		if (key == 72 && row > 4) // Up
			row--;
		else if (key == 80 && row < 20) // Down
			row++;
		else if (key == 75 && col > 13) // Left
			col--;
		else if (key == 77 && col < 59) // Right
			col++;
		else if (key == 99) // c
			color = cColor();
		else if (key == 115) // s
			symbol = cSymbol();
		else if (key == 32) // enter 13 space 32
		{
			SetConsoleTextAttribute(h, color);
			//putch(cSymbol());
			cout << char(symbol);
		}
		else if (key == 8) // backspace
			cout << " ";
		else if (key == 108) // l
		{
			line(row, col, color, symbol);

			row = dRow; col = dCol;

			SetConsoleTextAttribute(h, 7);
			press();
		}
		else if (key == 113) // q
		{
			square(row, col, color, symbol);

			SetConsoleTextAttribute(h, 7);
			press();
		}
		else if (key == 116) // t
		{
			triangle(row, col, color, symbol);

			press();
			for (short i = 14; i < 71; i++)
			{
				SetConsoleCursorPosition(h, { i, 2 });
				cout << " ";
			}
		}
		else if (key == 27) // esc
			break;
	}
}
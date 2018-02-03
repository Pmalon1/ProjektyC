#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int polozenieZnacznikaX = 0;
int polozenieZnacznikaY = 0	;
const int ruchGora = 72, ruchDol = 80, ruchLewa = 75, ruchPrawa = 77;

void ksztaltZzadania(int szerokoscFigury, int wysokoscFigury, char znak);
void gotoxy(short polozenieZnacznikaX, short polozenieZnacznikaY);
void HideCursor();

int main() {
	char nawigacja;
	int szerokoscFigury, wysokoscFigury;
	char znak;
	bool warunek = true;
	system("MODE CON COLS=80 LINES=20");
	HideCursor();
	cout << "Witaj w programie rysowania znaku !" << endl;
	cout << "Program powinien umozliwic:" << endl;
	cout << "   - wybor znaku kodu ASCII" << endl;
	cout << "   - wczytanie poczatkowych rozmiarow figury" << endl;
	cout << "   - przesuwanie figury klawiszami" << endl;
	cout << "   - powiekszanie oraz zmniejszanie rozmiaru figury za pomoca klawiszy +/-" << endl;
	cout << "   - ograniczenie przesuwania i rozmiarow figury do obszaru ekranu" << endl;
	cout << endl << endl << endl;
	cout << "\t\t\tNacisnij dowolny klawisz, aby przejsc dalej...";
	_getch();
	system("cls");

	while (true)
	{
		cout << "Podaj szerokosc ksztaltu z zakresu 4 - 20:" << endl;
		cin >> szerokoscFigury;
		if (szerokoscFigury > 20 || szerokoscFigury < 4)
		{
			cout << "Podaj ponownie." << endl;
			continue;
		}
		cout << "Podaj wysokosc ksztaltu z zakresu 4-20: " << endl;
		cin >> wysokoscFigury;
		if (wysokoscFigury > 20 || wysokoscFigury < 4)
		{
			cout << "Podaj ponownie." << endl;
			continue;
		}
		cout << "Podaj znak, ktory posluzy za budulec figury" << endl;
		cin >> znak;
		system("cls");
		gotoxy(polozenieZnacznikaX, polozenieZnacznikaY);
		while (warunek)
		{
			ksztaltZzadania(szerokoscFigury, wysokoscFigury, znak);
			nawigacja = _getch();
			switch (nawigacja)
			{
			case '+':
			{
				if (polozenieZnacznikaY < 0 )
				{
					break;
				}
				if (polozenieZnacznikaY + (wysokoscFigury * 2) + 1 >= 19)
				{
					polozenieZnacznikaY = polozenieZnacznikaY - 2;
					if (polozenieZnacznikaY < 0)
					{
						polozenieZnacznikaY = polozenieZnacznikaY + 2;
						break;
					}
				}
			
				if (polozenieZnacznikaX + szerokoscFigury > 78)
				{
					polozenieZnacznikaX--;
				}
				szerokoscFigury++;
				wysokoscFigury++;
				break;
			}
			case '-':
			{
				if (wysokoscFigury == 4 || szerokoscFigury == 4)
				{
					break;
				}
				szerokoscFigury--;
				wysokoscFigury--;
				break;
			}
			case ruchGora:
			{
				if (polozenieZnacznikaY == 0)
				{
					break;
				}
				polozenieZnacznikaY--;
				break;
			}
			case ruchDol:
			{
				if (polozenieZnacznikaY == 19 - (wysokoscFigury * 2) )
				{
					break;
				}
				polozenieZnacznikaY++;
				break;
			}
			case ruchLewa:
			{
				if (polozenieZnacznikaX == 0)
				{
					break;
				}
				polozenieZnacznikaX--;
				break;
			}
			case ruchPrawa:
			{
				if (polozenieZnacznikaX == 79 - szerokoscFigury)
				{
					break;
				}
				polozenieZnacznikaX++;
				break;
			}
			case 'x':
			{
				warunek = false;
				break;
			}
			}
			system("cls");
		}
	}
}

void gotoxy(short polozenieZnacznikaX, short polozenieZnacznikaY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { polozenieZnacznikaX, polozenieZnacznikaY };

	SetConsoleCursorPosition(hStdout, position);
}
void ksztaltZzadania(int szerokoscFigury, int wysokoscFigury, char znak) {

	for (int i = 0; i <= wysokoscFigury; i++, polozenieZnacznikaX)
	{
		gotoxy(polozenieZnacznikaX + i, polozenieZnacznikaY + i);
		cout << znak;
	}
	for (int i = 0; i <= szerokoscFigury; i++, polozenieZnacznikaY)
	{
		gotoxy(polozenieZnacznikaX + i, polozenieZnacznikaY + 2 * wysokoscFigury - i);
		cout << znak;
	}

}

void HideCursor()
{
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = FALSE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
}


#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "windows.h"



void wstep();
void znak(char &z, int &);
void rysowanie(char &z, int, int, int &);
void poruszanie(int &, int &, int &);
void koniec();

using namespace std;

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int wherex()
{

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.X;
}

int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.Y;
}

void HideCursor()
{
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = FALSE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
}



int main()
{
	char z;
	int x = 38, y = 11, bok;
	wstep();
	znak(z, bok);
	do
	{							
		poruszanie(x, y, bok);
		rysowanie(z, x, y, bok);
	} while (_getch() != 27);
	koniec();
	return 0;
}



void wstep()
{
	system("cls");
	cout << "Witaj w programie rysowania znaku!" << endl;
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

}

void znak(char &z,int &bok)
{
	cout << "Wybierz znak ASCII, ktory posluzy za budulec figury:";
	cin >> z;
	cout << "\nPodaj poczatkowy rozmiar figury (od 5 do 23):";
	cin >> bok;
	while (bok < 5 || bok > 23)
	{
		cout << "\nPodaj prawidlowy rozmiar figury!:"; cin >> bok;
	} 
}

void rysowanie(char &z, int x, int y, int &bok)
{
	
	system("cls");
	int x1 = x; int y1 = y;
	gotoxy(x, y);




	for (int i = x1 - (bok / 2); i <= x1+1; i++, y1++)	
	{
		gotoxy(i, y1 - bok / 2);
		cout << z;
	}


	for (int i = x1; i <= x1 + bok / 2; i++, y1--)
	{
		gotoxy(i-(bok/2), y1 + bok / 2 - (bok/2));
		cout << z;
	}

	gotoxy(3, 24);
	cout <<"Nacisnij ESC, aby wyjsc...    " <<"Dlugosc boku:" << bok<<"    "<<"Wspolrzedne (x,y):"<<x<<"|"<<y;
}


void poruszanie(int &x, int &y, int &bok)
{
	HideCursor();
	char klawisz = _getch();
	int x_l = (x - bok / 2);
	int x_p = (x);
	int y_g = (y - bok / 2);
	int y_d = y;


	switch (klawisz)
	{
	case 75:
	{if(x_l>=1)x--; break; }
	case 77:
	{if (x_p<=76)x++; break; }
	case 72:
	{if (y_g>=1)y--; break; }
	case 80:
	{if (y_d<=(20-(bok/2)))y++; break; }
	case '+': {if ((x_l>=1)&&(x_p<=77)&&(y_g>=1)&& (y_d <= (20 - (bok / 2))))  bok += 2;
		break; }
	case '-':{if (bok>=6) bok -= 2;	
		break; }								 	
	}
}	


void koniec()
{
	system("cls");
	int klawisz;
	gotoxy(0, 10);
	cout << "Jezeli chcesz powtorzyc program, nacisnij klawisz 'P'" << endl;
	cout << "W innym przypadku, nacisnij dowolny klawisz..."<<endl;
	gotoxy(0, 30);
	cout << "Projekt wykonal: Piotr Malon" << endl;
	cout << "Numer indeksu: s16721";
	klawisz=_getch();
	switch (klawisz)
	{
	case 'P': {main(); break; }
	case 'p': {main(); break; }
	}
}

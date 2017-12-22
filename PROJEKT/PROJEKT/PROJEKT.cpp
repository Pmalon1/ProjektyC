
#include "stdafx.h"					//Biblioteki programu
#include <iostream>
#include <conio.h>
#include "windows.h"



void wstep();						//Powiadamiam program o u¿ytych funkcjach 
void znak(char &z, int &);
void rysowanie(char &z, int, int, int &);
void poruszanie(int &, int &, int &);
void koniec();

using namespace std;				//U¿ycie przestrzeni nazw STD

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



int main()						//Funkcja g³ówna programu
{
	char z;						//Zmienna lokalna z
	int x = 38, y = 11, bok;	//Wielkoœci zmiennych x i y odpowiadaj¹ce za punkt pocz¹tkowy programu oraz zmienna dlugosci boku
	wstep();					//Wywolujaca sie funkcja wstep z informacjami na temat programu
	znak(z, bok);				//Funkcja pobierajaca znak oraz dlugosc boku
	do							//Pêtla wykonuj¹ca siê do naciœniêcia klawisza ESC
	{							
		poruszanie(x, y, bok);	//Funkcja ruszania i powiekszania figury
		rysowanie(z, x, y, bok);//Funkcja rysowania figury
	} while (_getch() != 27);
	koniec();					//Funkcja wyswietlajaca autora oraz mozliwoœæ powtórzenia programu
	return 0;
}



void wstep()
{
	system("cls");				//Czyszczenie ekranu na wypadek jego powtórzenia
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
	system("cls");				//Czyszczenie ekranu po wykonaniu funkcji

}

void znak(char &z,int &bok)
{
	cout << "Wybierz znak ASCII, ktory posluzy za budulec figury:";
	cin >> z;					//Pobieranie znaku figury
	cout << "\nPodaj poczatkowy rozmiar figury (od 5 do 23):";
	cin >> bok;					//Pobieranie wymiarów figury
	while (bok < 5 || bok > 23)	//Pêtla sprawdzaj¹ca prawid³owe rozmiary figury
	{
		cout << "\nPodaj prawidlowy rozmiar figury!:"; cin >> bok;
	} 
}

void rysowanie(char &z, int x, int y, int &bok)
{
	
	system("cls");											//Czyszczenie ekranu po wykonaniu funkcji znak
	int x1 = x; int y1 = y;									//Inicjalizacja zmiennych pomocniczych
	gotoxy(x, y);											//Ustawianie wspó³rzêdnych x i y




	for (int i = x1 - (bok / 2); i <= x1+1; i++, y1++)		//Tworzenie lewego boku figury		
	{
		gotoxy(i, y1 - bok / 2);
		cout << z;
	}


	for (int i = x1; i <= x1 + bok / 2; i++, y1--)			//Tworzenie prawego	boku figury
	{
		gotoxy(i-(bok/2), y1 + bok / 2 - (bok/2));
		cout << z;
	}

	gotoxy(3, 24);											//Napis informuj¹cy na dole ekranu
	cout <<"Nacisnij ESC, aby wyjsc...    " <<"Dlugosc boku:" << bok<<"    "<<"Wspolrzedne (x,y):"<<x<<"|"<<y;
}


void poruszanie(int &x, int &y, int &bok)
{
	HideCursor();					//Funkcja ukrywania kursora
	char klawisz = _getch();		//Inicjalizacja klawisza u¿ytego w switchu
	int x_l = (x - bok / 2);		//Zmienne pomocnicze
	int x_p = (x);		//	
	int y_g = (y - bok / 2);		//
	int y_d = y;					//


	switch (klawisz)				//Switch s³u¿¹cy do poruszania i powiêkszania figury
	{
	case 75:						//przesuniêcie w lewo
	{if(x_l>=1)x--; break; }
	case 77:						//przesuniêcie w prawo
	{if (x_p<=76)x++; break; }
	case 72:						//przesuniêcie do góry
	{if (y_g>=1)y--; break; }
	case 80:						//przesuniêcie do do³u
	{if (y_d<=(20-(bok/2)))y++; break; }
	case '+': {if ((x_l>=1)&&(x_p<=77)&&(y_g>=1)&& (y_d <= (20 - (bok / 2))))  bok += 2;	//Powiêkszanie obiektu
		break; }
	case '-':{if (bok>=6) bok -= 2;						//Pomniejszanie obiektu 	
		break; }								 	
	}
}	


void koniec()
{
	system("cls");				//Czyszczenie figury
	int klawisz;				//Zmienna pomocnicza
	gotoxy(0, 10);				//Napis na œrodku ekranu
	cout << "Jezeli chcesz powtorzyc program, nacisnij klawisz 'P'" << endl;
	cout << "W innym przypadku, nacisnij dowolny klawisz..."<<endl;
	gotoxy(0, 30);				//Napis na dole ekranu
	cout << "Projekt wykonal: Piotr Malon" << endl;
	cout << "Numer indeksu: s16721";
	klawisz=_getch();
	switch (klawisz)			//Switch s³u¿¹cy do powtórzenia funkcji g³ównej, czyli ca³ego programu
	{
	case 'P': {main(); break; }
	case 'p': {main(); break; }
	}
}
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#define _USE_MATH_DEFINES


using namespace std;

int main() {
	while (true) {
		int p;
		int q;
		int wygrana;
		int losowosc;


		cout << "Witaj. Prosze o dwukrotne rzucenie kostka w celu ustalenia wygranej.\n";
		cout << "Aby grac losowo wpisz	0, aby wybrac z klawiatury wpisz 1\n";
		cin >> losowosc;
		if (losowosc == 0) {
			srand((unsigned)time(NULL));
			p = (double)rand() / (RAND_MAX) * 6 + 1;
			q = (double)rand() / (RAND_MAX) * 6 + 1;
		}
		else if (losowosc == 1) {
			cout << "Prosze wybrac liczbe z zakresu od 1 do 6 \n";
			while (!(cin >> q) || q < 1 || q > 6) {
				cout << "Podana liczba jest nieprawidlowa. Prosze podac liczbe z zakresu od 1 do 6 \n";
				cin.clear();
				
			}
			cout << "Oto Twoj drugi rzut. Prosze podac liczbe z zakresu od 1 do 6 \n";
			while (!(cin >> p) || p < 1 || p > 6) {
				cout << "Podana liczba jest nieprawidlowa. Prosze podac liczbe z zakresu od 1 do 6 \n";
				cin.clear();
	
			}
		}


		cout << "Oto wynik pierwszego rzutu: " << p << endl;
		cout << "Oto wynik drugiego rzutu: " << q << endl;

		if (p % 2 == 0) {
			if (q == 2 || q == 4 || q == 5) {
				wygrana = p + 3 * q;
				cout << "Wygrana wynosi:" << wygrana << endl;
			}
			else {
				wygrana = 2 * q;
				cout << "Wygrana wynosi: " << wygrana << endl;

			}
		}
		else {
			if (q == 1 || q == 3 || q == 6) {
				if (p == q) {
					wygrana = 5 * p + 3;
					cout << "Wygrana wynosi: " << wygrana << endl;
				}
				else {
					wygrana = 2 * q + p;
					cout << "Wygrana wynosi: " << wygrana << endl;
				}
			}

			else {
				wygrana = min(p, q) + 4;
				if (p == 5 && q == 5) {
					wygrana += 5;
				}
				cout << "Gratuluje! Trafiles dwie 5! Zdobywasz dodatkowe 5 punktow. Calkowita wygrana: " << wygrana << endl;
			}
		}
		cout << "Jesli chcesz zagrac ponownie, wpisz 1. Aby wylaczyc program wpisz 0 \n";
		exit(0);
		system("cls");

	}
	
}

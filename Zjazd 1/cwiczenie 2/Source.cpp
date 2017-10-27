#include <iostream>
#include <conio.h> 
#include <math.h>
using namespace std;
int main() {
	double x;
	double x1;
	double x2;
	double xo;
	double y;
	double y1;
	double y2;
	double a;
	double b;
	double r;
	double delta;
	double pierwiastekdelta;
	cout << "Oto program, ktory okresli polozenie prostej i okregu, oraz poda wspolrzedne ich przeciecia. \n";
	cout << "Rownanie prostej: y = ax + b \n";
	cout << "Rownanie okregu: x^2 + y^2 = r^2 \n";

	cout << "Podaj zmienna a \n";
	cin >> a;
	cout << "Podaj zmienna b \n";
	cin >> b;
	cout << "Podaj promien \n";
	cin >> r;
	delta = 4 * pow (a,2) * pow (r,2) - 4 * pow(b,2) + 4 * pow(r,2);

	if (delta > 0) {
		pierwiastekdelta = sqrt (4 * pow(a, 2) * pow(r, 2) - 4 * pow(b, 2) + 4 * pow(r, 2));
		x1 = (-2 * a*b - pierwiastekdelta) / (2 * pow(a, 2) + 2);
		cout << "x1 = " << x1 << endl;
		x2 = (-2 * a*b + pierwiastekdelta) / (2 * pow(a, 2) + 2);
		cout << "x2 = " << x2 << endl;
		y1 = a * x1 + b;
		cout << "y1 =" << y1 << endl;
		y2 = a * x2 + b;
		cout << "y2 =" << y2 << endl << endl;
		
	}
	if (delta == 0) {
		x = (-2 * a * b) / (pow(a, 2) + 2);
		y = a*x + b;
		cout << "Rozwiazaniem uk³adu jest" << x << endl;
		}
	if (delta < 0) {
		cout << "Brak rozwiazan \n";
	}
	if (r < 0) {
		cout << "Promien nie moze byc mniejszy od zera";
	}
	if (r == 0) {
		cout << "Nieprawidlowa wartosc promienia. Rownanie nie jest okregiem \n";
	}

	system("PAUSE");
	return 0;
} 
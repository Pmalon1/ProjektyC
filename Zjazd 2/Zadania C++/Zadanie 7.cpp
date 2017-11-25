#include <iostream>
#include <conio.h>

using namespace std;

int main() {

	int a;
	int b;
	int nww;
	cout << "Witaj! Jestem programem, ktory obliczy za Ciebie najmniejsza wspolna wielokrotnosc dwoch podanych przez Ciebie liczb calkowitych dodatnich \n";
	cout << "Podaj liczbe a\n";
	cin >> a;
	cout << "Podaj b\n";
	cin >> b;

	if (a > 0 && b > 0) {

		int a1 = a;
		int b1 = b;

		while (a1 != b1) {
			if (a1 > b1) {
				b1 = b1 + b;
			}
			else {
				a1 = a1 + a;
			}
		}
		nww = a1;
	}
	else {
		nww = 0;
	}
	cout << "najwieksza wspolna wielokotnosc podanych przez Ciebie liczb to: \n" << nww << endl;
	system("PAUSE");
	return 0;
}

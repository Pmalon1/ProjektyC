#include <iostream>
#include <conio.h>

using namespace std;

int main() {

	int a;
	int b;
	int nwp;
	cout << "Witaj! Jestem programem, ktory obliczy za Ciebie najwiekszy wspolny podzielnik dwoch podanych przez Ciebie liczb calkowitych dodatnich \n";
	cout << "Podaj liczbe a\n";
	cin >> a;
	cout << "Podaj b\n";
	cin >> b;

	if (a > 0 && b > 0) {

		int a1 = a;
		int b1 = b;

		while (a1 != b1) {
			if (a1 > b1) {
				a1 = a1 - b1;
			}
			else {
				b1 = b1 - a1;
			}
		}
		nwp = a1;
	}
	else {
		cout << "Brak rozwiazan\n";
	}
	cout << "najwiekszy wspolny podzielnik podanych przez Ciebie liczb to: \n" << nwp << endl;
	system("PAUSE");
	return 0;
}

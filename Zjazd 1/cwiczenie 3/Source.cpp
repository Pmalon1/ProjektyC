#define _USE_MATH_DEFINES
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
int main (){
	double promien;
	double katalfa;
	double radianalfa;
	double poleodcinka;
	double F;
	double sinalfa;

	cout << "Oto program, ktory obliczy pole wycinka kola dzieki wybranemu przez Ciebie promieniu, oraz kacie rozwarcia. \n";
	cout << "Prosze podac promien \n";
	while (!(cin >> promien) || promien < 0) {
		cout << "Wprowadzono niewlasciwy znak. Prosze o podanie liczby dodatniej \n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
		cout << "Prosze podac kat rozwarcia \n";
		while (!(cin >> katalfa) || katalfa < 0 || katalfa > 360) {
		cout << "Wprowadzono niewlasciwa wartosc. Maksymalny kat to 360 stopni.  \n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
		radianalfa = (M_PI*katalfa) / (180);
		F = (pow(promien, 2) / 2) * (radianalfa - sin(radianalfa));
		cout << "Pole wycinka wynosi: " << F;
		cout << endl << endl;
		system("PAUSE");
		return 0;
}
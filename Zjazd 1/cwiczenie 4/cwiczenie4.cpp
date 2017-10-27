#include <iostream>
#include <conio.h>
#include <limits>
using namespace std;
int main() {
	double odcinekA;
	double odcinekB;
	double odcinekC;
	cout << "Podaj dlugosc odcinka A \n";
	while (!(cin >> odcinekA) || (odcinekA <= 0)){
	
		cout << "Wprowadzono nieodpowiedni znak. Wprowadz liczbe dodatnia \n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '/n');
	}
	cout << "Podaj dlugosc odcinak B \n";
	while (!(cin >> odcinekB) || (odcinekB <= 0)){
	
		cout << "Wprowadzono nieodpowiedni znak. Wprowadz liczbe dodatnia \n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "Podaj dlugosc odcinak C \n";
	while (!(cin >> odcinekC) || (odcinekC <= 0)){
	
		cout << "Wprowadzono nieodpowiedni znak. Wprowadz liczbe dodatnia \n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if ((odcinekA == odcinekB) && (odcinekC&&odcinekB)){
	cout << "odcinek A i odcinek B sa rowne. \n";

	}
	if ((odcinekA < odcinekB) && (odcinekA < odcinekC)){
		cout << "odcinek A jest najkrotszy. \n" ;
	}
	if ((odcinekB < odcinekA) && (odcinekB < odcinekC)) {
		cout << "odcinek B jest najkrotszy. \n";
	}
	if ((odcinekC < odcinekA) && (odcinekC < odcinekB)) {
		cout << "odcinek C jest najkrotszy. \n";
	}
	system("PAUSE");
		return 0;
	
}
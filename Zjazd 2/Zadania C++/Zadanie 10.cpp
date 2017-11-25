#include <iostream>

using namespace std;

char wybor, kategoria;
int brutto, netto, godziny;

int main() {

	for (;;) {
		cout << "Witam. Jestem programem, ktory obliczy Twoje tygodniowe zarobki zarobki netto i brutto. \n";
		cout << "Prosze wybrac kategorie: ";
		cin >> kategoria;
		cout << "Teraz poprosze o podanie przepracowanych godzin: ";
		cin >> godziny;


		switch (kategoria) {
		case 'a':
			brutto = godziny * 15;
			break;
		case 'b':
			brutto = godziny * 25;
			break;
		case 'c':
			brutto = godziny * 30;
			break;
		case 'd':
			brutto = godziny * 35;
			break;

		default: cout << "Nieprawidlowy wybor. Prosze wybrac podane kategorie. \n";
			break;
		}

		if (brutto <= 700) {
			netto = brutto * 0.85;
		}
		if (700 < brutto <= 1200) {
			netto = brutto * 0.8;
		}
		if (brutto > 1200) {
			netto = brutto * 0.75;
		}
		cout << "Zarobki brutto: " << brutto << endl;
		cout << "Zarobki netto: " << netto << endl;
		cout << "Chcesz obliczyc zarobki jeszcze raz? (y/n)";
		cin >> wybor;
		if (wybor == 'y')
			system("cls");
		else
			break;
	}




}
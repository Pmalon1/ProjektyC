#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	int n;
	int suma = 0;
	

	cout << "Podaj liczbê n\n";
	cin >> n;

		for(int i = 1; i < n + 1; i++) {

			suma = suma + i * i;


		}
		cout << "1 * 1 + 2 * 2 + ... +n * n = " << suma << endl;


		system("PAUSE");
		return 0;
}
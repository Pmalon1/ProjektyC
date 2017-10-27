#include <iostream>
#include <conio.h>

using namespace std;

int main(){
	int n;
	int i = 1;
	
	cout << "Jestem programem, ktory pokaze Ci dzielniki podanej przez Ciebie liczby n\n";
	cout << "Podaj liczbe:\n";
	cin >> n;
	cout << "Dzielniki podanej przez Ciebie liczby to:\n";

		/* Przyklad 1:
		
		for (i; i <= n; i++) {
			if (n%i == 0)
				cout << i << endl;
			i++;
			
		}*/
		
	/* Przyklad 2:
	
	while (i <= n) {
		if (n%i == 0)
			cout << i << endl;
		i++; 
	} */
	do {
		if (n%i == 0)
		cout << i << endl;
		
		i++;
		
	} while (i <= n);
		system("PAUSE");
		return 0; 
}
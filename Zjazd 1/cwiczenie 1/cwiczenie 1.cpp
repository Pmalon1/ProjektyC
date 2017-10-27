#include <iostream>
#include <conio.h> 
using namespace std;
int main()
{
	double a;
	double b;
	double c;
	double d;	
	double e;
	double f;
	double x;
	double y;
	double W;
	double Wy;
	double Wx;

	cout << "Podaj zmienne a, b, c, d" << endl;
	
	cout << "Podaj zmienna a \n";
	cin >> a;
	
	cout << "Podaj zmienna b \n"; 
	cin >> b;
	
	cout << "Podaj zmienna c \n";
	cin >> c;
	
	cout << "Podaj zmienna d \n";
	cin >> d;
	
	cout << "Podaj zmienna e \n";
	cin >> e;

	cout << "Podaj zmienna f\n";
	cin >> f;

	W = a*d - b*c;
	Wx = e*d - f*c;
	Wy = a*f - b*e;
	
	if (W != 0) {
		x = Wx / W;
		y = Wy / W;
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.width(8);
		cout.precision(3);
		cout << "X = " << x << endl;
		cout.width(8);
		cout << "Y = " << y << endl;
		_getch();
	}



		if (W == 0 && Wx == 0 && Wy == 0) {
		
		cout << "Nieskoneczenie wiele rozwiazan" << endl;
	}
	if (W == 0 && Wx != 0) {
		
		cout << "Uklad sprzeczny" << endl;
	
	}
	system("PAUSE");
	return 0;
 }
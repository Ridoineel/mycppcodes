/*
* Programme de conversion celsius -> fahrenheit
* Autheur: OURO-BANG'NA Ridoine
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	// code...
	float fahrenheit;
	float celsius;
	float start_tmp;
	float end_tmp;
	float step;

	cout << " Programme de conversion Cel=>Far" << endl;

	do {
		cout << endl; // saut de ligne

		cout << "Température de début : ";
		cin >> start_tmp;

		cout << "Température de fin   : ";
		cin >> end_tmp;

		cout << "Pas d'avancement     : ";
		cin >> step;

		// saut de ligne
		cout << endl;

		if (start_tmp > end_tmp) {
			cout << "Attention la température de début est inféreure\n";
			cout << "à la température de fin" << endl;
		}
	}while (start_tmp > end_tmp);


	cout << " Celsius => Fahrenheit" << endl;

	// définition la précision de l'affichage 
	// des nombres à deux chiffres après la virgule
	cout << fixed << setprecision(2);

	for (int i=start_tmp; i <= end_tmp; i += step) {
		celsius = i;
		fahrenheit = 9/5*celsius + 32;

		cout << setw(8) << celsius << " => " << setw(10) << fahrenheit << endl;
	}
	
	return 0;
}
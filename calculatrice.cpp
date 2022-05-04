/*
*	Calculatrice
*	@Autheur: OURO-BANG'NA Ridoine
*
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main(int agrc, char * args[]) {
	const int floatPrecision = 2;

	int val1;
	int val2;
	int somme;
	int produit;
	int difference;
	float rapport;

	cout << "Programme Calculatrice" << endl;
	cout << endl;

	cout << "Entrer deux nombres a et b:" << endl;

	cout << "a: ";
	cin >> val1;

	cout << "b: ";
	cin >> val2;

	somme = val1 + val2;
	produit = val1 * val2;
	difference = val1 - val2;
	rapport = float(val1)/val2;

	cout << endl;
	cout << fixed << setprecision(floatPrecision);

	cout << "Somme      = " << setw(10) << somme << endl;
	cout << "Produit    = " << setw(10) << produit << endl;
	cout << "Difference = " << setw(10) << difference << endl;
	cout << "Rapport    = " << setw(10 + floatPrecision + 1) << rapport << endl;

	return 0;
}
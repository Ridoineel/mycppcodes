/*
* Calculatrice simple
* Autheur: OURO-BANG'NA Ridoine
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	float a;
	float b;
	float resultat;
	char operateur;

	// ope_valide sera à false si 
	// l'operateur est invalide
	bool ope_valide = true; 

	cout << "Calculatrice" << endl << endl;

	// Saisie des valeurs
	cout << "Saisir un nombre (a): ";
	cin >> a;

	cout << "Saisir un nombre (b): ";
	cin >> b;

	cout << "Saisir l'opérateur (+-/*%): ";
	cin >> operateur;

	// Calcul du résultat
	switch (operateur) {
		case '+':
			resultat = a + b;
			break;
		case '-':
			resultat = a - b;
			break;
		case '*':
			resultat = a * b;
			break;
		case '/':
			resultat = a / b;
			break;
		/*case '%':
			resultat = a % b;
			break;*/
		default:
			ope_valide = false;
	}

	// un saut de ligne
	cout << endl;

	if (ope_valide) {
		/* affichage du resultat si l'operateur est valide */

		// définition la précision de l'affichage 
		// des nombres à deux chiffres après la virgule
		cout << fixed << setprecision(2);

		cout << a << ' ' << operateur << ' ' << b << " = " << resultat << endl;
	}else {
		cout << "operateur invalide." << endl;
	}
}
#include <iostream>

using namespace std;

int main() {
	float a;
	float b;
	float resultat;
	char operateur;

	// et ope_valide qui sera à false si 
	// l'operateur est invalide
	bool ope_valide = true; 

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
		// affichage du resultat si l'operateur est valide
		cout << a << ' ' << operateur << ' ' << b << " = " << resultat << endl;
	}else {
		cout << "operateur invalide." << endl;
	}


}
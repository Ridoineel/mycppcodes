#include <iostream>

using namespace std;

int randint(int min, int max) {
	return min + rand()%(max - min + 1);
}

int main() {
	//
	srand(time(0));

	// intervale du nombre aléatoire
	const int START_NB = 0;
	const int END_NB = 5;
	// Nombre de tour du jeu (basé sur l'intervale)
	const int MAX_TOUR = 20;
	const int TOUR = min((END_NB - START_NB + 1)*2/3, MAX_TOUR);

	int n;
	int tour_cpt = TOUR;
	int target_number = randint(START_NB, END_NB);
	

	/*cout << target_number << endl;*/
	printf("Salut, je viens de choisir un nombre compris entre (%d-%d),\n", START_NB, END_NB);
	cout << "essaie de le deviner." << endl;

	do {
		cout << "Tour: " << tour_cpt << endl;

		cout << "Entrer le nombre: ";
		cin >> n;

		cout << endl;

		if (n != target_number){
			cout << "Désolé ce n'est pas le bon nombre." << endl;
			cout << endl;
		}

		tour_cpt--;

	}while (n != target_number and tour_cpt > 0);


	if (n == target_number) {
		cout << "Félication, " << n << " est bien le nombre que j'ai choisie." << endl;
		printf("Trouvé en %d tour(s) sur %d.\n", TOUR - tour_cpt, TOUR);
		// cout << "Trouvé en " << TOUR - tour_cpt << " tours sur " << TOUR << endl;
	}else {
		cout << "Nombre de tour épuisé." << endl;
	}

	return 0;
}
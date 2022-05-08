#include <iostream>


#define CLEAR_BUFFER while (getchar() != '\n');

using namespace std;

int randint(int min, int max) {
	/* Renvoi un nombre aléatoire compris entre 
	*  min et max
	*/

	return min + rand()%(max - min + 1);
}

int ctoi(char digit) {
	/* Conversion de chiffre char ('0' - '9') vers int
	*
	*/

	return digit - 48;
}

int getNiveau() {
	char niv;

	do {
		cout << "Saisir votre choix (1-3): ";
		cin >> niv;

		CLEAR_BUFFER;
	}while (niv <= '0' or niv > '3');

	return ctoi(niv);
}

void setInterval(int niv, int& startNb, int& endNb) {

	switch (niv) {
		case 1:
			startNb = 0;
			endNb = 100;
			break;
		case 2:
			startNb = 0;
			endNb = 500;
			break;
		case 3:
			startNb = 0;
			endNb = 1000;
			break;
	}
}

/*
int getNiveau() {
	string niv;

	do {
		cout << "Saisir votre choix (1-3): ";
		getline(cin, niv);

	}while (niv <= "0" or niv > "3");

	return niv;
}
*/
int main() {
	//
	srand(time(0));

	// Nombre de nbTour maximal du jeu
	const int maxTour = 15;

	int n;
	int tour;
	int randomNumber;
	int niv;
	int startNb;
	int endNb;
	int nbTour;

	cout << "1. Niveau Facile (0-100)" << endl;
	cout << "2. Niveau moyen (0-500)" << endl;
	cout << "3. Niveau difficile (0-1000)" << endl;
	cout << endl;

	niv = getNiveau();

	// définition de l'interval du nombre aléatoire,
	// par rapport au niveau du jeu.
	setInterval(niv, startNb, endNb);

	randomNumber = randint(startNb, endNb);
	//nbTour = min((endNb - startNb + 1)*2/3, maxTour);
	tour = maxTour;
	
	/*cout << randomNumber << endl;*/
	printf("Salut, je viens de choisir un nombre compris entre %d-%d,\n", startNb, endNb);
	cout << "essaie de le deviner." << endl;

	do {
		cout << "Tour: " << tour << endl;

		cout << "Entrer le nombre: ";
		cin >> n;

		cout << endl;

		if (n < randomNumber){
			cout << "Désolé, c'est plus petit que ça." << endl;
			cout << endl;
		}

		if (n > randomNumber){
			cout << "Désolé, c'est plus grand que ça." << endl;
			cout << endl;
		}

		tour--;

	}while (n != randomNumber and tour > 0);


	if (n == randomNumber) {
		printf("Félication, %d est bien le nombre que j'ai choisie.\n", n);
		printf("Trouvé en %d nbTour(s) sur %d.\n", nbTour - tour, nbTour);
		// cout << "Félication, " << n << " est bien le nombre que j'ai choisie." << endl;
		// cout << "Trouvé en " << TOUR - tour << " tours sur " << TOUR << endl;
	}else {
		cout << "Nombre de nbTour épuisé." << endl;
	}

	return 0;
}
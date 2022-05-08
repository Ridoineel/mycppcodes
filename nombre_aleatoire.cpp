#include <iostream>
#include <cmath>
#include <vector>

#define CLEAR_BUFFER while (getchar() != '\n');

using namespace std;

int randint(int min, int max) {
	/* Renvoi un nombre aléatoire compris entre 
	*  min et max
	*/

	return min + rand()%(max - min + 1);
}

int ctoi(char digit) {
	/* 	Renvoit la conversion de chiffre 
	*	char ('0' - '9') vers int
	*
	*/

	return digit - 48;
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


int getNiveau() {
	string niv;

	do {
		cout << "Saisir votre choix (1-3): ";
		getline(cin, niv);

		if (niv.size() != 1 or niv <= "0" or niv > "3") {
			cout << "Saisie invalide." << endl << endl;
		}
	}while (niv.size() != 1 or niv <= "0" or niv > "3");

	return ctoi(niv[0]);
}

string winnerStatus(int tour) {
	/* Renvoi le status du gagnant 
	*
	*/

	int tourRange = ceil((float(tour)/3));
	
	switch (tourRange) {
		case 1:
			return "super voyant";
		case 2:
			return "sage voyant";
		case 3:
			return "apprenti voyant";
		default:
			return "pusillanime";
	}
}

float olympAvg(vector <int> vect) {
	/*	Calcule et renvoit la moyenne olympique,
	*	des nombres de <vect>
	*
	*/

	int length = vect.size();
	int sum;
	float avg;

	for (int i = 0; i < length; i++) {
		sum += vect[i];
	}

	avg = float(sum)/length;

	return avg;
}

int main() {
	//
	srand(time(0));

	// Nombre de tour maximal du jeu
	const int maxTour = 15;

	int n;
	int tour;
	int randomNumber;
	int niv;
	int startNb;
	int endNb;
	vector<int> tentatives;
	//int nbTour;

	cout << "	JEU DE DEVINETTE" << endl << endl;
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

	cout << endl;
	cout << "Salut, je viens de choisir un nombre compris entre " << startNb << "-" << endNb << endl;
	cout << "essaie de le deviner." << endl << endl;

	do {
		cout << "Tour restant: " << tour << endl;

		cout << "Entrer le nombre: ";
		cin >> n;

		cout << endl;

		// enregistrement de la tentative
		tentatives.push_back(n);

		if (n > randomNumber){
			cout << "Désolé, c'est plus petit que ça." << endl;
			cout << endl;
		}

		if (n < randomNumber){
			cout << "Désolé, c'est plus grand que ça." << endl;
			cout << endl;
		}

		tour--;

	}while (n != randomNumber and tour > 0);

	if (n == randomNumber) {
		cout << "Félication, " << n << " est bien le nombre que j'ai choisie." << endl;
		cout << "Trouvé en " << maxTour - tour << "/" << maxTour << "tours." << endl;
		cout << "Status gagnant: " << winnerStatus(maxTour - tour) << endl;
	}else {
		cout << "Nombre de tour épuisé." << endl;
	}

	return 0;
}
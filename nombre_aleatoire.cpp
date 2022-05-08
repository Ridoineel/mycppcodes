#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

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

void setInterval(int level, int& startNb, int& endNb) {

	switch (level) {
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


int getLevel() {
	string level;

	do {
		cout << "Saisir votre choix (1-3): ";
		getline(cin, level);

		if (level.size() != 1 or level <= "0" or level > "3") {
			cout << "Saisie invalide." << endl << endl;
		}
	}while (level.size() != 1 or level <= "0" or level > "3");

	return ctoi(level[0]);
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
	/*	Calcule et renvoit la moyenne olympique
	*	des nombres de du tableau vect.
	*
	*/

	int length = vect.size();
	int sum = 0;
	float avg;

	for (int i = 0; i < length; i++) {
		sum += vect[i];
	}

	avg = float(sum)/length;

	return avg;
}

void clearScreen() {
	system("cls|clear");
}

void game(vector<int>& tentatives) {
	//
	srand(time(0));

	// Nombre de tour maximal du jeu
	const int maxTour = 15;

	int n;
	int tour;
	int randomNumber;
	int level;
	int startNb;
	int endNb;
	//int nbTour;

	clearScreen();

	cout << "	JEU DE DEVINETTE" << endl << endl;
	cout << "1. Niveau Facile (0-100)" << endl;
	cout << "2. Niveau moyen (0-500)" << endl;
	cout << "3. Niveau difficile (0-1000)" << endl;
	cout << endl;

	level = getLevel();

	// définition de l'interval du nombre aléatoire,
	// par rapport au niveau du jeu.
	setInterval(level, startNb, endNb);

	randomNumber = randint(startNb, endNb);
	//nbTour = min((endNb - startNb + 1)*2/3, maxTour);
	tour = maxTour;

	clearScreen();

	// cout << endl;
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

	clearScreen();

	if (n == randomNumber) {
		cout << "Félication, " << n << " est bien le nombre que j'ai choisie." << endl;
		cout << "Trouvé en " << maxTour - tour << "/" << maxTour << " tours." << endl;
		cout << "Status gagnant: " << winnerStatus(maxTour - tour) << endl;
	}else {
		cout << "Nombre de tour épuisé." << endl;
	}

	cout << endl;
}

int main() {
	vector<int> tentatives;
	char replay = 'O';

	do {
		game(tentatives);

		// affichage de l'historique du jeu.
		cout << "Les tentatives:" << endl;

		for (int i = 0; i < tentatives.size(); i++) {
			cout << "Tour " << i + 1 << ": " << tentatives[i] << endl;
		}

		cout << fixed << setprecision(2);
		// ecart type

		// moyenne olympique
		cout << endl;
		cout << "Moyenne olympique: " << olympAvg(tentatives) << endl;

		cout << endl;
		cout << "Voulez vous rejouer ? (O/N): ";
		cin  >> replay;

		// convertir replay en majuscule
		// s'il est en miuscule
		if (islower(replay)) {
			replay -= 32;
		}

		cin.ignore();
	}while (replay == 'O');

	cout << endl;
	cout << "Merci d'avoir jouer !" << endl;
	cout << "Aurevoir." << endl;

	return 0;
}
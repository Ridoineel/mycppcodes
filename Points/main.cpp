#include <iostream>
#include <vector>

using namespace std;

typedef struct TPoint TPoint;

struct TPoint {
	int abs;
	int ord;
};

int main() {
	// Prototypes
	TPoint* inputPt();
	void afficherPoints(vector<TPoint*> tabPt);

	// variables
	TPoint * pt;
	vector<TPoint*> tabPt;
	unsigned int choix;
	char c = 'o';
	
	cout << "Programme de gestion des points" << endl;
	// pt = inputPt();
	// cout << "Point{(" << pt->abs << ", " << pt->ord << "}" << endl;



	do {
		cout << "1. Ajouter point" << endl;
		cout << "2. Lister les points" << endl;
		cout << "3. Calculer la distance entre deux points" << endl;
		cout << "9. Quitter" << endl;

		cout << endl;
		cout << "Saisir votre choix: ";
		cin >> choix;

		switch(choix) {
			case 1:
				pt = inputPt();
				tabPt.push_back(pt);
				break;
			case 2:
				afficherPoints(tabPt);
				break;
			case 3:
				break;
			case 9:
				cout << "Aurevoir " << endl;
				exit(0);
				break;
		}
	}while (c = 'o');

	return 0;
}

TPoint * inputPt() {
	TPoint* pt = new TPoint;
	
	cout << "Saisie des coordonnées d'un nouveau point: " << endl;

	cout << "Abscisse: ";
	cin >> pt->abs;

	cout << "Ordonné: ";
	cin >> pt->ord;

	return pt;
}

void afficherPoints(vector<TPoint*> tabPt) {
	cout << endl;

	for (int i=0; i < tabPt.size(); i++) {
		printf("Point%d: (%d, %d)\n", i + 1, tabPt[i]->abs, tabPt[i]->ord);
	}

	cout << endl;
}

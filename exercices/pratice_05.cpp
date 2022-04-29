/*
* Calcul de BMI
* Autheur: OURO-BANG'NA Ridoine
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

float calculPI(char sexe, float taille) {
	/* renvoit le PI par rapport au sexe et 
	*  la taille d'une personne.
	*
	*  Elle renvoit -1 lorsque sexe != M et F 
	*/

	float PI = -1;

	// normalisation du sexe en majuscule
	sexe = toupper(sexe);

	if (sexe == 'M'){
		PI = (taille - 100) - (taille - 150)/4;
	}
	else if (sexe == 'F'){
		PI = (taille - 100) - (taille - 120)/4;
	}
	// au cas contraire, PI reste égale à -1

	return PI;
}

float calculBMI(float poids, float taille) {
	return poids/(taille*taille);
}

string diag(float BMI) {
	string status = "Normale";

	if (BMI >= 32) {
		status = "Malade";
	}else if (BMI > 27) {
		status = "Obèse";
	}

	return status;
}

int main() {
	// code...
	float taille;
	float poids;
	char sexe;
	float PI;
	float BMI;
	string status;

	cout << "	CALCUL DE BMI" << endl << endl;

	cout << "Saisir la taille (cm): ";
	cin >> taille;

	cout << "Saisir le poids (kg): ";
	cin >> poids;

	do {
		cout << "Saisir le sexe (M/F): ";
		cin >> sexe;

		PI = calculPI(sexe, taille);

		if (PI == -1) {
			cout << "Sexe incorrecte !" << endl;
			cout << endl;
		}
	}while (PI == -1);

	// conversion de la taille 
	// en m (cm -> m)
	taille = taille/100;

	BMI = calculBMI(poids, taille);
	status = diag(BMI);


	cout << endl; // saut de ligne
	cout << fixed << setprecision(2);

	cout << "PI  : " << PI << endl;
	cout << "BMI : " << BMI << endl;
	cout << endl;
	cout << "Cette personne est " << status << endl;
	
	return 0;
}
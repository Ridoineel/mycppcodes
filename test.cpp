#include <iostream>
#include <vector>
#include <cstring>

struct Personne {
	std::string nom;
	std::string prenom;
	int age;

};

// #define CLEAR_BUFFER while (getchar() != '\n');
using namespace std;

int main()
{
	/*string a = "0 1 2 3";
	string w;
	stringstream ss(a);

	while (ss >> w) {
		cout << w << endl;
	}*/
	
	Personne ridoine;
	ridoine.nom = "OURO-B";
	ridoine.prenom = "Ridoine";
	ridoine.age = 20;

	cout << "Nom: " << ridoine.nom << endl;
	cout << "Prenom: " << ridoine.prenom << endl;
	cout << "Age: " << ridoine.age << endl;


	vector<> aroidoi;




	return 0;
}

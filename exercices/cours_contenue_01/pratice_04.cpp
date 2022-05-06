/*
* Calcul de la distance entre deux points
* Autheur: OURO-BANG'NA Ridoine
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	// code...
	float ax;
	float ay;
	float bx;
	float by;
	float dist;

	cout << " Calcul de la distance entre deux points." << endl << endl;

	// premier point
	cout << "Entrer les coordonées du premier point (A): " << endl;

	cout << "> x: ";
	cin >> ax;

	cout << "> y: ";
	cin >> ay;

	// deuxième point
	cout << endl;
	cout << "Entrer les coordonées du deuxième point (B): " << endl;

	cout << "> x: ";
	cin >> bx;

	cout << "> y: ";
	cin >> by;

	cout << endl;

	// calcul de la distance
	dist = sqrt(pow(ax - bx, 2) + pow(ay - by, 2));

	cout << fixed;
	cout << "d(A, B) = " << setprecision(2) << dist << endl;
	
	return 0;
}
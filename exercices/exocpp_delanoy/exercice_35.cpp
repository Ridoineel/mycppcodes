#include <iostream>

using namespace std;

void main1() {
	/* 	Min et max d'un tableau avec
	*	le formalisme tableau uniquement
	*/

	float nombres[10];
	float min;
	float max;

	for (int i = 0; i < 10; i++) {
		cout << "Val " << i + 1 << ": ";
		cin >> nombres[i];
	}

	min = nombres[0];
	max = nombres[0];

	for (int i = 1; i < 10; i++) {
		if (min > nombres[i]) {
			min = nombres[i];
		}

		if (max < nombres[i]) {
			max = nombres[i];
		}
	}

	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
}

void main2() {
	/* 	Min et max d'un tableau avec pointeur
	*/

	float nombres[10];
	float min;
	float max;

	for (int i = 0; i < 10; i++) {
		cout << "Val " << i + 1 << ": ";
		cin >> *(nombres + i);
	}

	min = *nombres;
	max = *nombres;

	for (int i = 1; i < 10; i++) {
		if (min > *(nombres + i)) {
			min = *(nombres + i);
		}

		if (max < *(nombres + i)) {
			max = *(nombres + i);
		}
	}

	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
}

int main()
{
	main2();

	return 0;
}

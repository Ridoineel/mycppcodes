#include <iostream>

using namespace std;

int main() {
	/*	Recopier dans t2 les valeurs positive de t1
	*	et complèter t2 par des 0
	*
	*/

	int t1[] = {-1, 2, -3, 4, -5, 6, -7, 8, -9, 10};
	int t2[10];
	int nbPos(0);

	// copie de nb positive de t1 -> t2
	for (int j = 0, i = 0; i < 10; i++) {
		if (t1[i] > 0) {
			t2[j++] = t1[i];
			nbPos++;
		}
	}

	// on complète t2 par des zeros
	for (int i = nbPos; i < 10; i++) {
		t2[i] = 0;
	}


	for (int i = 0; i < 10; i++) {
		cout << "Val " << i + 1 << ": " << t2[i] << endl;
	}
	
	return 0;
}

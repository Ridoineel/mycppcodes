#include <iostream>
#include <vector>

// #define CLEAR_BUFFER while (getchar() != '\n');
using namespace std;

int main()
{
	vector<string> v;
	string rid = "Midoine";
	rid[0] = 'R';

	rid += "dd";

	v.push_back(rid);

	cout << rid << endl;


	

	return 0;
}

#include <iostream>
#include <vector>

#include"exemple.h"

using namespace std;

vector<int> rezultate;

void myFunction(vector<int(*)(int)> vectorFunctii, int valoare){
	
	// Adaug in vectorul rezultate valorile de return ale functiilor
	// aflate la adresele din vectorul 'vectorFunctii' aplicate asupra
	// valoii 'valoare'	
	for (unsigned int i = 0; i < vectorFunctii.size(); i++)
		rezultate.push_back((*vectorFunctii.at(i))(valoare));

}

int main() {
	
	vector<int(*)(int)> functii;
	
	// Test 1
	functii.push_back(&identica);
	functii.push_back(&patrat);
	functii.push_back(&cub);
	
	myFunction(functii, 3);
	
	cout << "Rezultatele identica(3), patrat(3) si cub(3)" << endl;
	for (unsigned int i = 0; i < rezultate.size(); i++)
		cout << rezultate.at(i) << endl;
	functii.clear();
	rezultate.clear();
	
	// Test 2
	functii.push_back(&opus);
	functii.push_back(&patrat);
	functii.push_back(&cub);
	functii.push_back(&nul);
	functii.push_back(&plus3);
	
	myFunction(functii, 4);
	
	cout << "Rezultatele opus(4), patrat(4), ";
	cout << "cub(3), nul(4), plus3(4)" << endl;
	for (unsigned int i = 0; i < rezultate.size(); i++)
		cout << rezultate.at(i) << endl;

	functii.clear();
	rezultate.clear();
	
	return 0;

}

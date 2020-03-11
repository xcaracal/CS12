
#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string filename);
int main() {
	string filename;
	cout << "Enter the name of the input file: ";
	cin >> filename;
	cout << endl;
	cout << "Sum: " << fileSum(filename) << endl;
	return 0;
}

// Place fileSum implementation here
int fileSum(string filename) {
	ifstream input;
	int num;
	int sum;

	input.open(filename);
	if (!input.is_open()) {
		cout << "Error opening " << filename << endl;
		return 1;
	}
	while (!input.fail()) {
		input >> num;
		sum = sum + num;
		return sum;
	}
	input.close();


}
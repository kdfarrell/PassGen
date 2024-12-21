#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

string toLower(string word) {
	
	for (auto& c : word) {
		c = tolower(c);
	}
	return word;
}

int main() {
	
	int length;
	string opt1, opt2, opt3, opt4;
	string sequence;
	
	cout << "--- Welcome to PassGen ---\n\n";
	
	cout << "Enter the Length of your password: ";
	cin >> length;
	
	cout << "Would you like to include characters A-Z? [Yes/No]\n";
	cin >> opt1;
	
	cout << "\n\nWould you like to include characters 0-9? [Yes/No]\n";
	cin >> opt2;
	
	cout << "\n\nWould you like to include special characters !@#? [Yes/No]\n";
	cin >> opt3;
	
	cout << "Would you like your password to include a specific sequence. [Yes/No]\n";
	cout << "Sequence: blueberry\n";
	cout << "Password: =3blueberry!?a\n";
	cin >> opt4;
	
	
	
	if (toLower(opt4) == "yes") {
		cout << "hi";
	}
}


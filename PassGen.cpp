#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	
	int length;
	char op1, op2, op3, op4;
	string sequence;
	
	cout << "--- Welcome to PassGen ---\n\n";
	
	cout << "Enter the Length of your password: ";
	cin >> length;
	
	cout << "Would you like to include characters A-Z? [Yes/No]\n\n";
	cin >> op1;
	
	cout << "Would you like to include characters 0-9? [Yes/No]\n\n";
	cin >> op2;
	
	cout << "Would you like to include special characters !@#? [Yes/No]\n\n";
	cin >> op3;
	
	cout << "Would you like your password to include a specific sequence. [Yes/No]\n";
	cout << "Sequence: blueberry\n";
	cout << "Password: =3blueberry!?a\n";
	cin >> op4;
}


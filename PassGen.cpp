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
	string opt1, opt2, opt3, opt4, opt5;
	string sequence, password;
	
	srand(time(0));
	
	cout << "--- Welcome to PassGen ---\n\n";
	
	cout << "Enter the Length of your password: ";
	cin >> length;
	
	cout << "\nInclude lowercase letters a-z? [Yes/No]\n";
	cin >> opt1;
	
	cout << "\nInclude uppercase letters A-Z? [Yes/No]\n";
	cin >> opt2;
	
	cout << "\nInclude Numbers 0-9? [Yes/No]\n";
	cin >> opt3;
	
	cout << "\nInclude special characters !@#? [Yes/No]\n";
	cin >> opt4;
	
	cout << "\Exclude any characters? [Yes/No]\n";
	cin >> opt5
	
	cout << "\nWould you like your password to include a specific sequence. [Yes/No]\n";
	cout << "Sequence: blueberry\n";
	cout << "Password: =3blueberry!?a\n";
	cin >> opt6;
	
	if (toLower(opt6) == "yes") {
		cout << "Enter the sequence: ";
		cin >> sequence;
	}
	
	if (sequence.empty() == true) {
		

		for (int i = 0 ; i < 10; ++i){
			
			while (length != 0) {
			
				int chartype = rand() % 5 + 1;
				
				if (chartype == 1) {
					
					char type1 = rand() % (122 - 97 + 1) + 97;
					cout << type1;	
				}
				if (chartype == 2) {
					
					char type2 = rand() % (90 - 65 + 1) + 65;
					cout << type2;	
				}
				if (chartype == 3) {
					
					char type3 = rand() % (57 - 48 + 1) + 48;
					cout << type3;	
				}
				if (chartype == 4) {
					
					char type4 = rand() % (47 - 33 + 1) + 33;
					cout << type4;		
				}
				length--;				
			}
			cout << endl;
			length = 8;	
		}	
	}
	return 0;
}


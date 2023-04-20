#include <iostream>
#include <string>

using namespace std;

//------prototypes------
int raiseToExp(int base, int exponent);


/**
    Asks the user to enter a positive integer for a base and positive or 0 integer
    for an exponent and raises the base value to the exponent value
    @author Keara Taylor Lopez
    @date February 5, 2023
*/
int main() {
	string input;
	int found = false;
	int base, exponent, result;

	//getting user input for base
	cout << "Please enter the base: ";
	getline(cin, input);
	found = input.find('.'); //returns the position of the first character of the first match of '.'


	while ((stoi (input) <= 0) || (found != string::npos)) {
		while (found != string::npos) { //if string::npos is not found, then there exists '.' -- floating type
			cout << "This is a floating-point value, please enter an integer: ";
			getline (cin, input);
			found = input.find ('.');

		}//end while

		while (stof (input) <= 0.0) {
			cout << "The base must be positive, please re-enter the base: ";
			getline (cin, input);
			found = input.find ('.');

		}//end while

		found = input.find('.');

	}//end outer while


	if ((!(stoi (input) <= 0)) && (found == string::npos)) {
		base = stoi (input);
	}//end if


	//getting user input for exponent
	cout << "Please enter the exponent: ";
	getline(cin, input);
	found = input.find('.');

	while ((stoi (input) < 0) || (found != string::npos)) {
		while (found != string::npos) {
			cout << "This is a floating-point value, please enter an integer: ";
			getline (cin, input);
			found = input.find ('.');

		}//end while

		while (stof (input) < 0.0) {
			cout << "The exponent must be positive, please re-enter the exponent: ";
			getline (cin, input);
			found = input.find ('.');

		}//end while

		found = input.find('.');

	}//end outer while

	if ((!(stoi (input) < 0)) && (found == string::npos)) {
		exponent = stoi (input);
	}//end if


	//---using input to raise base to exponent value---
	result = raiseToExp(base, exponent);
	cout << base << " ^ " << exponent << " = " << result << endl;


	return 0;

}//end main()



/**
    Raises user-provided base value to user-provided exponent value
    @param base the base integer
    @param exponent the exponent integer
    @return the base raised to an exponent or if exponent is 0, returns 1
*/
int raiseToExp(int base, int exponent) {
	if (exponent > 0) {
		return base * raiseToExp(base, exponent - 1);
	} else {
		return 1;
	}
}//end raiseToExp()


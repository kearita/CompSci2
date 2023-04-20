/** Main
  * @file main.cpp
  * @author Keara Taylor Lopez
*/
#include <iostream>
#include <string>
#include <sstream>
#include "ArrayStack.h"

using namespace std;

/**
    Instantiates an array-based implementation of a vowel, digit and symbol stack.
    Gets string data from user-input and pushes data to corresponding stacks.
    Calculates a result based an operation (whose operation was provided
    by the top of the symbol stack) on the first two items of the digit stack
    @author Keara Taylor Lopez
    @date March 7, 2023
*/
int main() {
	ArrayStack<char>vowelStack;
	string line;
	string vowels = "aeiouAEIOU";
	char vowelOccurrences[] = {'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z'};

	ArrayStack<int>digitStack;
	int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int digitOccurrences[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

	ArrayStack<char>symbolStack;
	string symbols = "+-*/%";
	char symbolOccurrences[] = {'&', '&', '&', '&', '&', '&', '&', '&', '&', '&'};

	int digit;
	int numDigits = 0;

	cout << "Input a string: ";
	getline(cin, line, '\n');


	int found = line.find_first_of(symbols);

	for(int i = 0; i < line.length(); i++) {
		if(isdigit(line[i])) {
			digit = line[i] - '0';
			numDigits++;
		}
	}

	while(found == -1 || numDigits < 2) {
		cout << "Bad data" << endl;
		cout << "Please re-enter: ";
		getline(cin, line, '\n');
		found = line.find_first_of(symbols);

		for(int i = 0; i < line.length(); i++) {
			if(isdigit(line[i])) {
				digit = line[i] - '0';
				numDigits++;
			}
		}
	}//end while


	for(int i = 0; i < line.length(); i++) {
		//***PUSH TO VOWELSTACK***
		for(int j = 0; j < vowels.length(); j++) {
			if((line[i] == vowels[j]) && (line[i] != vowelOccurrences[j]) &&
			        (vowelOccurrences[j] != 'x')) {
				vowelOccurrences[j] = line[i];
				vowelStack.push(vowelOccurrences[j]);
			} else if((line[i] == vowels[j]) && (line[i] == vowelOccurrences[j])) {
				vowelOccurrences[j] = 'x';
			}

		}//end for

		//***PUSH TO SYMBOLSTACK***
		for(int k = 0; k < symbols.length(); k++) {
			if((line[i] == symbols[k]) && (line[i] != symbolOccurrences[k]) &&
			        (symbolOccurrences[k] != '!')) {
				symbolOccurrences[k] = line[i];
				symbolStack.push(symbolOccurrences[k]);
			} else if((line[i] == symbols[k]) && (line[i] == symbolOccurrences[k])) {
				symbolOccurrences[k] = '!';
			}
		}//end for

		//***PUSH TO DIGITSTACK***
		if(isdigit(line[i])) {
			digit = line[i] - '0';

			for(int n = 0; n < 10; n++) {
				if(digit == digits[n] && digit != digitOccurrences[n] &&
				        digitOccurrences[n] != -2) {
					digitOccurrences[n] = digit;
					digitStack.push(digitOccurrences[n]);
				} else if(digit == digitOccurrences[n]) {
					digitOccurrences[n] = -2;
				}
			}//end for
		}

	}//end for


	int firstInt = digitStack.peek();
	digitStack.pop();
	int secondInt = digitStack.peek();
	digitStack.pop();

	int result;
	char operation = symbolStack.peek();

	if(operation == '+')
		result = firstInt + secondInt;
	else if(operation == '-')
		result = firstInt - secondInt;
	else if(operation == '*')
		result = firstInt * secondInt;
	else if(operation == '/')
		result = firstInt / secondInt;
	else if(operation == '%')
		result = firstInt % secondInt;


	//*****DISPLAY STACKS*****
	cout << "Vowel Stack" << endl;

	while(!vowelStack.isEmpty()) {
		cout << vowelStack.peek() << endl;
		vowelStack.pop();
	}

	cout << "Digit Stack" << endl;
	cout << firstInt << endl;
	cout << secondInt << endl;

	while(!digitStack.isEmpty()) {
		cout << digitStack.peek() << endl;
		digitStack.pop();
	}

	cout << "Symbol Stack" << endl;

	while(!symbolStack.isEmpty()) {
		cout << symbolStack.peek() << endl;
		symbolStack.pop();
	}

	cout << "Result: " << result << endl;


	return 0;
}

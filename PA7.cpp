/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: April 12, 2020
Programming Assignment: PA7
Description: Create a program that solves two tasks: 1) Report gross salary amounts and benefits for employees at your company, 2) Convert INFIX expressions to POSTFIX expressions and then evaluate those POSTFIX expressions using stacks.
Notes: Function definition cpp file
*/
#include "PA7.h"
/*************************************************************
 * Function: runTask1()
 * Date Created: 04/12/20
 * Date Last Modified: 04/12/20          
 * Description: This function runs task 1.
 * Input parameters: none
 * Returns: nothing
 * Pre: nothing
 * Post: Runs the functions called that execute and display
 *				task 1.
*************************************************************/
// TODO: your task 1 helper functions here
void runTask1() {
	Employee * employeePtrArr[8];
	
	employeePtrArr[0] = new Programmer("Milee Owen", 0);
	employeePtrArr[1] = new Programmer("Ima Nerd", 1);
	employeePtrArr[2] = new Lawyer("Kenny Dewitt", 10);
	employeePtrArr[3] = new Lawyer("Dan D. Lyon", 0);
	employeePtrArr[4] = new Lawyer("Willie Makit", 100);
	employeePtrArr[5] = new Accountant("Hal E. Luya", 17.00);
	employeePtrArr[6] = new Accountant("Midas Well", 45.50);
	employeePtrArr[7] = new Accountant("Doll R. Bill", 2.50);
	
	cout << "Task 1:" << endl << "--------------------" << endl;
	
	for (Employee * employeePtr : employeePtrArr) {
		// same code for all objects pointed to
		cout << employeePtr->toStringStaticBind() << endl;
		cout << employeePtr->toStringDynamicBind() << endl << endl;
	}
}
/*************************************************************
 * Function: runTask2()
 * Date Created: 04/12/20
 * Date Last Modified: 04/12/20          
 * Description: This function runs task 2.
 * Input parameters: none
 * Returns: nothing
 * Pre: nothing
 * Post: Runs the functions called that execute and display
 *				task 2.
*************************************************************/
// TODO: your task 2 helper functions here
void runTask2() {
	ifstream inputFile;
	Calculator test;
	string line, infix, postfix, integer;
	char letter;
	string inputSymbolTable['Z' + 1];
	string postfixEvaluation;
	
	openInputFile(inputFile, "../input.txt");
	
	// gets information from file
	while (letter != '#' || integer != "#") {
		if (inputFile.good()) {
			inputFile >> letter;
			// if reaches # stop reading in values
			if (letter == '#') {
				break;
			}
			inputFile.ignore();
			inputFile >> integer;
			inputSymbolTable[letter] = integer;
		}
	}
	
	// sets the new symbolTable array
	test.setSymbolTable(inputSymbolTable);
	
	// skip over #
	inputFile.ignore();
	
	cout << "Task 2:" << endl << "--------------------" << endl;
	
	while (!inputFile.eof() && infix != "#") {
		getline(inputFile, infix);
		// if reaches # stop reading in expressions
		if (infix == "#") {
			break;
		}
		// display content
		cout << "Infix Expression: " << infix << endl;
		postfix = test.convertInfixToPostfix(infix);
		cout << "Postfix Equivalent: " << postfix << endl;
		postfixEvaluation = test.evaluatePostfix(postfix);
		cout << "Expression value after postfix evaluation: " << postfixEvaluation << endl << endl;
	}
	
	inputFile.close();
}
/*************************************************************
 * Function: openinputFile()
 * Date Created: 01/21/20
 * Date Last Modified: 02/17/20          
 * Description: This function opens file for reading in.
 * Input parameters: The ifstream file must be pass by 
 *				reference and the name of the file.
 * Returns: nothing
 * Pre: The ifstream file must be pass by 
 *				reference and the name of the file had to have 
 *            	been scanned in by the user.
 * Post: The file is opened or not and a message is displayed.
 *************************************************************/
void openInputFile(ifstream& inputFile, string iname) {
	// opens file for reading & outputs message
	inputFile.open(iname);
	if (inputFile.is_open()) {
		cout << "Successfully opened file" << endl;
	}
	else {
		cout << "Failed to open file" << endl;
		exit(-1);
	}
}

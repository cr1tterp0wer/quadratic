/**
 * ./main.cpp
 * Driver for Quadratic package
 * Christopher Apodaca
 */

#include<iostream>
#include "quadratic.h"

using std::endl;
using std::cout;

float A = 2;
float B = 6;
float C = 4;

/**
 * Launch the program here
 * @return {Boolean} - The Status flag: (1)Error (0)Success
 */
int main() {

		Quadratic *q;
	// Try to create the Quadratic object.
	// Terminate program with Status(1) if errors.
	try {
		q = new Quadratic(A, B, C);
	} catch (DiscriminantException& de) {
		std::cout << "Error, Exception Caught" << std::endl;
		printf("Invalid variables (%.2f,%.2f,%.2f) on initialize()\n", A, B, C);
		std::cout << de.what() << std::endl;
		std::cout << "Terminating..." << std::endl;

		return 1;
	}


	printf("Quadratic Solutions for values  a:%.2f b:%.2f c:%.2f\n", A, B, C); 
	cout << q->calculatePositive() << endl;
	cout << q->calculateNegative() << endl;

	return 0;
}

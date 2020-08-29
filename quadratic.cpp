/**
 * ./quadratic.cpp
 * Calculates the quadratic formula
 * Christopher Apodaca
 */

#include "quadratic.h"
#include <exception>
#include <iostream>
#include <cmath>

/**
 * Custom Quadratic Discriminant Exception
 */
struct DiscriminantException: public std::exception {
	const char * what() const throw() {
		return "DiscriminantException::NEGATIVE_SQUARE_ROOT";
	}
};

/**
 * Quadratic Formula constructor
 * @param {float} a - The quadratic var a
 * @param {float} b - The quadratic var b
 * @param {float} c - The quadratic var c
 */
Quadratic::Quadratic(float a, float b, float c) {
	this->a = a;
	this->b = b;
	this->c = c;

	// Validate the values given resolve to
	// a non-zero discriminant when obj is created
	this->isValidDiscriminant();
}

/**
 * Calculates the Positive value of the formula
 * @return {float} - the calculated solution
 */
float Quadratic::calculatePositive() {
	float disc = this->getDiscriminant();

	float numer = -b + sqrt(disc);
	float denom = 2*a;

	return numer / denom;
}

/**
 * Calculates the Negative value of the formula
 * @return {float} - the calculated solution
 */
float Quadratic::calculateNegative() {
	float disc = this->getDiscriminant();

	float numer = -b - sqrt(disc);
	float denom = 2*a;

	return numer / denom;
}

/**
 * Calculates the Discriminant formula: (b^2 - 4ac)
 * @return {float} - the calculated discriminant
 */
float Quadratic::getDiscriminant() {
	return (pow(this->b, 2) - (4 * this->a * this->c));
}

/**
 * Tests the variables for an impossible solutions.
 * Throws a DiscriminantException if the object was
 * created with bad values.
 * 
 * @throws {DiscriminantException} - the custom Exception
 * @return {Boolean} - the calculated discriminant
 */
bool Quadratic::isValidDiscriminant() {
	float disc = this->getDiscriminant();

	if (disc < 0) throw DiscriminantException();

	return disc;
}

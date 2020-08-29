
/**
 * ./quadratic.h
 * Calculates the quadratic formula
 * Christopher Apodaca
 */

#pragma once
#include <exception>

/**
 * Custom Quadratic Discriminant Exception
 */
struct DiscriminantException: public std::exception {
	const char * what() const throw() {
		return "DiscriminantException::NEGATIVE_SQUARE_ROOT";
	}
};

class Quadratic {
	public:
		Quadratic(float a, float b, float c);

		float calculatePositive();
		float calculateNegative();

	private:
		float a;
		float b;
		float c;
		float getDiscriminant();
		bool isValidDiscriminant();
};

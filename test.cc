#include "cdm/Vector2.h"
#include <iostream>
#include <cassert>

int main(void)
{
	std::cout << "[Type Construction]" << std::endl;
	{
		// Test default construction.
		std::cout << "\tDefault:\t";

		cdm::Vector2<float> vDefault;
		assert(vDefault.x == 0 && vDefault.y == 0);

		std::cout << "passed." << std::endl;
		// End Test

		// Test explicit construction.
		std::cout << "\tExplicit:\t";

		cdm::Vector2<float> vExplicit(3.14159f, 2.71828f);
		assert(vExplicit.x == 3.14159f && vExplicit.y == 2.71828f);

		std::cout << "passed." << std::endl;
		// End Test
	}

	// Test arithmetic operators
	std::cout << "[Arithmentic Operators]" << std::endl;
	{
		// Test addition.
		std::cout << "\tAddition:\t";

		cdm::Vector2<float> v1(0.5f, 0.25f);
		cdm::Vector2<float> v2(0.25f, 0.5f);

		cdm::Vector2<float> v3 = v1 + v2;

		assert(v3.x == 0.75f && v3.y == 0.75f);

		std::cout << "passed." << std::endl;
		// End Test

		// Test subtraction.
		//std::cout
	}


	// Test compound assignment operators
	// Test relational operators


	cdm::Vector2<float> v2(0.10f, 0.20f);
	std::cout << v2[0] << ", " << v2[1] << std::endl;
	std::cout << v2.magnitude() << std::endl;

	return 0;
}
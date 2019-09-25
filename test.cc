#include "cdm/vec2.h"
#include "cdm/vec3.h"
#include <iostream>
#include <cassert>

int main(void)
{
	std::cout << "[Type Construction]" << std::endl;
	{
		// Test default construction.
		std::cout << "\tDefault:\t";

		cdm::tvec2<float> vDefault;
		assert(vDefault.x == 0 && vDefault.y == 0);

		std::cout << "passed." << std::endl;
		// End Test

		// Test explicit construction.
		std::cout << "\tExplicit:\t";

		cdm::tvec2<float> vExplicit(3.14159f, 2.71828f);
		assert(vExplicit.x == 3.14159f && vExplicit.y == 2.71828f);

		std::cout << "passed." << std::endl;
		// End Test
	}

	// Test arithmetic operators
	std::cout << "[Arithmentic Operators]" << std::endl;
	{
		// Test addition.
		std::cout << "\tAddition:\t";

		cdm::vec2 v1(0.5f, 0.25f);
		cdm::vec2 v2(0.25f, 0.5f);

		cdm::vec2 v3 = v1 + v2;

		assert(v3.x == 0.75f && v3.y == 0.75f);

		std::cout << "passed." << std::endl;
		// End Test

		// Test subtraction.
		//std::cout
	}


	// Test compound assignment operators
	// Test relational operators

	cdm::vec2 t(3.0f, 4.0f);
	std::cout << t.magnitude() << std::endl;

	cdm::vec3 pos(1234.0f, 4276.0f, 200.0f);
	std::cout << pos.x << ", " << pos.y << ", " << pos.z << std::endl;

	return 0;
}
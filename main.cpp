#include <iostream>

#include "core/ValueModel.h"
#include "fuzzy/AndMin.h"

int main(int argc, char* const argv[]) {
	core::ValueModel<int> value(1);


	std::cout << "Value : " << value.evaluate() << std::endl;

	//fuzzy::AndMin<int> andOpe;
	core::ValueModel<int> left(5);
	core::ValueModel<int> right(4);

	fuzzy::AndMin<int> opeAnd;
	std::cout << opeAnd.evaluate(&left, &right) << std::endl;
}

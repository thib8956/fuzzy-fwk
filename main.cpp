#include <iostream>

#include "core/BinaryExpressionModel.h"
#include "core/ValueModel.h"
#include "fuzzy/AndMin.h"
#include "fuzzy/OrMax.h"
#include "fuzzy/NotMinus1.h"
#include "fuzzy/ThenMin.h"
#include "fuzzy/AggMax.h"
#include "fuzzy/ThenMult.h"
#include "fuzzy/AggPlus.h"


int main(int argc, char* const argv[]) {
	core::ValueModel<int> value(1);


	std::cout << "Value : " << value.evaluate() << std::endl;

	//fuzzy::AndMin<int> andOpe;
	core::ValueModel<int> left(5);
	core::ValueModel<int> right(4);
    fuzzy::AggPlus<int> opeAnd;
    std::cout << opeAnd.evaluate(&left, &right) << std::endl;
}

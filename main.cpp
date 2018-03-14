#include <iostream>

#include "core/UnaryExpressionModel.h"
#include "core/ValueModel.h"
#include "fuzzy/IsTriangle.h"
#include "fuzzy/NotMinus1.h"

int main(int argc, char* const argv[]) {
	core::ValueModel<int> value;
	int v(5);
	value.setValue(&v);

	std::cout << "Value : " << value.evaluate() << std::endl;

    fuzzy::NotMinus1<int> opeNot;
    core::UnaryExpressionModel<int> model(&value, &opeNot);
	std::cout << "NotMinus1 : " << model.evaluate() << std::endl;

	fuzzy::IsTriangle<int> opeIsTriangle;
	std::cout << "IsTriangle : " << opeIsTriangle.evaluate(&value) << std::endl;
}

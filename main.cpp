#include <iostream>

#include "core/ValueModel.h"
#include "fuzzy/NotMinus1.h"
#include "core/UnaryExpressionModel.h"

int main(int argc, char* const argv[]) {
	core::ValueModel<int> value;
	int v(5);
	value.setValue(&v);

	std::cout << "Value : " << value.evaluate() << std::endl;

    fuzzy::NotMinus1<int> expr;
    core::UnaryExpressionModel<int> model(&value, &expr);
	std::cout << "NotMinus1 : " << model.evaluate();
}

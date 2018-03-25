#include <iostream>

#include "core/BinaryExpressionModel.h"
#include "core/UnaryExpressionModel.h"
#include "core/ValueModel.h"
#include "fuzzy/AndMin.h"
#include "fuzzy/CogDefuzz.h"
#include "fuzzy/IsTriangle.h"
#include "fuzzy/OrMax.h"

using namespace core;
using namespace fuzzy;

int main(int argc, char* const argv[]) {
	CogDefuzz<float> opDefuzz(0, 5, 1);
	IsTriangle<float> cheap(0, 5, 10);

	ValueModel<float> output(0);
	ValueModel<float> val(2);
	UnaryExpressionModel<float> cheapModel(&val, &cheap);
	float eval = opDefuzz.evaluate(&output, &cheapModel);
	std::cout << eval << std::endl;
}

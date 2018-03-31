
#include <iostream>

#include "core/UnaryExpressionModel.h"
#include "core/ValueModel.h"
#include "fuzzy/AggMax.h"
#include "fuzzy/AndMin.h"
#include "fuzzy/CogDefuzz.h"
#include "fuzzy/FuzzyFactory.h"
#include "fuzzy/IsTriangle.h"
#include "fuzzy/NotMinus1.h"
#include "fuzzy/OrMax.h"
#include "fuzzy/ThenMin.h"

using namespace core;
using namespace fuzzy;

void tipsExample() {
	// operators
	NotMinus1<float> opeNot;
	AndMin<float> opeAnd;
	OrMax<float> opeOr;
	ThenMin<float> opeThen;
	AggMax<float> opeAgg;
	CogDefuzz<float> opDefuzz(0, 25, 1);

	// FuzzyFactory(Not<T> *opNot, And<T> *opAnd, Or<T> *opOr, Then<T> *opThen, Agg<T> *opAgg, MamdaniDefuzz<T> *opDeffuzz);
	FuzzyFactory<float> factory(&opeNot, &opeAnd, &opeOr, &opeThen, &opeAgg, &opDefuzz);

	IsTriangle<float> poor(-5, 0, 5);
	IsTriangle<float> good(0, 5, 10);
	IsTriangle<float> excellent(5, 10, 15);

	IsTriangle<float> cheap(0, 5, 10);
	IsTriangle<float> average(10, 15, 20);
	IsTriangle<float> generous(20, 25, 30);

	ValueModel<float> service(0);
	ValueModel<float> food(0);
	ValueModel<float> tips(0);

	Expression<float> *expr = factory.newAgg(
			factory.newAgg(
					factory.newThen(factory.newIs(&poor, &service), factory.newIs(&cheap, &tips)),
					factory.newThen(factory.newIs(&good, &service), factory.newIs( &average, &service))
			),
			factory.newThen(factory.newIs(&excellent, &service), factory.newIs(&generous, &tips)
			)
	);
	Expression<float> *system = factory.newDefuzz(&tips, expr);

	float s;
	while (true) {
		std::cout << "Service : ";
		std::cin >> s;
		service.setValue(&s);
		std::cout << "Tips -> " << system->evaluate() << std::endl;
	}
}

int main(int argc, char* const argv[]) {
//	CogDefuzz<float> opDefuzz(0, 5, 1);
//	IsTriangle<float> cheap(0, 5, 10);
//
//	ValueModel<float> output(0);
//	ValueModel<float> val(2);
//	UnaryExpressionModel<float> cheapModel(&val, &cheap);
//	float eval = opDefuzz.evaluate(&output, &cheapModel);
//	std::cout << eval << std::endl;
	tipsExample();
}

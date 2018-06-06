#include <iostream>
#include <stdexcept>
#include <vector>

#include "core/Expression.h"
#include "core/ValueModel.h"
#include "fuzzy/AggMax.h"
#include "fuzzy/AndMin.h"
#include "fuzzy/CogDefuzz.h"
#include "fuzzy/FuzzyFactory.h"
#include "fuzzy/IsTriangle.h"
#include "fuzzy/NotMinus1.h"
#include "fuzzy/OrMax.h"
#include "fuzzy/SugenoConclusion.h"
#include "fuzzy/SugenoDefuzz.h"
#include "fuzzy/SugenoThen.h"
#include "fuzzy/ThenMin.h"

using namespace core;
using namespace fuzzy;

void tipsMamdani() {
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
	ValueModel<float> tips(0);

	Expression<float> *expr = factory.newAgg(
			factory.newAgg(
					// IF service is poor, THEN tips are cheap
					factory.newThen(
							factory.newIs(&poor, &service),
							factory.newIs(&cheap, &tips)
					),
					// IF service is good, THEN tips are average
					factory.newThen(
							factory.newIs(&good, &service),
							factory.newIs( &average, &service)
					)
			),
			// IF service is excellent, THEN tips are generous
			factory.newThen(
					factory.newIs(&excellent, &service),
					factory.newIs(&generous, &tips)
			)
	);
	Expression<float> *system = factory.newDefuzz(&tips, expr);

	std::cout << "Mamdani inference system test." << std::endl;
	float s;
	while (true) {
		std::cout << "Service : ";
		std::cin >> s;
		service.setValue(&s);
		try {
			std::cout << "Tips -> " << system->evaluate() << std::endl;
		} catch (std::runtime_error& e) {
			std::cout << e.what() << std::endl;
		}
	}
}

void tipsSugeno() {
	// operators
	NotMinus1<float> opeNot;
	AndMin<float> opeAnd;
	OrMax<float> opeOr;
	SugenoThen<float> opeThen;
	AggMax<float> opeAgg;
	CogDefuzz<float> opeMamdani(5, 25, 1);
	SugenoDefuzz<float> opeSugeno;

	std::vector<float> coefs;
	coefs.push_back(1);
	coefs.push_back(1);
	SugenoConclusion<float> opeConclusion(coefs);

	FuzzyFactory<float> factory(&opeNot, &opeAnd, &opeOr, &opeThen, &opeAgg, &opeMamdani, &opeSugeno, &opeConclusion);

	// Membership functions for service
	IsTriangle<float> poor(-5, 0, 5);
	IsTriangle<float> good(0, 5, 10);
	IsTriangle<float> excellent(5, 10, 15);
	// Membership functions for food
	IsTriangle<float> rancid(-5, 0, 5);
	IsTriangle<float> delicious(5,10,15);

	ValueModel<float> service(0);

	std::vector<Expression<float> *> serviceConcl;
	serviceConcl.push_back(&service);

	// Rules
	std::vector<Expression<float> *> rules;
	rules.push_back(
			factory.newThen(
					factory.newIs(&poor, &service),
					factory.newConclusion(&serviceConcl)
			)
	);

	rules.push_back(factory.newThen(
			factory.newIs(&good, &service),
			factory.newConclusion(&serviceConcl))
	);

	rules.push_back(
			factory.newThen(
					factory.newIs(&excellent, &service),
					factory.newConclusion(&serviceConcl)
			)
	);

	Expression<float> *system = factory.newSugeno(&rules);
	std::cout << "Sugeno inference system test." << std::endl;
	float s;
	while (true) {
		std::cout << "Service : ";
		std::cin >> s;
		service.setValue(&s);
		try {
			std::cout << "Tips -> " << system->evaluate() << std::endl;
		} catch (std::runtime_error& e) {
			std::cout << e.what() <<std::endl;
		}
	}
}

void gradesMamdani() {
	// operators
	NotMinus1<float> opeNot;
	AndMin<float> opeAnd;
	OrMax<float> opeOr;
	ThenMin<float> opeThen;
	AggMax<float> opeAgg;
	CogDefuzz<float> opDefuzz(0, 20, 1);

	FuzzyFactory<float> factory(&opeNot, &opeAnd, &opeOr, &opeThen, &opeAgg, &opDefuzz);

	// Input variables : care and work
	ValueModel<float> care(0);
	ValueModel<float> work(0);

	// Output : grade
	ValueModel<float> grade(0);

	// Membership functions
	IsTriangle<float> poor(-5, 0, 5);
	IsTriangle<float> good(0, 5, 10);
	IsTriangle<float> excellent(10, 20, 30);
	IsTriangle<float> bad(0, 5, 10);
	IsTriangle<float> careful(10, 15, 20);

	Expression<float> *expr = factory.newAgg(
			factory.newAgg(
					// IF work IS poor OR care is bad THEN grade IS bad
					factory.newThen(
							factory.newOr(
									factory.newIs(&poor, &work),
									factory.newIs(&bad, &care)
							),
							factory.newIs(&bad, &grade)
					),
					// IF work IS good THEN grade IS good
					factory.newThen(
							factory.newIs(&good, &work),
							factory.newIs(&good, &grade)
					)
			),
			// IF work IS excellent AND care IS good THEN grade IS excellent
			factory.newThen(
					factory.newAnd(
							factory.newIs(&excellent, &work),
							factory.newIs(&careful, &care)
					),
					factory.newIs(&excellent, &grade)
			)
	);

	Expression<float> *system = factory.newDefuzz(&grade, expr);

	std::cout << "Grades test." << std::endl;
	float s;
	while (true) {
		std::cout << "Work : ";
		std::cin >> s;
		work.setValue(&s);
		std::cout << "Care : ";
		std::cin >> s;
		care.setValue(&s);
		try {
			std::cout << "Grade -> " << system->evaluate() << std::endl;
		} catch (std::runtime_error& e) {
			std::cout << e.what() << std::endl;
		}
	}

	}
int main(void) {
	//tipsMamdani();
	//tipsSugeno();
	gradesMamdani();
}

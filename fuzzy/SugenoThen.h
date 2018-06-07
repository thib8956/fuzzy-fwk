#ifndef CORE_SUGENOTHEN_H_
#define CORE_SUGENOTHEN_H_

#include <iostream>

#include "../core/Expression.h"
#include "../core/Then.h"

namespace fuzzy {

template <typename T>
class SugenoThen : public core::Then<T> {
public:
	SugenoThen();
	virtual ~SugenoThen() = default;

	virtual T evaluate(core::Expression<T> *left, core::Expression<T> *right) const;
	virtual T getPremiseValue() const;

private:
	mutable T premiseValue;
};

template <typename T>
SugenoThen<T>::SugenoThen() : premiseValue(0) {}

template <typename T>
T SugenoThen<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const {
	premiseValue = left->evaluate();
	T rightEval = right->evaluate();
	return premiseValue * rightEval;
}

template <typename T>
T SugenoThen<T>::getPremiseValue() const {
		return premiseValue;
}

}

#endif /* CORE_SUGENOTHEN_H_ */

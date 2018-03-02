#ifndef ANDMIN_H_
#define ANDMIN_H_

#include "../core/And.h"
#include "../core/Expression.h"

namespace fuzzy {

template<typename T>
class AndMin: public core::And<T> {
public:
	virtual ~AndMin() = default;
	virtual T evaluate(core::Expression<T> *left, core::Expression<T> *right) const;
};

template<class T>
T AndMin<T>::evaluate(core::Expression<T> *left, core::Expression<T> *right) const {
	T leftEval, rightEval;
	leftEval = left->evaluate();
	rightEval = right->evaluate();
	if (leftEval > rightEval) {
		return rightEval;
	} else {
		return leftEval;
	}
}

}

#endif

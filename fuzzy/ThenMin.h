#ifndef THENMIN_H_
#define THENMIN_H_

#include "../core/Then.h"
#include "../core/Expression.h"

namespace fuzzy {

template<typename T>
class ThenMin: public core::Then<T> {
public:
	virtual ~ThenMin() = default;
	virtual T evaluate(core::Expression<T> *left, core::Expression<T> *right) const;
};

template<class T>
T ThenMin<T>::evaluate(core::Expression<T> *left, core::Expression<T> *right) const {
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

#ifndef AGGMAX_H_
#define AGGMAX_H_

#include "../core/Expression.h"
#include "../core/Agg.h"

namespace fuzzy {

template <typename T>
class AggMax : public core::Agg<T> {
public:
	virtual ~AggMax() = default;
	virtual T evaluate(core::Expression<T> *left, core::Expression<T> *right) const;
};

template <typename T>
T AggMax<T>::evaluate(core::Expression<T> *left, core::Expression<T> *right) const {
	T leftEval = left->evaluate();
	T rightEval = right->evaluate();

	return (leftEval < rightEval) ? rightEval : leftEval;
}

}

#endif /* AGGMAX_H_ */

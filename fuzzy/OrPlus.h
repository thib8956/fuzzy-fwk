#ifndef ORPLUS_H_
#define ORPLUS_H_

#include "../core/Expression.h"
#include "../core/Or.h"

namespace fuzzy {

template <typename T>
class OrPlus : public core::Or<T> {
public:
	virtual ~OrPlus() = default;
	virtual T evaluate(core::Expression<T> *left, core::Expression<T> *right) const;
};

template <typename T>
T OrPlus<T>::evaluate(core::Expression<T> *left, core::Expression<T> *right) const {
	return left->evaluate() + right->evaluate();
}
}



#endif /* ORPLUS_H_ */

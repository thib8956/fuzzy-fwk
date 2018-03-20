#ifndef AGGPLUS_H_
#define AGGPLUS_H_

#include "../core/Expression.h"
#include "../core/Agg.h"

namespace fuzzy {

template <typename T>
class AggPlus : public core::Agg<T> {
public:
	virtual ~AggPlus() = default;
	virtual T evaluate(core::Expression<T> *left, core::Expression<T> *right) const;
};

template <typename T>
T AggPlus<T>::evaluate(core::Expression<T> *left, core::Expression<T> *right) const {
	return left->evaluate() + right->evaluate();
}
}



#endif /* AGGPLUS_H_ */

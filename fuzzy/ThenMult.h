#ifndef THENMULT_H_
#define THENMULT_H_

#include "../core/Then.h"
#include "../core/Expression.h"

namespace fuzzy {

template<typename T>
class ThenMult: public core::Then<T> {
public:
	virtual ~ThenMult() = default;
	virtual T evaluate(core::Expression<T> *left, core::Expression<T> *right) const;
};

template<typename T>
T ThenMult<T>::evaluate(core::Expression<T> *left, core::Expression<T> *right) const {
	return left->evaluate() * right->evaluate();
}

}

#endif /* THENMULT_H_ */

#ifndef ANDMULT_H_
#define ANDMULT_H_

#include "../core/And.h"
#include "../core/Expression.h"

namespace fuzzy {

template<typename T>
class AndMult: public core::And<T> {
public:
	virtual ~AndMult() = default;
	virtual T evaluate(core::Expression<T> *left, core::Expression<T> *right) const;
};

template<class T>
T AndMult<T>::evaluate(core::Expression<T> *left, core::Expression<T> *right) const {
	return left->evaluate() * right->evaluate();
}

}

#endif /* ANDMULT_H_ */

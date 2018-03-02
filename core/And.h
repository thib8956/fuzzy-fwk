#ifndef AND_H_
#define AND_H_

#include "Expression.h"
#include "BinaryExpression.h"

namespace core {

template<typename T>
class And: public BinaryExpression<T> {
public:
	virtual ~And() = default;
	virtual T evaluate(Expression<T> *left, Expression<T> *right) const = 0;
};

}

#endif

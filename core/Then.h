#ifndef THEN_H_
#define THEN_H_

#include "Expression.h"
#include "BinaryExpression.h"

namespace core {

template<typename T>
class Then: public BinaryExpression<T> {
public:
	virtual ~Then() = default;
	virtual T evaluate(Expression<T> *left, Expression<T> *right) const = 0;
};

}

#endif

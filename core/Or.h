#ifndef OR_H_
#define OR_H_

#include "BinaryExpression.h"

namespace core {

template <typename T>
class Or : public BinaryExpression<T> {
public:
	virtual ~Or() = default;
	virtual T evaluate(Expression<T> *left, Expression<T> *right) const = 0;
};

}



#endif /* OR_H_ */

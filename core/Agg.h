#ifndef AGG_H_
#define AGG_H_

#include "BinaryExpression.h"

namespace core {

template <typename T>
class Agg : public BinaryExpression<T> {
public:
	virtual ~Agg() = default;
	virtual T evaluate(Expression<T> *left, Expression<T> *right) const = 0;
};

}



#endif /* AGG_H_ */

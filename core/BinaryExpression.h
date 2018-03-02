#ifndef BINARYEXPRESSION_H_
#define BINARYEXPRESSION_H_

#include "Expression.h"

namespace core {
	template <typename T>
	class BinaryExpression {
	public:
		virtual ~BinaryExpression() = default;
		virtual T evaluate(Expression<T> *left, Expression<T> *right) const = 0;
	};
}



#endif /* BINARYEXPRESSION_H_ */

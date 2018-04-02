#ifndef NARYEXPRESSION_H_
#define NARYEXPRESSION_H_

#include "Expression.h"

namespace core {
	template <typename T>
	class NaryExpression {
	public:
		virtual ~NaryExpression() = default;
		virtual T evaluate(Expression<T> operands[]) const = 0;
	};
}

#endif /* NARYEXPRESSION_H_ */

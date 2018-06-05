#ifndef NARYEXPRESSION_H_
#define NARYEXPRESSION_H_

#include <vector>

#include "Expression.h"

namespace core {
	template <typename T>
	class NaryExpression {
	public:
		virtual ~NaryExpression() = default;
		virtual T evaluate(std::vector<Expression<T>*> *operands) const = 0;
	};
}

#endif /* NARYEXPRESSION_H_ */

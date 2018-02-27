#ifndef UNARYEXPRESSION_H_
#define UNARYEXPRESSION_H_

#include "Expression.h"

namespace core {
	template <typename T>
	class UnaryExpression {
	public:
		virtual ~UnaryExpression() = default;
		virtual T evaluate(Expression<T> *expression) const = 0;
	};

	template <typename T>
	class Not : public UnaryExpression<T> {
	public:
		virtual ~Not() = default;
		virtual T evaluate(Expression<T> *expression) const = 0;
	};
}  // namespace core

#endif /* UNARYEXPRESSION_H_ */

#ifndef IS_H_
#define IS_H_

#include "Expression.h"
#include "UnaryExpression.h"

namespace core {
	template <typename T>
	class Is : public UnaryExpression<T> {
	public:
		virtual ~Is() = default;
		virtual T evaluate(Expression<T> *expression) const = 0;
	};
}  // namespace core

#endif /* IS_H_ */

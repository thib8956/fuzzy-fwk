#ifndef NOT_H_
#define NOT_H_

#include "Expression.h"
#include "UnaryExpression.h"

namespace core {
	template <typename T>
	class Not : public UnaryExpression<T> {
	public:
		virtual ~Not() = default;
		virtual T evaluate(Expression<T> *expression) const = 0;
	};
}  // namespace core

#endif /* NOT_H_ */

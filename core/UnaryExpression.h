#ifndef UNARYEXPRESSION_H_
#define UNARYEXPRESSION_H_

namespace core {
	template <typename T>
	class UnaryExpression {
	public:
		virtual ~UnaryExpression() = default;
		virtual T* evaluate(T* expression) const = 0;
	};
}  // namespace core

#endif /* UNARYEXPRESSION_H_ */

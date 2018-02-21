#ifndef EXPRESSION_H_
#define EXPRESSION_H_

namespace core {
	template <typename T>
	class Expression {
	public:
		virtual ~Expression() = default;
		virtual T evaluate() const = 0;
	};
}

#endif /* EXPRESSION_H_ */

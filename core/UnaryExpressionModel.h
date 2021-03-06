#ifndef UNARYEXPRESSIONMODEL_H_
#define UNARYEXPRESSIONMODEL_H_

#include "../exceptions/OperandException.h"
#include "../exceptions/OperatorException.h"
#include "Expression.h"
#include "UnaryExpression.h"

namespace core {

	template <typename T>
	class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T> {
	public:
		virtual ~UnaryExpressionModel() = default;

		UnaryExpressionModel(Expression<T> *operand, UnaryExpression<T> *ope);

		virtual T evaluate() const;
		virtual T evaluate(Expression<T> *expression) const;

	private:
		Expression<T> *operand;
		UnaryExpression<T> *ope; // operator
	};

	template<typename T>
	UnaryExpressionModel<T>::UnaryExpressionModel(Expression<T> *operand,
			UnaryExpression<T> *ope):operand(operand), ope(ope) {}

	template <typename T>
	T UnaryExpressionModel<T>::evaluate() const {
		if (operand == nullptr) {
			throw exceptions::OperandException("Operand is null");
		}
		return this->evaluate(operand);
	}

	template <typename T>
	T UnaryExpressionModel<T>::evaluate(Expression<T> *expression) const {
		if (ope == nullptr) {
			throw exceptions::OperatorException("Operator is null");
		}
		return ope->evaluate(expression);
	}

}  // namespace core

#endif /* UNARYEXPRESSIONMODEL_H_ */

#ifndef BINARYEXPRESSIONMODEL_H_
#define BINARYEXPRESSIONMODEL_H_

#include "../exceptions/OperandException.h"
#include "../exceptions/OperatorException.h"
#include "BinaryExpression.h"
#include "Expression.h"

namespace core {


template <typename T>
class BinaryExpressionModel : public Expression<T>, public BinaryExpression<T> {
public:
	BinaryExpressionModel(BinaryExpression<T> *ope, Expression<T> *left, Expression<T> *right);
	virtual ~BinaryExpressionModel() = default;

	virtual T evaluate() const;
	virtual T evaluate(Expression<T> *left, Expression<T> *right) const;
	const BinaryExpression<T>* getOperator() const;

private:
	BinaryExpression<T> *ope; // operator
	Expression<T> *left;
	Expression<T> *right;
};

template <typename T>
BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T> *ope, Expression<T> *left, Expression<T> *right) :
ope(ope), left(left), right(right) {}

template <typename T>
T BinaryExpressionModel<T>::evaluate() const {
	if (ope == nullptr) {
		throw exceptions::OperatorException("Operator is null");
	}
	return ope->evaluate(left, right);
}

template <typename T>
T BinaryExpressionModel<T>::evaluate(Expression<T> *left, Expression<T> *right) const {
	if (left == nullptr ||right == nullptr) {
		throw exceptions::OperandException("Operand is null");
	}
	return evaluate(left, right);
}

template <typename T>
const BinaryExpression<T>* core::BinaryExpressionModel<T>::getOperator() const {
	return ope;
}

}

#endif /* BINARYEXPRESSIONMODEL_H_ */

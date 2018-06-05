#ifndef NARYEXPRESSIONMODEL_H_
#define NARYEXPRESSIONMODEL_H_

#include <stddef.h>
#include <vector>

#include "../exceptions/OperandException.h"
#include "../exceptions/OperatorException.h"
#include "Expression.h"
#include "NaryExpression.h"

namespace core {

template <typename T>
class NaryExpressionModel : public NaryExpression<T>, public Expression<T> {
public:
	NaryExpressionModel(NaryExpression<T> *ope, std::vector<Expression<T>*> *operands);
	virtual ~NaryExpressionModel() = default;

	virtual T evaluate() const;
	virtual T evaluate(std::vector<Expression<T>*> *operands) const;

private:
	NaryExpression<T> *ope; // n-ary operator
	std::vector<Expression<T>*> *operands;
};

template<typename T>
NaryExpressionModel<T>::NaryExpressionModel(NaryExpression<T>* ope,
		std::vector<Expression<T>*> *operands) :
		ope(ope), operands(operands) {
}

template<typename T>
T NaryExpressionModel<T>::evaluate() const {
	if (operands->empty()) {
		throw exceptions::OperandException("Operands is empty.");
	}
	return evaluate(operands);
}

template<typename T>
T NaryExpressionModel<T>::evaluate(std::vector<Expression<T>*> *operands) const {
	if (operands->empty()) {
		throw exceptions::OperandException("Operands is empty.");
	}
	if (ope == NULL) {
		throw exceptions::OperatorException("Operator is null.");
	}
	return ope->evaluate(operands);
}

}

#endif /* NARYEXPRESSIONMODEL_H_ */

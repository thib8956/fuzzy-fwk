#ifndef NARYEXPRESSIONMODEL_H_
#define NARYEXPRESSIONMODEL_H_

#include "Expression.h"
#include "NaryExpression.h"

namespace core {

template <typename T>
class NaryExpressionModel : public NaryExpression<T>, public Expression<T> {
public:
	NaryExpressionModel(NaryExpression<T> *ope, Expression<T> *operands[]);
	virtual ~NaryExpressionModel() = default;

	virtual T evaluate() const;
	virtual T evaluate(Expression<T> *operands[]) const;

private:
	Expression<T> *operands[];
	NaryExpression<T> *ope; // n-ary operator
};

template<typename T>
NaryExpressionModel<T>::NaryExpressionModel(NaryExpression<T>* ope,
		Expression<T>* operands[]) :
		ope(ope), operands(operands) {
}

template<typename T>
T NaryExpressionModel<T>::evaluate() const {
	if (operands == NULL) {
		// TODO handle exception
		return 0;
	}
	return ope->evaluate(operands);
}

template<typename T>
T NaryExpressionModel<T>::evaluate(Expression<T> *operands[]) const {
	if (operands == NULL) {
		// TODO handle exception
		return 0;
	}
	return evaluate(operands);
}

}

#endif /* NARYEXPRESSIONMODEL_H_ */

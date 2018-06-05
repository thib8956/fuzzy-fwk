#ifndef EXPRESSIONFACTORY_H_
#define EXPRESSIONFACTORY_H_

#include <set>
#include <vector>

#include "BinaryExpression.h"
#include "BinaryExpressionModel.h"
#include "Expression.h"
#include "NaryExpression.h"
#include "NaryExpressionModel.h"
#include "UnaryExpression.h"
#include "UnaryExpressionModel.h"
#include "ValueModel.h"

namespace core {

template <typename T>
class ExpressionFactory {
public:
	virtual ~ExpressionFactory();
	virtual Expression<T>* hold(Expression<T> *expression);
	virtual ValueModel<T>* newValue(T value);

protected:
	virtual Expression<T>* newUnary(UnaryExpression<T> *ope, Expression<T> *expression);
	virtual Expression<T>* newBinary(BinaryExpression<T> *ope, Expression<T> *left, Expression<T> *right);
	virtual Expression<T>* newNAry(NaryExpression<T> *ope, std::vector<Expression<T>*> operands);

private:
	std::set<Expression<T>*> memory;
};

template <typename T>
ExpressionFactory<T>::~ExpressionFactory() {
	for (const auto *expr : memory) {
		delete(expr);
	}
}

template <typename T>
Expression<T>* ExpressionFactory<T>::hold(Expression<T> *expression) {
	memory.insert(expression);
	return expression;
}

template <typename T>
ValueModel<T>* ExpressionFactory<T>::newValue(T value) {
	return static_cast<ValueModel<T> *>(hold(new ValueModel<T>(value)));
}

template <typename T>
Expression<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T> *ope, Expression<T> *expression) {
	return hold(new UnaryExpressionModel<T>(expression, ope));
}

template <typename T>
Expression<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T> *ope, Expression<T> *left, Expression<T> *right) {
	return hold(new BinaryExpressionModel<T>(ope, left, right));
}

template <typename T>
Expression<T>* ExpressionFactory<T>::newNAry(NaryExpression<T> *ope, std::vector<Expression<T>*> operands) {
	return hold(new NaryExpressionModel<T>(ope, operands));
}


}

#endif /* EXPRESSIONFACTORY_H_ */

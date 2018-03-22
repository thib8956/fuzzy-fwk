#ifndef EXPRESSIONFACTORY_H_
#define EXPRESSIONFACTORY_H_

#include <set>

#include "BinaryExpression.h"
#include "BinaryExpressionModel.h"
#include "Expression.h"
#include "UnaryExpression.h"
#include "UnaryExpressionModel.h"
#include "ValueModel.h"

namespace core {

template <typename T>
class ExpressionFactory {
public:
	virtual ~ExpressionFactory();
	virtual Expression<T>* hold(Expression<T> *expression);
	virtual Expression<T>* newValue(T *value);

protected:
	virtual Expression<T>* newUnary(UnaryExpression<T> *ope, Expression<T> *expression);
	virtual Expression<T>* newBinary(BinaryExpression<T> *ope, Expression<T> *left, Expression<T> *right);

private:
	std::set<Expression<T>*> memory;
};

template <typename T>
ExpressionFactory<T>::~ExpressionFactory() {
	/*for (typename std::set<Expression<T>*>::iterator it = memory.begin(); it < memory.end(); it++) {
		delete(*it);
	}*/
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
Expression<T>* ExpressionFactory<T>::newValue(T *value) {
	return new ValueModel<T>(*value);
}

template <typename T>
Expression<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T> *ope, Expression<T> *expression) {
	return new UnaryExpressionModel<T>(expression, ope);
}

template <typename T>
Expression<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T> *ope, Expression<T> *left, Expression<T> *right) {
	return new BinaryExpressionModel<T>(ope, left, right);
}

}

#endif /* EXPRESSIONFACTORY_H_ */

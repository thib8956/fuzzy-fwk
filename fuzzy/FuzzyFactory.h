#ifndef FUZZYFACTORY_H_
#define FUZZYFACTORY_H_

#include "../core/Agg.h"
#include "../core/And.h"
#include "../core/BinaryShadowExpression.h"
#include "../core/Expression.h"
#include "../core/ExpressionFactory.h"
#include "../core/Is.h"
#include "../core/Not.h"
#include "../core/Or.h"
#include "../core/Then.h"
#include "../core/UnaryShadowExpression.h"

using namespace core;

namespace fuzzy {

template <typename T>
class FuzzyFactory : public ExpressionFactory<T> {
public:
	FuzzyFactory(Not<T> *opNot, And<T> *opAnd, Or<T> *opOr, Then<T> *opThen, Agg<T> *opAgg);
	// TODO : add defuzz, is and shape
	Expression<T>* newAnd(Expression<T> *left, Expression<T> *right);
	Expression<T>* newOr(Expression<T> *left, Expression<T> *right);
	Expression<T>* newThen(Expression<T> *left, Expression<T> *right);
	Expression<T>* newAgg(Expression<T> *left, Expression<T> *right);
	Expression<T>* newNot(Expression<T> *expr);

	Expression<T>* changeAnd(And<T> *o);
	Expression<T>* changeOr(Or<T> *o);
	Expression<T>* changeThen(Then<T> *o);
	Expression<T>* changeAgg(And<T> *o);
	Expression<T>* changeNot(Not<T> *o);


private:
	UnaryShadowExpression<T> opNot;
	BinaryShadowExpression<T> opAnd;
	BinaryShadowExpression<T> opOr;
	BinaryShadowExpression<T> opThen;
	BinaryShadowExpression<T> opAgg;
};

template<typename T>
FuzzyFactory<T>::FuzzyFactory(Not<T> *opNot, And<T> *opAnd, Or<T> *opOr, Then<T> *opThen, Agg<T> *opAgg) :
opNot(opNot), opAnd(opAnd), opOr(opOr), opThen(opThen), opAgg(opAgg) {
}

template<typename T>
Expression<T>* FuzzyFactory<T>::newAnd(Expression<T> *left, Expression<T> *right) {
	return newBinary(opAnd, *left, *right);
}

template<typename T>
Expression<T>* FuzzyFactory<T>::newOr(Expression<T> *left, Expression<T> *right) {
	return newBinary(opOr, *left, *right);
}

template<typename T>
Expression<T>* FuzzyFactory<T>::newThen(Expression<T> *left, Expression<T> *right) {
	return newBinary(opThen, *left, *right);
}

template<typename T>
Expression<T>* FuzzyFactory<T>::newAgg(Expression<T> *left, Expression<T> *right) {
	return newBinary(opAgg, *left, *right);
}

template<typename T>
Expression<T>* FuzzyFactory<T>::newNot(Expression<T> *expr) {
	return newUnary(opNot, expr);
}

template<typename T>
Expression<T>* FuzzyFactory<T>::changeAnd(And<T> *o) {
	opAnd->setTarget(o);
	return this;
}

template<typename T>
Expression<T>* FuzzyFactory<T>::changeOr(Or<T> *o) {
	opOr->setTarget(o);
	return this;
}

template<typename T>
Expression<T>* FuzzyFactory<T>::changeThen(Then<T> *o) {
	opThen->setTarget(o);
	return this;
}

template<typename T>
Expression<T>* FuzzyFactory<T>::changeAgg(And<T> *o) {
	opAgg->setTarget(o);
	return this;
}

template<typename T>
Expression<T>* FuzzyFactory<T>::changeNot(Not<T> *o) {
	opNot->setTarget(o);
	return *this;
}

}

#endif /* FUZZYFACTORY_H_ */

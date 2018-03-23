#ifndef MAMDANIDEFUZZ_H_
#define MAMDANIDEFUZZ_H_

#include "../core/BinaryExpression.h"
#include "../core/Evaluator.h"
#include "../core/Expression.h"

using namespace core;

namespace fuzzy{

template <typename T>
class MamdaniDefuzz : public BinaryExpression<T>{
public:
	T evaluate(Expression<T>* l,Expression<T>* r) const=0;
	virtual ~MamdaniDefuzz() = default;
	virtual T defuzz(const typename Evaluator<T>::Shape&) const=0;
	virtual typename Evaluator<T>::Shape buildShape(Expression<T> *in, Expression<T> *out) const=0;
};






}
#endif //MAMDANIDEFUZZ_H_

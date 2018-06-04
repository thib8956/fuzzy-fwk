#ifndef NARYSHADOWEXPRESSION_H_
#define NARYSHADOWEXPRESSION_H_

#include "../exceptions/EvaluationException.h"
#include "Expression.h"
#include "NaryExpression.h"

namespace core {

template <typename T>

class NaryShadowExpression : public NaryExpression<T> {
public:
	NaryShadowExpression(NaryExpression<T> *target=nullptr);
	virtual ~NaryShadowExpression() = default;

	virtual T evaluate(Expression<T> *operands[]) const;
	const NaryExpression<T>* getTarget() const;
	void setTarget(const NaryExpression<T> *target);

private:
	NaryExpression<T> *target;
};

template<typename T>
NaryShadowExpression<T>::NaryShadowExpression(NaryExpression<T>* target) :
target(target) {
}

template<typename T>
T NaryShadowExpression<T>::evaluate(Expression<T>* operands[]) const {
	if (target == nullptr) {
		throw exceptions::EvaluationException("Target is null");
	}
	return target->evaluate(operands);
}

template <typename T>
const NaryExpression<T>* core::NaryShadowExpression<T>::getTarget() const {
	return target;
}

template <typename T>
void NaryShadowExpression<T>::setTarget(const NaryExpression<T> *target) {
	this->target = target;
}

}

#endif /* NARYSHADOWEXPRESSION_H_ */

#ifndef BINARYSHADOWEXPRESSION_H_
#define BINARYSHADOWEXPRESSION_H_

#include "BinaryExpression.h"
#include "Expression.h"

namespace core {
	template <typename T>
    class BinaryShadowExpression : public BinaryExpression<T> {
	public:
		BinaryShadowExpression(BinaryExpression<T> *target = nullptr);
		virtual ~BinaryShadowExpression() = default;
		virtual T evaluate(Expression<T> *left, Expression<T> *right) const;
		const BinaryExpression<T>* getTarget() const;
		void setTarget(BinaryExpression<T>* target);

    private:
        BinaryExpression<T> *target; // target
	};

	template<typename T>
	BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* target) : target(target) {
	}

    template <typename T>
    T BinaryShadowExpression<T>::evaluate(Expression<T> *left, Expression<T> *right) const {
        if (target == nullptr) {
        	throw exceptions::EvaluationException("Target is null");
        }
        return target->evaluate(left, right);
    }

    template <typename T>
    const BinaryExpression<T>* BinaryShadowExpression<T>::getTarget() const {
    	return target;
    }

    template <typename T>
    void BinaryShadowExpression<T>::setTarget(BinaryExpression<T>* target) {
    	this->target = target;
    }
} // namespace core

#endif /* BINARYSHADOWEXPRESSION_H_ */

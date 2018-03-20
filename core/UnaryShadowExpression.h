#ifndef UNARYSHADOWEXPRESSION_H_
#define UNARYSHADOWEXPRESSION_H_

#include "Expression.h"
#include "UnaryExpression.h"

namespace core {
	template <typename T>
    class UnaryShadowExpression : public UnaryExpression<T>{
	public:
		UnaryShadowExpression(UnaryExpression<T> *target = nullptr);
		virtual ~UnaryShadowExpression() = default;
		virtual T evaluate(Expression<T> *expression) const;
		const UnaryExpression<T>* getTarget() const;
		void setTarget(UnaryExpression<T>* target);

    private:
        UnaryExpression<T> *target;
    };

	template <typename T>
	UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T> *target) :	target(target) {
	}
    
    template <typename T>
    T UnaryShadowExpression<T>::evaluate(Expression<T> *expression) const {
        if (target != nullptr) {
            return target->evaluate(expression);
        }
        return T();
    }
    
    template <typename T>
    const UnaryExpression<T>* UnaryShadowExpression<T>::getTarget() const {
    	return target;
    }

    template <typename T>
    void UnaryShadowExpression<T>::setTarget(UnaryExpression<T>* target) {
    	this->target = target;
    }

}  // namespace core

#endif /* UNARYSHADOWEXPRESSION_H_ */

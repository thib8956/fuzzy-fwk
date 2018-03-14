#ifndef UNARYSHADOWEXPRESSION_H_
#define UNARYSHADOWEXPRESSION_H_

#include "UnaryExpression.h"

namespace core {
	template <typename T>
    class UnaryShadowExpression : public UnaryExpression<T>{
	public:
		virtual ~UnaryShadowExpression() = default;
		virtual T evaluate(Expression<T> *expression);
    private:
        UnaryExpression<T> *target; // target
    };
    
    
    template <typename T>
    T UnaryShadowExpression<T>::evaluate(Expression<T> *expression) const {
        if (target != nullptr) {
            return target->evaluate(expression);
        }
        return T();
    }
    
}  // namespace core

#endif /* UNARYSHADOWEXPRESSION_H_ */

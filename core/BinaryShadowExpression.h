#ifndef BINARYSHADOWEXPRESSION_H_
#define BINARYSHADOWEXPRESSION_H_

#include "BinaryExpression.h"

namespace core {
	template <typename T>
    class BinaryShadowExpression : public BinaryExpression{
	public:
		virtual ~BinaryShadowExpression() = default;
		virtual T evaluate(Expression<T> *left, Expression<T> *right);
    private:
        BinaryExpression<T> *target; // target
	};
    
    template <typename T>
    T BinaryShadowExpression<T>::evaluate(Expression<T> *left, Expression<T> *right) const {
        if (target != nullptr) {
            return target->evaluate(left,right);
        }
        return T();
    }
} // namespace core



#endif /* BINARYSHADOWEXPRESSION_H_ */

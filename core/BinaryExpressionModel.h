#ifndef BINARYEXPRESSION_H_
#define BINARYEXPRESSION_H_

#include "Expression.h"
using namespace std;

namespace core {
	template <typename T>
	class BinaryExpressionModel: public BinaryExpression {
	public:

		BinaryExpressionModel();
		virtual ~BinaryExpressionModel();
		virtual T* evaluate(Expression *left, Expression *right) const;
		virtual T* evaluate() const;
	private:
		BinaryExpression<T> &be;
		Expression<T> &left;
		Expression<T> &right;
	};

template <class T>
BinaryExpressionModel<T>::BinaryExpressionModel(){

}

template <class T>
BinaryExpressionModel<T>::~BinaryExpressionModel(){

}

template <class T>
T* BinaryExpressionModel<T>::evaluate(Expression *left, Expression *right){
	if(operator !=nullptr){
		return operator.evaluate(left,right);
	}

}

template <class T>
T* BinaryExpressionModel<T>::evaluate(){
	if(left != nullptr && right != nullptr){
		return evaluate(left,right);
	}
}

}



#endif /* BINARYEXPRESSION_H_ */

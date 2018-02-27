#ifndef BINARYEXPRESSION_H_
#define BINARYEXPRESSION_H_

#include "BinaryExpression.h"
using namespace std;

namespace core {
	template <typename T>
	class BinaryExpressionModel: public BinaryExpression<T> {
	public:

		BinaryExpressionModel();
		virtual ~BinaryExpressionModel();
		virtual T* evaluate(Expression<T> *left, Expression<T> *right) const;
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
T* BinaryExpressionModel<T>::evaluate(Expression<T> *left, Expression<T> *right) const{
	if(be !=nullptr){
		return be->evaluate(left,right);
	}
	return 0;
}

template <class T>
T* BinaryExpressionModel<T>::evaluate() const{
	if(left != nullptr && right != nullptr){
		return evaluate(left,right);
	}
	return 0;
}

}



#endif /* BINARYEXPRESSION_H_ */

#ifndef ANDMIN_H_
#define ANDMIN_H_

#include "Expression.h"
using namespace std;

namespace core {
	template <typename T>
	class AndMin : public And<T> {
	public:
		//AndMin();
		virtual T* evaluate(Expression<T> *left, Expression<T> *right) const;
		virtual ~AndMin();
	};

template <class T>
T* AndMin<T>::evaluate(Expression<T> *left, Expression<T> *right) const{
	T leftEval, rightEval;
	leftEval = left->evaluate();
	rightEval = right->evaluate();
	if(leftEval > rightEval){
		return rightEval;
	}
	else{
		return leftEval;
	}
}

template <class T>
AndMin<T>::~AndMin(){

}



}
#endif

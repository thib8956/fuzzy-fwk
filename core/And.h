#ifndef AND_H_
#define AND_H_

#include "BinaryExpression.h"
using namespace std;

namespace core {
	template <typename T>
	class And : public BinaryExpression<T> {
	public:
		virtual T* evaluate(Expression *left, Expression *right) const=0;
		virtual ~And();
	};

}
#endif

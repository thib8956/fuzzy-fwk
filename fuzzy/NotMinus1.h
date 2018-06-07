#ifndef NOTMINUS1_H_
#define NOTMINUS1_H_

#include "../core/Expression.h"
#include "../core/Not.h"

namespace fuzzy {

	template <typename T>
	class NotMinus1 : public core::Not<T> {
	public :
		virtual ~NotMinus1() = default;
		virtual T evaluate(core::Expression<T> *expression) const;
	};

	template<typename T>
	T NotMinus1<T>::evaluate(core::Expression<T> *expression) const {
		return 1 - expression->evaluate();
	}
}

#endif /* NOTMINUS1_H_ */

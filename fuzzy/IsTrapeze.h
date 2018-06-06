#ifndef FUZZY_ISTRAPEZE_H_
#define FUZZY_ISTRAPEZE_H_

#include "../core/Expression.h"
#include "../core/Is.h"

namespace fuzzy {

template <typename T>
class IsTrapeze : public core::Is<T> {
public:
	IsTrapeze(T min, T midLow, T midHigh, T max);
	virtual ~IsTrapeze() = default;
	virtual T evaluate(core::Expression<T> *expression) const;
private:
	T min;
	T midLow;
	T midHigh;
	T max;
};

template <typename T>
IsTrapeze<T>::IsTrapeze(T min, T midLow, T midHigh, T max) :
min(min), midLow(midLow), midHigh(midHigh), max(max) {
}

template <typename T>
T IsTrapeze<T>::evaluate(core::Expression<T> *expression) const {
	T eval = expression->evaluate();
	if (eval < min || eval > max) {
		return 0;
	}
	if (eval < midLow ) {
		return (eval - min)/(midLow - min);
	}
	if (eval >= midHigh) {
		return (eval - max) / (midHigh - max);
	}
	return 0;
}

}

#endif /* FUZZY_ISTRAPEZE_H_ */

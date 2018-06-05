#ifndef ISTRIANGLE_H_
#define ISTRIANGLE_H_

#include "../core/Expression.h"
#include "../core/Is.h"
#include "../exceptions/OperandException.h"

namespace fuzzy {

template <typename T>
class IsTriangle : public core::Is<T> {
public:
	IsTriangle(T min=0, T mid=0, T max=0);
	virtual ~IsTriangle() = default;
	virtual T evaluate(core::Expression<T> *expression) const;

private:
	T min;
	T mid;
	T max;
};

template<typename T>
IsTriangle<T>::IsTriangle(T min, T mid, T max) : min(min), mid(mid), max(max) {
}

template <typename T>
T IsTriangle<T>::evaluate(core::Expression<T> *expression) const {
	T eval = expression->evaluate();

	if (eval < min || eval > max) {
		return 0;
	}

	return (eval < mid) ? (eval-min)/(mid-min) : (max-eval)/(max-mid);
}

}

#endif /* ISTRIANGLE_H_ */

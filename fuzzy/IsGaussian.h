#ifndef FUZZY_ISGAUSSIAN_H_
#define FUZZY_ISGAUSSIAN_H_

#include <cmath>

#define PI 3.1415

#include "../core/Expression.h"
#include "../core/Is.h"

namespace fuzzy {

template <typename T>
class IsGaussian : public core::Is<T> {
public:
	IsGaussian(T sigma, T mu);
	virtual ~IsGaussian() = default;
	virtual T evaluate(core::Expression<T> *expression) const;
private:
	T sigma;
	T mu;
};

template<typename T>
IsGaussian<T>::IsGaussian(T sigma, T mu) : sigma(sigma), mu(mu) {
}

template <typename T>
T IsGaussian<T>::evaluate(core::Expression<T> *expression) const {
	T eval = expression->evaluate();
	T num = exp(-.5 * pow((eval - mu) / sigma, 2));
	T den = sigma * sqrt(2 * PI);
	return num / den;
}

}

#endif /* FUZZY_ISGAUSSIAN_H_ */

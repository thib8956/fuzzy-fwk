#ifndef SUGENOCONCLUSION_H_
#define SUGENOCONCLUSION_H_

#include <vector>

#include "../core/Expression.h"
#include "../core/NaryExpression.h"

namespace fuzzy {

template <typename T>
class SugenoConclusion : public core::NaryExpression<T> {
public:
		SugenoConclusion(T *coeff);
		virtual ~SugenoConclusion() = default;
		virtual T evaluate(std::vector<const core::Expression<T>*> *operands) const;
private:
		const std::vector *coeff;
};

template <typename T>
SugenoConclusion<T>::SugenoConclusion(T *coeff) : coeff(coeff) {}

template <typename T>
T SugenoConclusion<T>::evaluate(std::vector<const core::Expression<T>*> *operands) const {
	T result = 0;
	auto itcoeff = coeff->begin();
	auto itexpr = operands->begin();
	for (; itexpr != operands->end() && itcoeff != coeff->end(); itexpr++, itcoeff++) {
		T eval = (*itexpr)->evaluate();
		result += *itcoeff * eval;
	}

	return result;
}

}

#endif /* SUGENOCONCLUSION_H_ */

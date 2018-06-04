#ifndef SUGENOCONCLUSION_H_
#define SUGENOCONCLUSION_H_

#include <vector>

#include "../core/Expression.h"
#include "../core/NaryExpression.h"

namespace fuzzy {

template <typename T>
class SugenoConclusion : public core::NaryExpression<T> {
public:
		virtual ~SugenoConclusion() = default;
		virtual T evaluate(std::vector<const core::Expression<T>*> *operands) const;
private:
		const std::vector *coeff;
};

template <typename T>
SugenoConclusion<T>::SugenoConclusion(T *coeff) : coeff(coeff) {}
	// TODO
	return NULL;
}

}

#endif /* SUGENOCONCLUSION_H_ */

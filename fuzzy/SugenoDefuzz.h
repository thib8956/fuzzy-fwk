#ifndef SUGENODEFUZZ_H_
#define SUGENODEFUZZ_H_

#include <vector>

#include "../core/BinaryExpressionModel.h"
#include "../core/BinaryShadowExpression.h"
#include "../core/Expression.h"
#include "../core/NaryExpression.h"

namespace fuzzy {

template <typename T>
class SugenoDefuzz : public core::NaryExpression<T> {
public:
		virtual ~SugenoDefuzz() = default;
		virtual T evaluate(std::vector<const core::Expression<T>*> *operands) const;
};

template <typename T>
T SugenoDefuzz<T>::evaluate(std::vector<const core::Expression<T>*> *operands) const {
	T num = 0;
	T denum = 0;

	for (auto it = operands->begin(); it != operands->end(); it++) {
		core::BinaryExpressionModel<T> *expressionModel = static_cast<core::BinaryExpressionModel<T> *>(*it);
		core::BinaryShadowExpression<T> *shadow = static_cast<core::BinaryShadowExpression<T> *>(expressionModel->getOperator());
		SugenoThen<T> *sugenoThen = static_cast<SugenoThen<T> *>(shadow->getTarget());
		T premise = sugenoThen->getPremiseValue();

		num += premise * (*it)->evaluate();
		denum += premise;
	}
	// TODO: check denum != O
	return num / denum;
}
}

#endif /* SUGENODEFUZZ_H_ */

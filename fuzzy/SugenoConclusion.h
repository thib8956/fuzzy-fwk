#ifndef SUGENOCONCLUSION_H_
#define SUGENOCONCLUSION_H_

#include "../core/Expression.h"
#include "../core/NaryExpression.h"

namespace fuzzy {

template <typename T>
class SugenoConclusion : public core::NaryExpression<T> {
public:
		virtual ~SugenoConclusion() = default;
		virtual T evaluate(core::Expression<T> operands[]);
private:
		T coeff[];
};

template <typename T>
T SugenoConclusion<T>::evaluate(core::Expression<T> operands[]) {
	// TODO
	return NULL;
}

}

#endif /* SUGENOCONCLUSION_H_ */

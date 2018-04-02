#ifndef SUGENODEFUZZ_H_
#define SUGENODEFUZZ_H_

#include "../core/Expression.h"
#include "../core/NaryExpression.h"

namespace fuzzy {

template <typename T>

class SugenoDefuzz : public core::NaryExpression<T> {
public:
		virtual ~SugenoDefuzz() = default;
		virtual T evaluate(core::Expression<T> operands[]);
};

template <typename T>
T SugenoDefuzz<T>::evaluate(core::Expression<T> operands[]) {
	// TODO
	return NULL;
}
}

#endif /* SUGENODEFUZZ_H_ */

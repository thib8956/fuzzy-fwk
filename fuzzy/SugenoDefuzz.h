#ifndef SUGENODEFUZZ_H_
#define SUGENODEFUZZ_H_

#include <vector>

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
	// TODO
	return NULL;
}
}

#endif /* SUGENODEFUZZ_H_ */

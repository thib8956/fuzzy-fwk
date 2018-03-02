#ifndef VALUEMODEL_H_
#define VALUEMODEL_H_

#include "Expression.h"

namespace core {

	template <typename T>
	class ValueModel : public Expression<T> {
	public:
		virtual ~ValueModel() = default;
		ValueModel(T value);

		virtual T evaluate() const;
		virtual void setValue(T *v);

	private:
		T value;
	};

	template <typename T>
	ValueModel<T>::ValueModel(T value) : value(value) {}

	template <typename T>
	T ValueModel<T>::evaluate() const {
		return value;
	}

	template <typename T>
	void ValueModel<T>::setValue(T *v) {
		value = *v;
	}

}  // namespace core

#endif /* VALUEMODEL_H_ */

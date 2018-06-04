#ifndef COGDEFUZZ_H_
#define COGDEFUZZ_H_

#include "../core/Evaluator.h"
#include "../core/Expression.h"
#include "../core/ValueModel.h"
#include "../exceptions/EvaluationException.h"
#include "MamdaniDefuzz.h"

namespace fuzzy{

template <typename T>
class CogDefuzz : public MamdaniDefuzz<T>
{
public:
	CogDefuzz(T min, T max, T step);
	T evaluate(Expression<T>* l,Expression<T>* r) const;
	virtual ~CogDefuzz() = default;
	T defuzz(const typename Evaluator<T>::Shape &shape) const;
	typename Evaluator<T>::Shape buildShape(Expression<T> *in, Expression<T> *out) const;

private:
	T min;
	T max;
	T step;
};

template <class T>
CogDefuzz<T>::CogDefuzz(T min, T max, T step): min(min),max(max),step(step) {}

template <class T>
T CogDefuzz<T>::evaluate(Expression<T>* l,Expression<T>* r) const {
	return defuzz(buildShape(l,r));
}

template <class T>
T CogDefuzz<T>::defuzz(const typename Evaluator<T>::Shape &shape) const {
	// Calcul du centre de gravité **Méthode d'approximation par rectangle**
	T den = 0;
	T num = 0;
	for(unsigned int i = 0; i<shape.first.size();i++){
		num = num + shape.first.at(i) * shape.second.at(i); //Somme de x*y
		den = den + shape.second.at(i); // somme de y
	}

	if (den == 0) throw  exceptions::DefuzzException("Denominator is null");
	return num/den;
}

template <class T>
typename Evaluator<T>::Shape CogDefuzz<T>::buildShape(Expression<T> *in, Expression<T> *out) const{
	return Evaluator<T>::buildShape(min,max,step,(ValueModel<T>*) in, out);
}

}
#endif //COGDEFUZZ_H_

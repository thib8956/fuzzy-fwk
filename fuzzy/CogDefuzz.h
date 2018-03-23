#ifndef COGDEFUZZ_H_
#define COGDEFUZZ_H_

#include "../core/Evaluator.h"
#include "../core/Expression.h"
#include "MamdaniDefuzz.h"


namespace fuzzy{
template <typename T>
class CogDefuzz : public MamdaniDefuzz<T>
{
public:
	CogDefuzz(T , T , T );
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
CogDefuzz<T>::CogDefuzz(T min, T max, T step): min(min),max(max),step(step){}

template <class T>
T CogDefuzz<T>::evaluate(Expression<T>* l,Expression<T>* r) const{
	return defuzz(buildShape(l,r));
}

template <class T>
T CogDefuzz<T>::defuzz(const typename Evaluator<T>::Shape &shape) const{
	//Calcul du centre de gravité **Méthode d'approximation par rectange**
	T dem = 0;
	T num = 0;
	for(int i = 0; i<shape.first.size();i++){
		num = num + shape.first.at(i)*shape.second.at(i); //Somme de x*y
		dem = dem + shape.second.at(i); // somme de y
	}
	return num/dem;
}

template <class T>
typename Evaluator<T>::Shape CogDefuzz<T>::buildShape(Expression<T> *in, Expression<T> *out) const{
	return Evaluator<T>::buildShape(min,max,step,(ValueModel<T>*) in, out);
}


}
#endif //COGDEFUZZ_H_

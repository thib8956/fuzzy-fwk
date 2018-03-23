#ifndef EVALUATOR_H_
#define EVALUATOR_H_

#include <iostream>
#include <utility>
#include <vector>

#include "Expression.h"

using namespace std;

namespace core {



template <typename T>
class Evaluator
{
public:
	typedef pair<vector<T>,vector<T> > Shape;
	static Shape buildShape(const T& min, const T& max, const T& step, ValueModel<T> *in, Expression<T> *out);
};



template <class T>
typename Evaluator<T>::Shape Evaluator<T>:: buildShape(const T& min, const T& max, const T& step, ValueModel<T> *in, Expression<T> *out) {
	vector<T> x, y;
	for (T i= min ;i <= max ;i += step) {
		in->setValue(&i); //step pour pouvoir evaluer la Value
		y.push_back(out->evaluate()); //Construction de la forme par valeur de y en avancant sur x
		x.push_back(i); }
	return Shape(x,y);
}



}
#endif //EVALUATOR_H_

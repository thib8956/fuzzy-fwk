#include <iostream>

#include "core/ValueModel.h"

int main(int argc, char* const argv[]) {
	core::ValueModel<int> value;
	int v(2);
	value.setValue(&v);

	std::cout << "Value : " << value.evaluate() << std::endl;
}

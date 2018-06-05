#ifndef EXCEPTIONS_OPERANDEXCEPTION_H_
#define EXCEPTIONS_OPERANDEXCEPTION_H_

#include <stdexcept>
#include <string>

namespace exceptions {

struct OperandException : public std::runtime_error {
	OperandException(const std::string& msg) : std::runtime_error(msg) {}
	const char* what() const _GLIBCXX_USE_NOEXCEPT override {
		return this->what();
	}
};

}  // namespace exceptions

#endif /* EXCEPTIONS_OPERANDEXCEPTION_H_ */

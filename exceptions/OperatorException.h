#ifndef EXCEPTIONS_OPERATOREXCEPTION_H_
#define EXCEPTIONS_OPERATOREXCEPTION_H_

#include <stdexcept>
#include <string>

namespace exceptions {

struct OperatorException : public std::runtime_error {
	OperatorException(const std::string& msg) : std::runtime_error(msg) {}
	const char* what() const _GLIBCXX_USE_NOEXCEPT override {
		return std::runtime_error::what();
	}
};

}  // namespace exceptions

#endif /* EXCEPTIONS_OPERATOREXCEPTION_H_ */

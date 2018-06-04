#ifndef EXCEPTIONS_OPERATOREXCEPTION_H_
#define EXCEPTIONS_OPERATOREXCEPTION_H_

#include <stdexcept>
#include <string>

namespace exceptions {

class OperatorException : public std::runtime_error {
public:
	OperatorException(const std::string& msgs);
	const char* what() override;
private:
	const std::string message;

};

OperatorException::OperatorException(const std::string& msg) : message(msg) {}

const char* OperatorException::what() {
	return message.c_str();
}

}  // namespace exceptions

#endif /* EXCEPTIONS_OPERATOREXCEPTION_H_ */

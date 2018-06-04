#ifndef EXCEPTIONS_OPERANDEXCEPTION_H_
#define EXCEPTIONS_OPERANDEXCEPTION_H_

#include <stdexcept>
#include <string>

namespace exceptions {

class OperandException : public std::runtime_error {
public:
	OperandException(const std::string& msg);
	const char* what() override;
private:
	const std::string message;

};

OperandException::OperandException(const std::string& msg) : message(msg) {}

const char* OperandException::what() {
	return message.c_str();
}

}  // namespace exceptions

#endif /* EXCEPTIONS_OPERANDEXCEPTION_H_ */

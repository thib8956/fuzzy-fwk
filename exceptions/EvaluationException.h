#ifndef EXCEPTIONS_EVALUATIONEXCEPTION_H_
#define EXCEPTIONS_EVALUATIONEXCEPTION_H_

#include <stdexcept>
#include <string>

namespace exceptions {

class EvaluationException : public std::runtime_error {
public :
	EvaluationException(const std::string& msg);
	const char* what() override;
private:
	const std::string msg;
}

EvaluationException::EvaluationException(const std::string& msg) : msg(msg) {}

const char* EvaluationException::what() {
	return msg.c_str();
}


}

#endif /* EXCEPTIONS_EVALUATIONEXCEPTION_H_ */

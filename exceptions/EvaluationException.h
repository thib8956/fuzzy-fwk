#ifndef EXCEPTIONS_EVALUATIONEXCEPTION_H_
#define EXCEPTIONS_EVALUATIONEXCEPTION_H_

#include <stdexcept>
#include <string>

namespace exceptions {

struct EvaluationException : public std::runtime_error {
	EvaluationException(const std::string & msg) : std::runtime_error(msg) {}
	const char* what() const _GLIBCXX_USE_NOEXCEPT {
		return this->what();
	}
};

}

#endif /* EXCEPTIONS_EVALUATIONEXCEPTION_H_ */

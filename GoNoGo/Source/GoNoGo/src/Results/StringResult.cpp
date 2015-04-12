#include "GoNoGo.h"
#include <Results/StringResult.hpp>

StringResult::StringResult() : StringResult("", INVALID) { }

StringResult::StringResult(std::string Result) : StringResult(Result, INVALID) { }

StringResult::StringResult(std::string Result, RESULT_STATUSES Status) : ResultBase(Status)
{
	this->_result = Result;

	return;
}

const std::string StringResult::GetResult()
{
	return this->_result;
}

std::string StringResult::ToJson()
{
	std::stringstream ss;
	ss << "{ status: '" << this->_status << "', result: '" << this->_result << "' }";

	return ss.str();
}

#include "GoNoGo.h"
#include <Results/IntResult.hpp>

IntResult::IntResult() : IntResult(0, INVALID) { }

IntResult::IntResult(int Result) : IntResult(Result, INVALID) { }

IntResult::IntResult(int Result, RESULT_STATUSES Status) : ResultBase(Status)
{
	this->_result = Result;

	return;
}

const int IntResult::GetResult()
{
	return this->_result;
}

std::string IntResult::ToJson()
{
	std::stringstream ss;
	ss << "{ status: '" << this->_status << "', result: '" << this->_result << "' }";

	return ss.str();
}

#pragma once

#include <Core.hpp>
#include <BaseClasses/ResultBase.hpp>

class StringResult : public ResultBase
{
private:
	std::string _result;

public:
	StringResult();
	StringResult(std::string Result);
	StringResult(std::string Result, RESULT_STATUSES Status);

	const std::string GetResult();
	std::string ToJson();
};

#pragma once

#include <BaseClasses/ResultBase.hpp>

class IntResult : public ResultBase
{
private:
	int _result;

public:
	IntResult();
	IntResult(int Result);
	IntResult(int Result, RESULT_STATUSES Status);

	const int GetResult();
	std::string ToJson();
};

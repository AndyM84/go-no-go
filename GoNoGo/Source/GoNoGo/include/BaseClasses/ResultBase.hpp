#pragma once

#include <Core.hpp>

class ResultBase
{
protected:
	RESULT_STATUSES _status;

public:
	ResultBase();
	ResultBase(RESULT_STATUSES Status);

	const RESULT_STATUSES GetStatus();
	virtual std::string ToJson();
};

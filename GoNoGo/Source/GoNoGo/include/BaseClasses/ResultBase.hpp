#pragma once

#include <string>
#include <sstream>

enum RESULT_STATUSES
{
	INVALID = 0,
	GO,
	NO_GO
};

class ResultBase
{
protected:
	RESULT_STATUSES _status;

	void SetStatus(RESULT_STATUSES Status);

public:
	ResultBase();
	ResultBase(RESULT_STATUSES Status);

	const RESULT_STATUSES GetStatus();
	virtual std::string ToJson();
};

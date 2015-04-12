#pragma once

#include <string>

class ResultBase
{
	virtual std::string ToJson() = 0;
};

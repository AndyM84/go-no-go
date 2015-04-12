#include "GoNoGo.h"
#include <BaseClasses/ResultBase.hpp>

ResultBase::ResultBase()
{
	return;
}

ResultBase::ResultBase(RESULT_STATUSES Status)
{
	this->_status = Status;

	return;
}

void ResultBase::SetStatus(RESULT_STATUSES Status)
{
	return;
}

const RESULT_STATUSES ResultBase::GetStatus()
{
	return this->_status;
}

std::string ResultBase::ToJson()
{
	std::stringstream ss;
	ss << "{ status: '" << this->_status << "' }";

	return ss.str();
}

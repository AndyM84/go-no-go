#include "GoNoGo.h"
#include <BaseClasses/HoldBase.hpp>

HoldBase::HoldBase() : HoldBase("HoldBase", INVALID)
{ }

HoldBase::HoldBase(std::string Key, RESULT_STATUSES Status)
{
	this->SetKey(Key.c_str());
	this->SetVersion("1.0");
	this->_status = Status;
	this->_isHolding = false;

	return;
}

void HoldBase::CompleteHold(RESULT_STATUSES Status)
{
	if (!this->_isHolding)
	{
		return;
	}

	time(&this->_holdCompleted);
	this->_status = Status;

	return;
}

void HoldBase::StartHold()
{
	if (this->_isHolding)
	{
		return;
	}

	this->_isHolding = true;
	time(&this->_holdStarted);
	time(&this->_holdUpdated);

	return;
}

void HoldBase::UpdateHold()
{
	if (!this->_isHolding)
	{
		return;
	}

	time(&this->_holdUpdated);

	return;
}

const time_t HoldBase::GetHoldCompletedTime()
{
	return this->_holdCompleted;
}

const time_t HoldBase::GetHoldStartedTime()
{
	return this->_holdStarted;
}

const time_t HoldBase::GetHoldUpdatedTime()
{
	return this->_holdUpdated;
}

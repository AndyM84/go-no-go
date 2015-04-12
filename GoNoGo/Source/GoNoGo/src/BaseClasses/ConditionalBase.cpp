#include "GoNoGo.h"
#include <BaseClasses/ConditionalBase.hpp>

ConditionalBase::ConditionalBase() : ConditionalBase("ConditionalBase", INVALID)
{

}

ConditionalBase::ConditionalBase(std::string Key, RESULT_STATUSES Status)
{
	this->SetKey(Key.c_str());
	this->SetVersion("1.0");
	this->_status = Status;
	time(&this->_statusUpdated);
}

void ConditionalBase::UpdateStatus() {
	time(&this->_statusUpdated);

}

time_t ConditionalBase::GetStatusUpdateTime() {

	return this->_statusUpdated;

}

void ConditionalBase::SetStatus(RESULT_STATUSES Status) {
	this->_status = Status;
	this->UpdateStatus();
}
#include "GoNoGo.h"
#include <BaseClasses/ResultBase.hpp>

void ResultBase::SetStatus(RESULT_STATUS Status)
{
	return;
}

RESULT_STATUS ResultBase::GetStatus()
{
	return this->_status;
}

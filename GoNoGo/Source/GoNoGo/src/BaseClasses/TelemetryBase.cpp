#include "GoNoGo.h"
#include <BaseClasses/TelemetryBase.hpp>

TelemetryBase::TelemetryBase(std::string ModuleID, std::string Name, float Frame, float Delta)
{
	this->_moduleID = ModuleID;
	this->_name = Name;
	this->_frame = Frame;
	this->_delta = Delta;

	return;
}

float TelemetryBase::GetDelta()
{
	return this->_delta;
}

float TelemetryBase::GetFrame()
{
	return this->_frame;
}

std::string TelemetryBase::GetModuleID()
{
	return this->_moduleID;
}

std::string TelemetryBase::GetName()
{
	return this->_name;
}

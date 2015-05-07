#pragma once

#include <Core.hpp>
#include <BaseClasses/DispatchBase.hpp>

class TelemetryBase : public N2f::DispatchBase
{
protected:
	std::string _moduleID, _name;
	float _frame, _delta;

public:
	TelemetryBase(std::string ModuleID, std::string Name, float Frame, float Delta);

	const float GetDelta();
	const float GetFrame();
	const std::string GetModuleID();
	const std::string GetName();
};

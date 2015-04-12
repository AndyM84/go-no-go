#pragma once

#include "Engine.h"
#include <BaseClasses/HoldBase.hpp>

class FuelLoadHold : public HoldBase {

private:

	FVector2D _reportedFuelLevel;
	RESULT_STATUSES _previousStatus;

public:

	FuelLoadHold();
	FuelLoadHold(RESULT_STATUSES PreviousStatus);

	void SetFuelLevel(FVector2D fuelLevel);
	FVector2D getFuelLevel();

	void Process(void *Sender, std::shared_ptr<N2f::DispatchBase> Dispatch);

};


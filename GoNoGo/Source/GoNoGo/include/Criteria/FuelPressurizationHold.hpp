#include "Engine.h"
#include <BaseClasses/HoldBase.hpp>

class FuelPressurizationHold : public HoldBase {

private:

	FVector2D _reportedFuelPressure;
	RESULT_STATUSES _previousStatus;

public:

	FuelPressurizationHold();
	FuelPressurizationHold(RESULT_STATUSES PreviousStatus);

	void SetFuelPressure(FVector2D fuelPressure);
	FVector2D getFuelPressure();

	void Process(void *Sender, std::shared_ptr<N2f::DispatchBase> Dispatch);

};

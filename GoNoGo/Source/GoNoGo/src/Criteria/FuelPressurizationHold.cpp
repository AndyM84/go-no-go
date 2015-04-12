#include "GoNoGo.h"

#include <Criteria/FuelPressurizationHold.hpp>

FuelPressurizationHold::FuelPressurizationHold() : FuelPressurizationHold(INVALID) {
	FVector2D initialFuelPressure = FVector2D(0, 0);


}

FuelPressurizationHold::FuelPressurizationHold(RESULT_STATUSES PreviousStatus) : HoldBase("FuelPressure", PreviousStatus) {

	FVector2D initialFuelPressure = FVector2D(0, 0);

	_reportedFuelPressure = initialFuelPressure;
	_previousStatus = INVALID;
}

void FuelPressurizationHold::Process(void *Sender, std::shared_ptr<N2f::DispatchBase> Dispatch) {
	// TODO: Once Dispatch Base processes are put together, complete this class

}
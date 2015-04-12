#include "GoNoGo.h"

#include <Criteria/FuelLoadHold.hpp>

FuelLoadHold::FuelLoadHold() : FuelLoadHold(INVALID) {

}

FuelLoadHold::FuelLoadHold(RESULT_STATUSES PreviousStatus) : HoldBase("FuelLoad", PreviousStatus) {

	FVector2D initialFuelLevel = FVector2D(0, 0);

	_reportedFuelLevel = initialFuelLevel;
	_previousStatus = PreviousStatus;
}

void FuelLoadHold::Process(void *Sender, std::shared_ptr<N2f::DispatchBase> Dispatch) {
	// TODO: Once Dispatch Base processes are put together, complete this class

}
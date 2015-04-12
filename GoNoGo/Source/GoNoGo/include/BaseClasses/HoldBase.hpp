#pragma once

#include <Core.hpp>
#include <BaseClasses/DispatchBase.hpp>
#include <BaseClasses/NodeBase.hpp>

class HoldBase : public N2f::NodeBase
{
private:
	time_t _holdStarted, _holdCompleted, _holdUpdated;
	RESULT_STATUSES _status;
	bool _isHolding;

protected:
	void CompleteHold(RESULT_STATUSES Status);
	void StartHold();
	void UpdateHold();

public:
	HoldBase();
	HoldBase(std::string Key, RESULT_STATUSES Status);

	const time_t GetHoldCompletedTime();
	const time_t GetHoldStartedTime();
	const time_t GetHoldUpdatedTime();
	virtual void Process(void *Sender, std::shared_ptr<N2f::DispatchBase> Dispatch) = 0;
};

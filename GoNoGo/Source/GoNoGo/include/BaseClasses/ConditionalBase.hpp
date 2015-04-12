#pragma once

#include <Core.hpp>
#include <BaseClasses/NodeBase.hpp>

class ConditionalBase : public N2f::NodeBase
{
private:
	time_t _statusUpdated;
	RESULT_STATUSES _status;

protected:
	void UpdateStatus();
	void SetStatus(RESULT_STATUSES Status);

public:

	ConditionalBase();
	ConditionalBase(std::string Key, RESULT_STATUSES Status);

	time_t GetStatusUpdateTime();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Virtual to check isAcceptable. </summary>
	///
	/// <remarks>   Steven, 4/12/2015. </remarks>
	///
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual bool IsAcceptable() = 0;
};


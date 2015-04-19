#pragma once
#include <Core.hpp>
#include <BaseClasses/DispatchBase.hpp>
#include <BaseClasses/ConditionalBase.hpp>

using namespace N2f;

class WindConditional : public ConditionalBase
{
public:
	WindConditional();
	virtual ~WindConditional();
	
	void Process(void *Sender, std::shared_ptr<DispatchBase> Dispatch);
};


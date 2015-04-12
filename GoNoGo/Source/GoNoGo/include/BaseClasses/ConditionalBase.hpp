#pragma once

#include <Core.hpp>
#include <BaseClasses/NodeBase.hpp>

class ConditionalBase : public N2f::NodeBase
{
public:
	virtual	~ConditionalBase(){}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Virtual to check isAcceptable. </summary>
	///
	/// <remarks>   Steven, 4/12/2015. </remarks>
	///
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual bool IsAcceptable() = 0;
};

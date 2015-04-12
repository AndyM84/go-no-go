#pragma once

#include <BaseClasses/NodeBase.hpp>
#include <Results/VectorResult.hpp>

class ConditionalBase : public N2f::NodeBase
{
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Virtual method to determine if condition was met. </summary>
	///
	/// <remarks>	Steven, 4/12/2015. </remarks>
	///
	///////////////////////////////////////////////////////////////
	virtual VectorResult isAcceptable() = 0;

};

#pragma once

#include <BaseClasses/NodeBase.hpp>
#include <BaseClasses/VectorResult.hpp>

class ConditionalBase : public N2f::NodeBase
{
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Virtual to check isAcceptable. </summary>
	///
	/// <remarks>   Steven, 4/12/2015. </remarks>
	///
	////////////////////////////////////////////////////////////////////////////////////////////////////
	public virtual VectorResult isAcceptable() = 0;
};

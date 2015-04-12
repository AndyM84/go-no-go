#include "GoNoGo.h"
#include <Results/VectorResult.hpp>

double VectorResult::Normalise(const double value, const double start, const double end)
{
	const double width = end - start;   // 
	const double offsetValue = value - start;   // value relative to 0

	return (offsetValue - (floor(offsetValue / width) * width)) + start;
	// + start to reset back to start of original range
}

void VectorResult::SetMagnitude(const double mag)
{
	_magnitude = mag;

	return;
}

void VectorResult::SetDirection(const double dir)
{
	_direction = Normalise(dir, 0, 2 * PI);

	return;
}

void VectorResult::SetMagDir(const double mag, const double dir)
{
	_magnitude = mag;
	_direction = Normalise(dir, 0, 2 * PI);

	return;
}

double VectorResult::GetMagnitude()
{
	return _magnitude;
};

double VectorResult::GetDirection()
{
	return _direction;
};

std::string VectorResult::ToJson()
{
	std::stringstream ss;
	ss << "{magnitude:'" << _magnitude << "',direction:'" << _direction << "'}";

	return ss.str();
}

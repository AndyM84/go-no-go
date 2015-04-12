#pragma once

#include <math.h>
#include <sstream>
#include <BaseClasses/ResultBase.hpp>

class VectorResult : public ResultBase
{
private:
	double _magnitude, _direction;

	// In case we find we need them:
	//double degToRad(double deg) { return deg * PI / 180.0; };
	//double radToDeg(double rad) { return rad * 180.0 / PI; };

	//Normalizes any number to an arbitrary range 
	//by assuming the range wraps around when going below min or above max
	// Thank you: http://stackoverflow.com/questions/1628386/normalise-orientation-between-0-and-360
	double Normalise(const double value, const double start, const double end);

public:
	void SetMagnitude(const double mag);
	void SetDirection(const double dir);
	void SetMagDir(const double mag, const double dir);
	double GetMagnitude();
	double GetDirection();

	std::string ToJson();
};

#pragma once
#include <math.h>
#include <sstream>
#include <BaseClasses/ResultBase.hpp>

class VectorResult : public ResultBase
{
private:
	
	double magnitude;
	double direction;

	// In case we find we need them:
	//double degToRad(double deg) { return deg * PI / 180.0; };
	//double radToDeg(double rad) { return rad * 180.0 / PI; };

	//Normalizes any number to an arbitrary range 
	//by assuming the range wraps around when going below min or above max
	// Thank you: http://stackoverflow.com/questions/1628386/normalise-orientation-between-0-and-360
	double normalise(const double value, const double start, const double end)
	{
		const double width = end - start;   // 
		const double offsetValue = value - start;   // value relative to 0

		return (offsetValue - (floor(offsetValue / width) * width)) + start;
		// + start to reset back to start of original range
	}

public:
	void setMagnitude(const double mag) { magnitude = mag; };
	void setDirection(const double dir) { direction = normalise(dir, 0, 2 * PI); };
	void setMagDir(const double mag, const double dir) { magnitude = mag; direction = normalise(dir, 0, 2 * PI); };
	double getMagnitude() { return magnitude; };
	double getDirection() { return direction; };

	std::string ToJson() {
		std::stringstream ss;
		ss << "{magnitude:'" << magnitude << "',direction:'" << direction << "'}";
		return ss.str();
	}

};

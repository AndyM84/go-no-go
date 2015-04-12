#pragma once

#include <BaseClasses/ConditionalBase.hpp>
#include <BaseClasses/DispatchBase.hpp>
#include <BaseClasses/HoldBase.hpp>
#include <map>
#include <string>

class LaunchDispatch : public N2f::DispatchBase
{
public:
	typedef std::map<std::string, std::string> StringHash;
	typedef std::map<std::string, std::string>::iterator StringHashIter;

private:
	StringHash _holdResults, _conditionalResults;
	bool _isGo = false;

public:
	LaunchDispatch();
	LaunchDispatch(const LaunchDispatch &Dispatch);
	~LaunchDispatch();

	void Initialize();
	void Initialize(bool IsGo);
	void Initialize(bool IsGo, StringHash HoldResults, StringHash ConditionalResults);
	int NumResults();
	void SetGo(bool IsGo);
	void SetResult();
};

#pragma once

#include <BaseClasses/ConditionalBase.hpp>
#include <BaseClasses/DispatchBase.hpp>
#include <BaseClasses/HoldBase.hpp>
#include <BaseClasses/ResultBase.hpp>
#include <map>
#include <string>

class LaunchDispatch : public N2f::DispatchBase
{
public:
	typedef std::map<std::string, ResultBase> ResultHash;
	typedef std::pair<std::string, ResultBase> ResultHashPair;
	typedef std::map<std::string, ResultBase>::iterator ResultHashIter;

private:
	ResultHash _holdResults, _conditionalResults;
	bool _isGo = false, _catFail = false;

public:
	LaunchDispatch();
	~LaunchDispatch();

	template<class T> const ResultBase GetHoldResult(std::string Key)
	{
		if (this->_holdResults.find(Key) != this->_holdResults.end())
		{
			return static_cast<T>(this->_holdResults.find(Key)->second);
		}

		return ResultBase(INVALID);
	}

	template<class T> const ResultBase GetConditionalResult(std::string Key)
	{
		if (this->_conditionalResults.find(Key) != this->_conditionalResults.end())
		{
			return static_cast<T>(this->_conditionalResults.find(Key)->second);
		}

		return ResultBase(INVALID);
	}

	const ResultBase GetConditionalResult(std::string Key);
	const ResultHash GetConditionalResults();
	const ResultBase GetHoldResult(std::string Key);
	const ResultHash GetHoldResults();
	void Initialize();
	void Initialize(bool IsGo);
	int NumConditionalResults();
	int NumHoldResults();
	int NumResults();
	void SetConditionalResult(std::string Key, ResultBase Result);
	void SetGo(bool IsGo);
	void SetHoldResult(std::string Key, ResultBase Result);
	void SetResult();
	bool IsCatFail();
	bool IsConditionalGo(std::string Key);
	bool IsHoldGo(std::string Key);
};

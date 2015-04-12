#include "GoNoGo.h"
#include <Dispatches/LaunchDispatch.hpp>

LaunchDispatch::LaunchDispatch()
{
	return;
}

LaunchDispatch::~LaunchDispatch()
{
	this->_conditionalResults.clear();
	this->_holdResults.clear();

	return;
}

const ResultBase LaunchDispatch::GetConditionalResult(std::string Key)
{
	ResultHashIter res;

	if ((res = this->_conditionalResults.find(Key)) != this->_conditionalResults.end())
	{
		return res->second;
	}

	return ResultBase(INVALID);
}

const LaunchDispatch::ResultHash LaunchDispatch::GetConditionalResults()
{
	return this->_conditionalResults;
}

const ResultBase LaunchDispatch::GetHoldResult(std::string Key)
{
	ResultHashIter res;

	if ((res = this->_holdResults.find(Key)) != this->_holdResults.end())
	{
		return res->second;
	}

	return ResultBase(INVALID);
}

const LaunchDispatch::ResultHash LaunchDispatch::GetHoldResults()
{
	return this->_holdResults;
}

void LaunchDispatch::Initialize()
{
	this->MakeValid();

	return;
}

void LaunchDispatch::Initialize(bool IsGo)
{
	this->_isGo = IsGo;
	this->MakeValid();

	return;
}

int LaunchDispatch::NumConditionalResults()
{
	return this->_conditionalResults.size();
}

int LaunchDispatch::NumHoldResults()
{
	return this->_holdResults.size();
}

int LaunchDispatch::NumResults()
{
	return 0;
}

void LaunchDispatch::SetConditionalResult(std::string Key, ResultBase Result)
{
	if (this->_conditionalResults.find(Key) != this->_conditionalResults.end())
	{
		return;
	}

	this->_conditionalResults.emplace(Key, Result);

	return;
}

void LaunchDispatch::SetGo(bool IsGo)
{
	this->_isGo = IsGo;

	return;
}

void LaunchDispatch::SetHoldResult(std::string Key, ResultBase Result)
{
	if (this->_holdResults.find(Key) != this->_holdResults.end())
	{
		return;
	}

	this->_holdResults.emplace(Key, Result);

	return;
}

void LaunchDispatch::SetResult()
{
	return;
}

bool LaunchDispatch::IsCatFail()
{
	return this->_catFail;
}

bool LaunchDispatch::IsConditionalGo(std::string Key)
{
	ResultHashIter res;

	if ((res = this->_conditionalResults.find(Key)) != this->_conditionalResults.end())
	{
		return res->second.GetStatus() == GO;
	}

	return false;
}

bool LaunchDispatch::IsHoldGo(std::string Key)
{
	ResultHashIter res;

	if ((res = this->_holdResults.find(Key)) != this->_holdResults.end())
	{
		return res->second.GetStatus() == GO;
	}

	return false;
}

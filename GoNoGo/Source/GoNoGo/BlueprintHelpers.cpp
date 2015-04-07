// Fill out your copyright notice in the Description page of Project Settings.

#include "GoNoGo.h"
#include "BlueprintHelpers.h"

void UBlueprintHelpers::TestMethod(const float InputFloat1, float &FirstFloat, float &SecondFloat)
{
	float val = 3.14;
	FirstFloat = val;
	SecondFloat = val;

	return;
}

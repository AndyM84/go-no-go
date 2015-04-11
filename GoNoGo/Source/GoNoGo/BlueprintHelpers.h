// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <N2f.hpp>
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintHelpers.generated.h"

/**
 * 
 */
UCLASS()
class GONOGO_API UBlueprintHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Blueprint Tests")
	void TestMethod(const float InputFloat1, float &FirstFloat, float &SecondFloat);
};

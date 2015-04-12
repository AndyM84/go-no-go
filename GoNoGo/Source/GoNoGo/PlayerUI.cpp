// Fill out your copyright notice in the Description page of Project Settings.

#include "GoNoGo.h"
#include "PlayerUI.h"

UPlayerUI::UPlayerUI(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	this->_stage1Load = this->_stage1Pressure = this->_stage2Load = this->_stage2Pressure = FVector2D(0.0, 0.0);
	this->_hours = 0;
	this->_minutes = 0;
	this->_seconds = 56;
	this->_windAngle = 23;
	this->_counter = 0;

	return;
}

void UPlayerUI::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if (this->_seconds > 0 && this->_counter == 30)
	{
		this->_seconds -= 1;
		this->_counter = 0;
	}
	else
	{
		if (this->_minutes > 0)
		{
			this->_minutes--;
			this->_seconds = 60;
		}

		this->_counter++;
	}

	this->_stage1Load.X += 0.0023;
	this->_stage1Load.Y += 0.032;
	this->_stage2Load.X += 0.1;
	this->_stage2Load.Y += 0.0005;

	this->_stage1Pressure.X = 0.12;
	this->_stage1Pressure.Y = 0.34;
	this->_stage2Pressure.X = 0.73;
	this->_stage2Pressure.Y = 0.44;

	this->TickFuelLoad(this->_stage1Load.X, this->_stage1Load.Y, this->_stage2Load.X, this->_stage2Load.Y);
	this->TickFuelPressure(this->_stage1Pressure.X, this->_stage2Pressure.Y, this->_stage1Pressure.Y, this->_stage2Pressure.Y);
	this->TickWindGauge(this->_windAngle);
	this->TickCountdownTimer(this->_hours, this->_minutes, this->_seconds);

	return;
}

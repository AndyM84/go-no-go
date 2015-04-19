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

	UTexture2D *goTexture = ConstructorHelpers::FObjectFinder<UTexture2D>(TEXT("Texture2D'/Game/Textures/GO.GO'")).Object;
	this->_goButtonBrush.SetResourceObject(goTexture);
	this->_goButtonBrush.ImageSize = FVector2D(goTexture->GetSizeX(), goTexture->GetSizeY());

	UTexture2D *nogoTexture = ConstructorHelpers::FObjectFinder<UTexture2D>(TEXT("Texture2D'/Game/Textures/NOGO.NOGO'")).Object;
	this->_nogoButtonBrush.SetResourceObject(nogoTexture);
	this->_nogoButtonBrush.ImageSize = FVector2D(nogoTexture->GetSizeX(), nogoTexture->GetSizeY());

	return;
}

UPlayerUI::~UPlayerUI()
{
	if (this->_buttonStates.size() > 0)
	{
		this->_buttonStates.clear();
	}

	return;
}

void UPlayerUI::NativeTick(const FGeometry &MyGeometry, float InDeltaTime)
{
	DidTick(InDeltaTime);
}

void UPlayerUI::DidTick_Implementation(float &DeltaTime)
{
	return;
}

void UPlayerUI::ReceiveTick(FVector2D &Stage1FuelLoad, FVector2D &Stage2FuelLoad, FVector2D &Stage1FuelPressure, FVector2D &Stage2FuelPressure, float &WindDirection, int32 &Hours, int32 &Minutes, int32 &Seconds)
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

	Stage1FuelLoad = this->_stage1Load;
	Stage2FuelLoad = this->_stage2Load;
	Stage1FuelPressure = this->_stage1Pressure;
	Stage2FuelPressure = this->_stage2Pressure;
	WindDirection = this->_windAngle;
	Hours = this->_hours;
	Minutes = this->_minutes;
	Seconds = this->_seconds;

	this->OnTickReceived.Broadcast(12.0);

	return;
}

void UPlayerUI::ToggleButton(const FString ButtonKey, FButtonStyle &ButtonStyle, FString &ButtonText)
{
	bool btnState = false;
	std::map<const FString, bool>::iterator found = this->_buttonStates.find(ButtonKey);

	if (found != this->_buttonStates.end())
	{
		btnState = found->second;
	}

	btnState = !btnState;

	FButtonStyle style;
	style.Normal = style.Hovered = style.Pressed = (btnState) ? this->_goButtonBrush : this->_nogoButtonBrush;

	FString text = (btnState) ? "GO" : "NO GO";

	ButtonStyle = style;
	ButtonText = text;

	if (found != this->_buttonStates.end())
	{
		this->_buttonStates[ButtonKey] = btnState;
	}
	else
	{
		this->_buttonStates.insert(std::pair<const FString, bool>(ButtonKey, btnState));
	}

	return;
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "GoNoGo.h"
#include "PlayerUI.h"

void UPlayerUI::AddButtonState(const FString Key, bool State)
{
	std::map<const FString, bool>::iterator found = this->_buttonStates.find(Key);

	if (found != this->_buttonStates.end())
	{
		this->_buttonStates[Key] = State;
	}
	else
	{
		this->_buttonStates.insert(std::pair<const FString, bool>(Key, State));
	}

	return;
}

int32 UPlayerUI::LaunchEndState()
{
	if (this->_isTicking)
	{
		return 2;
	}

	for (auto it = this->_buttonStates.begin(); it != this->_buttonStates.end(); it++)
	{
		if (!it->second)
		{
			return 1;
		}
	}

	if (this->_windVelocity > 1.2 && (this->_windAngle > 1 && this->_windAngle < 25))
	{
		return 2;
	}

	if (this->_stage1Load.X < 1 || this->_stage1Load.Y < 1 || this->_stage2Load.X < 1 || this->_stage2Load.Y < 1)
	{
		return 2;
	}

	return 0;
}

UPlayerUI::UPlayerUI(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	this->_stage1Load = this->_stage1Pressure = this->_stage2Load = this->_stage2Pressure = FVector2D(0.0, 0.0);
	this->_hours = 0;
	this->_minutes = 1;
	this->_seconds = 4;
	this->_windAngle = 23;
	this->_windVelocity = 0.4;
	this->_counter = 0;
	this->_isTicking = false;

	UTexture2D *goTexture = ConstructorHelpers::FObjectFinder<UTexture2D>(TEXT("Texture2D'/Game/Textures/GO.GO'")).Object;
	this->_goButtonBrush.SetResourceObject(goTexture);
	this->_goButtonBrush.ImageSize = FVector2D(goTexture->GetSizeX(), goTexture->GetSizeY());

	UTexture2D *nogoTexture = ConstructorHelpers::FObjectFinder<UTexture2D>(TEXT("Texture2D'/Game/Textures/NOGO.NOGO'")).Object;
	this->_nogoButtonBrush.SetResourceObject(nogoTexture);
	this->_nogoButtonBrush.ImageSize = FVector2D(nogoTexture->GetSizeX(), nogoTexture->GetSizeY());

	this->AddButtonState(TEXT("TG_FT_01"), false);
	this->AddButtonState(TEXT("TG_FT_02"), false);
	this->AddButtonState(TEXT("TG_FT_03"), false);
	this->AddButtonState(TEXT("TG_FT_04"), false);
	this->AddButtonState(TEXT("WP"), false);
	this->AddButtonState(TEXT("TG_PG_01"), false);
	this->AddButtonState(TEXT("TG_PG_02"), false);
	this->AddButtonState(TEXT("TG_PG_03"), false);
	this->AddButtonState(TEXT("TG_PG_04"), false);

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

void UPlayerUI::GetPSIAngle(const float PSI, float &Angle)
{
	float ag = ((270 * PSI) / 120) - 135;
	Angle = ag;

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

	this->AddButtonState(ButtonKey, btnState);

	return;
}

void UPlayerUI::ToggleTick()
{
	this->_isTicking = !this->_isTicking;

	return;
}

void UPlayerUI::DoTick()
{
	if (this->_isTicking)
	{
		if (this->_counter == 30)
		{
			if (this->_seconds > 0)
			{
				--this->_seconds;
			}
			else if (this->_seconds == 0)
			{
				if (this->_minutes > 0)
				{
					--this->_minutes;
					this->_seconds = 59;
				}
				else if (this->_minutes == 0 && this->_hours > 0)
				{
					--this->_hours;
					this->_minutes = 59;
					this->_seconds = 59;
				}
				else
				{
					this->_isTicking = false;
					this->LaunchCompleted.Broadcast(this->LaunchEndState());

					return;
				}
			}

			this->_counter = 0;
		}
		else
		{
			++this->_counter;
		}

		this->_stage1Load.X += 0.0023;
		this->_stage1Load.Y += 0.012;
		this->_stage2Load.X += 0.01;
		this->_stage2Load.Y += 0.0005;

		this->_stage1Pressure.X = 23;
		this->_stage1Pressure.Y = 16;
		this->_stage2Pressure.X = 44;
		this->_stage2Pressure.Y = 86;

		this->TClockTicked.Broadcast(this->_hours, this->_minutes, this->_seconds);
		this->Stage1FuelLoaded.Broadcast(this->_stage1Load.X, this->_stage1Load.Y);
		this->Stage2FuelLoaded.Broadcast(this->_stage2Load.X, this->_stage2Load.Y);
		this->Stage1FuelPressurized.Broadcast(this->_stage1Pressure.X, this->_stage1Pressure.Y);
		this->Stage2FuelPressurized.Broadcast(this->_stage2Pressure.X, this->_stage2Pressure.Y);
		this->WindPulsed.Broadcast(this->_windAngle, this->_windVelocity);
	}

	return;
}

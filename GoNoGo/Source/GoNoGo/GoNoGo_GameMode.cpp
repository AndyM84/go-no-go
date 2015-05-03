// (c) 2015 Team GoNoGo

#include "GoNoGo.h"
#include "GoNoGo_GameMode.h"

void AGoNoGo_GameMode::Reset()
{
	return;
}

void AGoNoGo_GameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	for (auto PCI = GetWorld()->GetPlayerControllerIterator(); PCI; ++PCI)
	{
		
	}

	return;
}

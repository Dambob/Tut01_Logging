// Fill out your copyright notice in the Description page of Project Settings.


#include "Utilities/Logger.h"

// Basic logging method
void ULogger::LogMessage(FString message)
{
	// Check that the engine exists
	if (GEngine)
	{
		// Add debug message to the screen
		// INDEX_NONE adds message to the top of the list
		// 10.0f shows the message for 10 seconds
		// FColor::Red makes the message color red
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Red, message);
	}
}
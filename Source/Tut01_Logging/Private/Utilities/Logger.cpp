// Fill out your copyright notice in the Description page of Project Settings.

#include "Utilities/Logger.h"

// Define Logging Category
DEFINE_LOG_CATEGORY(LogGame);

// Basic logging method
void ULogger::LogMessage(FString message, bool onScreen)
{
	// Check that the engine exists and we want to display the message on screen
	if (GEngine && onScreen)
	{
		// Add debug message to the screen
		// INDEX_NONE adds message to the top of the list
		// 10.0f shows the message for 10 seconds
		// FColor::Red makes the message color red
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Red, message);
	}

	// Print message to the log
	// LogGame is the log channel
	// Log is the verbosity
	// TEXT("%s") is the formatting mask to print
	// *message replaces the first %s in the output string
	UE_LOG(LogGame, Log, TEXT("%s"), *message);
}
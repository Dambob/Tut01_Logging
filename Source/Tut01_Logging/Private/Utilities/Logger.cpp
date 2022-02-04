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
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::White, message);
	}

	// Print message to the log
	LogPrint(message, ELogVerbosity::Log);
}

// Wrapper around UE_LOG macro
void ULogger::LogPrint(FString message, ELogVerbosity::Type verbosity)
{
	// Print message to the log
	// LogGame is the log channel
	// Verbosity is used to detect correct logging level
	// TEXT("%s") is the formatting mask to print
	// *message replaces the first %s in the output string
	switch (verbosity)
	{
		case ELogVerbosity::Fatal:			UE_LOG(LogGame, Fatal, TEXT("%s"), *message); break;
		case ELogVerbosity::Error:			UE_LOG(LogGame, Error, TEXT("%s"), *message); break;
		case ELogVerbosity::Warning:		UE_LOG(LogGame, Warning, TEXT("%s"), *message); break;
		case ELogVerbosity::Display:		UE_LOG(LogGame, Display, TEXT("%s"), *message); break;
		case ELogVerbosity::Log:			UE_LOG(LogGame, Log, TEXT("%s"), *message); break;
		case ELogVerbosity::Verbose:		UE_LOG(LogGame, Verbose, TEXT("%s"), *message); break;
		case ELogVerbosity::VeryVerbose:	UE_LOG(LogGame, VeryVerbose, TEXT("%s"), *message); break;
		default: break;
	}
}
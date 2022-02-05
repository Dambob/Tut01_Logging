// Fill out your copyright notice in the Description page of Project Settings.

#include "Utilities/Logger.h"

// Define Logging Category
DEFINE_LOG_CATEGORY(LogGame);

// Basic logging method
void ULogger::LogMessage(FString message, bool onScreen)
{
	PrintMessage(message, onScreen, FColor::White, 10.0f, ELogVerbosity::Log);
}

// Error logging method
void ULogger::LogError(FString message, bool onScreen)
{
	PrintMessage(message, onScreen, FColor::Red, 10.0f, ELogVerbosity::Error);
}

// Warning logging method
void ULogger::LogWarning(FString message, bool onScreen)
{
	PrintMessage(message, onScreen, FColor::Yellow, 10.0f, ELogVerbosity::Warning);
}

// Print message
void ULogger::PrintMessage(FString message, bool onScreen, FColor color, float timer, ELogVerbosity::Type verbosity)
{
	// If we want to display the message on screen
	if (onScreen)
	{
		ScreenPrint(message, color, timer);
	}

	// Print message to the log
	LogPrint(message, verbosity);
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

// Print message to screen
void ULogger::ScreenPrint(FString message, FColor color, float timer)
{
	if (GEngine)
	{
		// Add debug message to the screen
		// INDEX_NONE adds message to the top of the list
		// Timer shows the message for the duration in seconds
		// color sets the message color
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, timer, color, message);
	}
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Logger.generated.h"

// Declare Logging Category
// LogGame is the name of the log
// Log is the default verbosity, this will include levels from "Fatal" up to "Log"
// All is the highest level of logging we can use (VeryVerbose currently)
DECLARE_LOG_CATEGORY_EXTERN(LogGame, Log, All);

/**
 * Logging Utility
 */
UCLASS()
class TUT01_LOGGING_API ULogger : public UObject
{
	GENERATED_BODY()

public:
	// Basic logging method
	// UFunction allows calling from blueprints
	UFUNCTION(BlueprintCallable, Category="Logging")
	static void LogMessage(FString message, bool onScreen = false);

private:
	// Private and empty constructor/destructor
	// This will be a purely static class
	ULogger() {};
	~ULogger() {};

	// Wrapper around UE_LOG macro
	static void LogPrint(FString message, ELogVerbosity::Type verbosity);

	// Print message to screen
	static void ScreenPrint(FString message, FColor color, float timer = 10.0f);
};

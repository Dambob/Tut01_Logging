// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Logger.generated.h"

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
	static void LogMessage(FString message);

private:
	// Private and empty constructor/destructor
	// This will be a purely static class
	ULogger() {};
	~ULogger() {};
};

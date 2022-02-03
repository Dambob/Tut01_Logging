// Copyright Epic Games, Inc. All Rights Reserved.


#include "Tut01_LoggingGameModeBase.h"
#include "Utilities/Logger.h"

// Constructor
ATut01_LoggingGameModeBase::ATut01_LoggingGameModeBase()
{
	// Example calling logging message
	ULogger::LogMessage("Entered Constructor.");
}

// Destructor
ATut01_LoggingGameModeBase::~ATut01_LoggingGameModeBase()
{
	// Example calling logging message
	ULogger::LogMessage("Entered Destructor.");
}
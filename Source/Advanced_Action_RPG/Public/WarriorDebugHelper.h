#pragma once

namespace Debug
{
	static void Print(const FString& Message, const FColor& Color = FColor::Green, float InTimeToDisplay = 5.f, int32 InKey = -1, const FString& CallerFunction = TEXT("Unknown"))
	{
		if (GEngine)
		{
			FString DebugMessage = FString::Printf(TEXT("[%s] %s"), *CallerFunction, *Message);
			GEngine->AddOnScreenDebugMessage(InKey, InTimeToDisplay, Color, DebugMessage);
		}

		UE_LOG(LogTemp, Log, TEXT("[%s] %s"), *CallerFunction, *Message);
	}
}

#define DEBUG_PRINT(Message) \
	Debug::Print(Message, FColor::Green, 5.f, -1, TEXT(__FUNCTION__))

#define DEBUG_PRINT_COLOR(Message, Color) \
	Debug::Print(Message, Color, 5.f, -1, TEXT(__FUNCTION__))

#define DEBUG_PRINT_FULL(Message, Color, TimeToDisplay, Key) \
	Debug::Print(Message, Color, TimeToDisplay, Key, TEXT(__FUNCTION__))
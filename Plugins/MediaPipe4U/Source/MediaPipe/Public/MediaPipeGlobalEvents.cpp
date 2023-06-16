#include "MediaPipeGlobalEvents.h"

#include "Misc/LazySingleton.h"



FMediaPipeGlobalEvents::FMediaPipeGlobalEvents()
{
	
}

FMediaPipeGlobalEvents* GMediaPipeEvents = new FMediaPipeGlobalEvents();

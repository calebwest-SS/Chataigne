/*
  ==============================================================================

    Module.cpp
    Created: 8 Dec 2016 2:36:02pm
    Author:  Ben

  ==============================================================================
*/

#include "Module.h"
#include "CommandFactory.h"

Module::Module(const String &name) :
	BaseItem(name),
	valuesCC("Values")
{
	saveAndLoadRecursiveData = false; //manage value ourselves

	recursiveInspectionLevel = 1;
	addChildControllableContainer(&valuesCC);
	addChildControllableContainer(&defManager);

	logIncomingData = addBoolParameter("Log Incoming Data", "Enable / Disable logging of incoming data for this module", false);
	logIncomingData->hideInOutliner = true;
	logIncomingData->isTargettable = false;

	activityTrigger = addTrigger("Activity", "Activity Signal");
	activityTrigger->hideInEditor = true;
}

Module::~Module()
{

}

Array<WeakReference<Controllable>> Module::getValueControllables()
{
	return valuesCC.getAllControllables();
}


var Module::getJSONData()
{
	var data = BaseItem::getJSONData();
	data.getDynamicObject()->setProperty("type", getTypeString());
	return data;
}

#include "pch.h"
#include "OutputProperty.h"

#include "../../../../Makers.Pure/Makers.Pure/Include/Properties/OutputProperty.h"

Makers::Net::Properties::OutputProperty::OutputProperty(
	Makers::Net::Items::ItemBase^ ownerItem,
	Makers::Properties::OutputProperty& outputProperty) :
PropertyBase(ownerItem, outputProperty)
{

}

Makers::Net::Properties::OutputProperty::~OutputProperty()
{


}

Makers::Net::Properties::OutputProperty::!OutputProperty()
{

}
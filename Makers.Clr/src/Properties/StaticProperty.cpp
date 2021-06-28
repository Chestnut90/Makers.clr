#include "pch.h"
#include "StaticProperty.h"

#include "../../../../Makers.Pure/Makers.Pure/Include/Properties/StaticProperty.h"

Makers::Net::Properties::StaticProperty::StaticProperty(
	Makers::Net::Items::ItemBase^ ownerItem,
	Makers::Properties::StaticProperty& staticProperty) :
PropertyBase(ownerItem, staticProperty)
{

}

Makers::Net::Properties::StaticProperty::~StaticProperty()
{
	
}

Makers::Net::Properties::StaticProperty::!StaticProperty()
{
	
}
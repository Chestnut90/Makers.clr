#include "pch.h"
#include "Computable.h"

// pures
#include "../../../../Makers.Pure/Makers.Pure/Include/Computables/IComputable.h"


Makers::Net::Computables::Computable::Computable(Makers::Computables::IComputable * _computable)
{
	computable_ = _computable;
}

Makers::Net::Computables::Computable::~Computable()
{
	throw gcnew System::NotImplementedException();
}

Makers::Net::Computables::Computable::!Computable()
{
	throw gcnew System::NotImplementedException();
}

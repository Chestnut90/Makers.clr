#include "pch.h"
#include "DocumentIO.h"

// ref
#include "Document.h"

//@ load net document object
Makers::Net::Documents::Document^ Makers::Net::Documents::DocumentIO::Load(System::String^ filePath)
{
	return nullptr;
}

//@ load pure document object
Makers::Documents::Document* Makers::Net::Documents::DocumentIO::_Load(std::string  _file_path)
{
	return nullptr;
}

//@ save net document object
bool Makers::Net::Documents::DocumentIO::Save(Makers::Net::Documents::Document^ document)
{
	return true;
}

// save cpp document object
bool Makers::Net::Documents::DocumentIO::_Save(Makers::Documents::Document& _document)
{
	return true;
}


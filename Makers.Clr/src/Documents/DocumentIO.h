#pragma once

#include "Document.h"

namespace Makers
{
	namespace Net
	{
		namespace Documents
		{
			ref class DocumentIO
			{
			public: static Document^ Load(System::String^ filePath)
			{
				return nullptr;
			}

			public: static Document_* _Load(std::string _file_path)
			{
				return nullptr;
			}

			public: static bool Save(Document^ document)
			{
				return true;
			}

			public: static bool _Save(Document_& _document)
			{
				return true;
			}

			};
		}
	}
}
#pragma once

#include <string>

namespace Makers
{
	namespace Documents { class Document; }

	namespace Net
	{
		namespace Documents
		{
			ref class Document;
			ref class DocumentIO
			{
			public: 
				//@ load net document object
				static Document^ Load(System::String^ filePath);

				//@ save net document object
				static bool Save(Document^ document);

				//@ load cpp document object
				static Makers::Documents::Document* _Load(std::string _file_path);

				
				//@ save cpp document object
				static bool _Save(Makers::Documents::Document& _document);

			};
		}
	}
}
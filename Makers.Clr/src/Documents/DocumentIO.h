#pragma once


namespace Makers
{
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

				//@ load cpp document object
				static Document_* _Load(std::string _file_path);

				//@ save net document object
				static bool Save(Document^ document);

				//@ save cpp document object
				static bool _Save(Document_& _document);

			};
		}
	}
}
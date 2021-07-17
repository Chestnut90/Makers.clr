#pragma once

#include "Computable.h"

namespace Makers
{
	namespace Computables { class ROI; }
	namespace Net
	{
		namespace Computables
		{
#pragma region ROI

			public ref class ROIs :
				public Computable
			{
			public:

				//@ ROI Left
				property long Left
				{
					long get();
				}

				//@ ROI Top 
				property long Top
				{
					long get();
				}

				//@ ROI Right
				property long Right
				{
					long get();
				}

				//@ ROI Bottom
				property long Bottom
				{
					long get();
				}

			public:
				//@ Constructor
				ROIs(Makers::Computables::IComputable* computable);
				//@ Destructor
				~ROIs();
				//@ Finalizer
				!ROIs();

			public:
				//@ Set ROI
				void SetROI(long left, long top, long right, long bottom);

				// implement <IXmlNodeAble>
			public:
				//@ Load from xml 
				//@ abstract function
				virtual void LoadFromXml(System::Xml::XmlNode^ xmlNode) override;
				//@ To xml
				//@ abstract function
				virtual System::Xml::XmlNode^ ToXml(System::Xml::XmlDocument^ xmlDocument) override;

			};

#pragma endregion
		}
	}
}
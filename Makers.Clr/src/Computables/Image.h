#pragma once

#include "Computable.h"

namespace Makers
{
	namespace Computables { template<typename _image_type>class Image; }
	namespace Net
	{

		namespace Computables
		{
			generic<class T>
			public ref class Image :
				public Computable
			{
			private:
				Makers::Computables::IComputable* computable_;

			public:
				template<typename _image_type>
				Image(Makers::Computables::Image<T>* _computable);
				~Image();
				!Image();

			};
		}
	}

}


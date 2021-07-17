#pragma once

namespace Makers
{
	namespace Computables { class IComputable; }
	namespace Net
	{
		namespace Computables
		{
			ref class Computable;

			ref class ComputableConverter
			{
			public:
				static Computable^ Cast(Makers::Computables::IComputable* computable);

			};
		}
	}
}
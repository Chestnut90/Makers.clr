#pragma once


namespace Makers
{
	namespace Computables { class IComputable; }
	namespace Net
	{

	namespace Computables
	{
		public ref class Computable
		{
		private:
			Makers::Computables::IComputable* computable_;

		public:
			Computable(Makers::Computables::IComputable* _computable);
			virtual ~Computable();
			!Computable();

		};
	}
	}

}


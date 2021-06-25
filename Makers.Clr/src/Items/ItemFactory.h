#pragma once

#include "ItemBase.h"
#include "../../../../Makers.Pure/Makers.Pure/Include/Items/ItemFactory.h"
#include "../Conversions/Converter.h"

using ItemFactory_ = Makers::Items::ItemFactory;

namespace Makers
{
	namespace Net
	{
		namespace Items
		{
			public ref class ItemFactory
			{
			
			private: ItemFactory_* item_factory_;

			//@ this factory instance
			private: static ItemFactory^ instance_;

			public: static ItemFactory^ Instance()
			{
				if (instance_ == nullptr)
				{
					instance_ = gcnew ItemFactory();
				}

				return instance_;
			}

			protected: ItemFactory()
			{
				item_factory_ = new ItemFactory_();
			}

			protected: ~ItemFactory()
			{
				delete item_factory_;
			}
					
			public: static void Destory()
			{
				delete instance_;
				instance_ = nullptr;
			}

			public: ItemBase^ Create(System::String^ itemName)
			{
				std::string a = "";
				Conversion::ConvertString(itemName, a);
				//a = Conversion::ConvertString(itemName);
				std::cout << a << std::endl;

				System::String^ net = Conversion::ConvertString(a);
				System::Console::WriteLine(net);

				std::string std_item_name;
				Conversion::ConvertString(itemName, std_item_name);
				auto item = item_factory_->Create(std_item_name);

				return gcnew ItemBase(item);
			}

			};
		}
	}
}
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Makers.Net.Items;

namespace Test.Items
{
    class ItemsTest
    {
        public static void Test_ItemFactory_ItemList()
        {
            Console.WriteLine("Item Factory item list");

            foreach(var pair in ItemFactory.Instance().ContainingItems())
            {
                Console.WriteLine(pair.Key);
                foreach(var name in pair.Value)
                {
                    Console.WriteLine($"    {name}");
                }
            }

        }

        public static void Test_ItemBase()
        {
            ItemBase sample = ItemFactory.Instance().Create("FloatThresholdingItem");

            Console.WriteLine(sample.ID);
            Console.WriteLine(sample.ItemName);


        }
    }
}

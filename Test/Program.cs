using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test
{
    class Program
    {
        static void Main(string[] args)
        {
            //var factory = Makers.Net.Items.ItemFactory.Instance();

            //Documents.DocumentTest.Test_Document();

            //Test.Items.ItemsTest.Test_ItemBase();

            Test.Items.ItemsTest.Test_ItemFactory_ItemList();

            Test.Maker.Properties.PropertiesTest.PropertyBase_Test();

            GC.Collect();
        }
    }
}

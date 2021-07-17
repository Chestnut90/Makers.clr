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

            //@ item list test
            //Test.Items.ItemsTest.Test_ItemFactory_ItemList();

            //Test.Maker.Properties.PropertiesTest.PropertyBase_Test();

            // document test
            //Test.Documents.DocumentTest.Test_Simple_Document();

            // surf io test
            Surf.SurfTest.IO_Test();

            GC.Collect();
        }
    }
}

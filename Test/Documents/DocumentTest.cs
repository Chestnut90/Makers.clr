using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test.Documents
{
    class DocumentTest
    {
        public static void Test_Document()
        {
            Makers.Net.Documents.Document doc = new Makers.Net.Documents.Document();

            Console.WriteLine(doc.ID);
            Console.WriteLine(doc.Title);

            doc = null;
        }

        public static Makers.Net.Items.ItemBase Test_Create_FloatThresholdingItem()
        {
            var floatThresholdingItem = Makers.Net.Items.ItemFactory.Instance().Create("FloatThresholdingItem");



            return floatThresholdingItem;
        }


        public static void Test_Simple_Document()
        {
            Makers.Net.Documents.Document doc = new Makers.Net.Documents.Document();

            var item1 = Test_Create_FloatThresholdingItem();
            var item1_id = item1.ID;
            doc.AddItem(item1);

            doc.RemoveItem(item1);



        }

    }
}

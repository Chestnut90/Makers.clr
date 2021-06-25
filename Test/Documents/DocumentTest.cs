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

    }
}

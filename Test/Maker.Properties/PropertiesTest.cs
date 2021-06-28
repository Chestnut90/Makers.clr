using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test.Maker.Properties
{
    class PropertiesTest
    {
        public static void PropertyBase_Test()
        {
            var randomItem = Makers.Net.Items.ItemFactory.Instance().Create("RandomFloatImageItem");

            foreach(var property in randomItem.InputProperties.ToList())
            {
                var inputProperty = property as Makers.Net.Properties.InputProperty;
                Console.WriteLine(inputProperty.Name);
                Console.WriteLine(inputProperty.ConnectedProperty.Name);
            }

            foreach(var property in randomItem.StaticProperties.ToList())
            {
                var staticProperty = property as Makers.Net.Properties.StaticProperty;
                Console.WriteLine(staticProperty.Name);
            }

            foreach(var property in randomItem.OutputProperties.ToList())
            {
                var outputProperty = property as Makers.Net.Properties.OutputProperty;
                Console.WriteLine(outputProperty.Name);
            }
        }

    }
}

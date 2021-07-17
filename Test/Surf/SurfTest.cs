using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test.Surf
{
    public class SurfTest
    {
        private static void Print_list<T>(List<T> list, long width, long height)
        {
            StringBuilder sb = new StringBuilder();

            for(long y = 0; y < height; ++y)
            {
                sb.Clear();
                for(long x = 0; x < width; ++x)
                {
                    long index = y * width + x;
                    sb.Append($"{list[(int)index]},");
                }
                Debug.WriteLine($"{sb.ToString()}\n");
            }
        }

        public static void IO_Test()
        {
            string filename = @"E:\Test\SDK.NET\sample.surf";

            nXSDK.Net.Surf surf = new nXSDK.Net.Surf();
            surf.Load(filename);

            Debug.WriteLine($"Width : {surf.Width}");
            Debug.WriteLine($"Height : {surf.Height}");

            var dict = new Dictionary<string, object>()
            {
                {"Zmap", surf.Zmap },
                {"Mask", surf.Mask },
                {"Gray", surf.Gray },
                {"Red", surf.Red },
                {"Green", surf.Green },
                {"Blue", surf.Blue }
            };

            foreach(var pair in dict)
            {
                Debug.WriteLine($"{pair.Key}");
                if (pair.Value is List<float>)
                {
                    Print_list(pair.Value as List<float>, surf.Width, surf.Height);
                }
                else
                {
                    Print_list(pair.Value as List<byte>, surf.Width, surf.Height);
                }
                Debug.WriteLine("");

            }


        }

    }
}

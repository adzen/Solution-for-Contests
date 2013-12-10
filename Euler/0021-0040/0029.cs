// 問有幾個不同的 a^b，for 2 ≤ a ≤ 100 and 2 ≤ b ≤ 100?

// 用 C# 的 BigInteger 和 List 的 Distinct() 秒殺

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Numerics;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            List<BigInteger> seq = new List<BigInteger>();

            for (int a = 2; a <= 100; a++)
            {
                for (int b = 2; b <= 100; b++)
                {
                    BigInteger large = BigInteger.Pow(a, b);
                    seq.Insert(0, large);
                }
            }

            Console.WriteLine("num = " + seq.Distinct().Count().ToString());
            while (true) ;
        }
    }
}

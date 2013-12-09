// 100個50位數的大數加法...用 C# 秒殺

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
            BigInteger sum = 0;
            for (int i = 0; i < 100; i++)
            {
                sum += BigInteger.Parse(Console.ReadLine());
            }
            Console.WriteLine(sum.ToString());
            while (true) ;
        }
    }
}

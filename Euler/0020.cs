// 100! 的數字和...用 C# 的大數搞定！

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
            BigInteger big = 1;
            for (int i = 1; i <= 100; i++) big *= i;

            int sumDig = 0;
            while (big > 0) {
                sumDig += (int)(big % 10);
                big /= 10;
            }

            Console.WriteLine(sumDig.ToString());
            while (true) ;
        }
    }
}

// a^b 的十進位表示法，a, b < 100，最大的數字和是？

// C# 內建大數，就直接拿來用了...

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
            BigInteger max = 0;
            for (int a = 1; a < 100; a++) {
                for (int b = 1; b < 100; b++) {
                    BigInteger ans = BigInteger.Pow(a, b);   // a^b
                    
                    // 計算數字和
                    BigInteger sum = 0;
                    while (ans > 0) {
                        sum += ans % 10;
                        ans /= 10;
                    }

                    if (sum > max) max = sum;
                }
            }

            Console.WriteLine(max.ToString());
            while (true) ;
        }
    }
}

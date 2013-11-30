// 首個 1000 位數的 fib 是序列中的第幾個？ 還是 C# 秒殺...orz

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
            int count = 3;
            BigInteger a = 1, b = 1, c = 2;   // a+b = c
            while(true){
                a = b;
                b = c;
                c = a+b;
                count++;
                if (c.ToString().Length >= 1000) break;
            }
            Console.WriteLine(count.ToString());
            while (true) ;
        }
    }
}

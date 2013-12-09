// 2^1000 的十進位數字和 */

// C# 有大數就直接秒殺了... 

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
            BigInteger ans = BigInteger.Pow(2, 1000);
            int sum = 0;
            while (ans > 0) {
                sum += (int)(ans % 10);
                ans /= 10;
            }
            Console.WriteLine(sum.ToString());
            while (true) ;
        }
    }
}

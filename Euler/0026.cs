// 問 d < 1000，則可以使 1/d 的十進位表示法，小數部分的循環節最長？

// 就把小數點後的 10000 位數當成字串去算即可(?)

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Numerics;

namespace ConsoleApplication1
{
    class Program
    {
        // 算小數部分的循環長度
        static int calCycle(BigInteger fraction) {
            string p = fraction.ToString();
            int guessLen = 1;   // 從 1 開始猜
            while(true){
                // 取較後面的（小數點第 2000 位以後）連續兩段作比較，相同則表示猜中了
                string guess1 = p.Substring(2000, guessLen);
                string guess2 = p.Substring(2000+guessLen, guessLen);
                if (string.Compare(guess1, guess2) == 0) return guessLen;   
                guessLen++;
            }
        }

        static void Main(string[] args)
        {
            int find = 7, len = 6;    // 1/7 的循環長度是 6 
            BigInteger large = BigInteger.Pow(10, 10000);
            for (int down = 11; down < 1000; down++) {
                BigInteger fraction = large / down;    // 取小數點後 10000 位數
                int thisLen = calCycle(fraction);
                Console.WriteLine("1 / " + down.ToString() + " => len = " + thisLen.ToString());
                if (thisLen > len) {    // 長度較長就更新
                    len = thisLen;
                    find = down;
                }
            }
            Console.WriteLine("d = " + find.ToString());
            while (true) ;
        }
    }
}





using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Numerics;

namespace ConsoleApplication1
{
    class Program
    {
        static int calCycle(BigInteger fraction) {
            string p = fraction.ToString();
            int guessLen = 1;
            while(true){
                string guess1 = p.Substring(2000, guessLen);
                string guess2 = p.Substring(2000+guessLen, guessLen);
                if (string.Compare(guess1, guess2) == 0) return guessLen;
                guessLen++;
            }
        }

        static void Main(string[] args)
        {
            int find = 7, len = 6;
            BigInteger large = BigInteger.Pow(10, 10000);
            for (int down = 11; down < 1000; down++) {
                BigInteger fraction = large / down;
                int thisLen = calCycle(fraction);
                //Console.WriteLine(fraction.ToString());
                Console.WriteLine("1 / " + down.ToString() + " => len = " + thisLen.ToString());
                if (thisLen > len) {
                    len = thisLen;
                    find = down;
                }
            }
            Console.WriteLine("d = " + find.ToString());
            while (true) ;
        }
    }
}

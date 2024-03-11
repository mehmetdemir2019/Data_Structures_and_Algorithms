using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VeriConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            
            byte num1 = 8;
            sbyte num2 = -8;

            Console.WriteLine("Byte min: {0} max: {1}",byte.MinValue, byte.MaxValue);
            Console.WriteLine("SByte min: {0} max: {1}", sbyte.MinValue, sbyte.MaxValue);

            // 1 0 0 0 0 0 0 0 -> -128
            // 0 1 1 1 1 1 1 1 -> 127
           



            var numbers = new String[]
            {
                "00000000",     // 0
                "00000001",     // 1
                "00000010",     // 2
                "00000011",     // 3
                "00001011",     // 11
                "10000000",     // 128 | -128
                "10000001",     // 129 | -128+1 = -127
                "10000011",     // 131 | -128+3 = -125
                "10001111",     // 143 | -128+15 = -113
                
             };
            foreach (var item in numbers)
            {
                sbyte number = Convert.ToSByte(item,2);

                Console.WriteLine(number);

            }
            Console.ReadKey();





        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');

        int n = int.Parse(input[0]);
        int k = int.Parse(input[1]);

        List<int> numbers = Console.ReadLine().Split(' ').Select(int.Parse).ToList();

        foreach (int number in numbers)
        {
            if (number % k == 0)
            {
                Console.WriteLine(number / k + " ");
            }
        }

        Console.WriteLine();
    }
}

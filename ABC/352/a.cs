using System;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(' ');
        int n = int.Parse(input[0]);
        int x = int.Parse(input[1]);
        int y = int.Parse(input[2]);
        int z = int.Parse(input[3]);

        if ((y < z && z < x) || (x < z && z < y))
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }
}

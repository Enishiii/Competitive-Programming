using System;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());

        string[] inputs = Console.ReadLine().Split(' ');

        int sum = 0;
        int x;
        for (int i = 0; i < n-1; i++)
        {
            x = int.Parse(inputs[i]);
            sum += x;
        }

        Console.WriteLine(-sum);
    }
}

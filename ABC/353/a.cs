using System;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());

        int[] h = new int[n];
        string[] inputs = Console.ReadLine().Split(' ');
        for (int i = 0; i < n; ++i)
        {
            h[i] = int.Parse(inputs[i]);
        }

        for (int i = 1; i < n; ++i)
        {
            if (h[i] > h[0])
            {
                Console.WriteLine(i + 1);
                return;
            }
        }
        Console.WriteLine(-1);
    }
}

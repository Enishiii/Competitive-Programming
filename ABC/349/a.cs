using System;

class Program
{
    static void Main()
    {
        int numInputs = int.Parse(Console.ReadLine());

        string[] inputs = Console.ReadLine().Split(' ');

        int total = 0;
        for (int i = 0; i < numInputs-1; i++)
        {
            total += int.Parse(inputs[i]);
        }

        Console.WriteLine(-total);
    }
}

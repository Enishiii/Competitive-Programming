using System;

class Program
{
    static void Main(string[] args)
    {
        string S = Console.ReadLine();

        int num = int.Parse(S.Substring(3,3));

        if (num >= 1 && num <= 349 && num != 316)
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }
}

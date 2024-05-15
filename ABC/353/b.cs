using System;

class Program
{
    static void Main()
    {
        string[] inputs = Console.ReadLine().Split();
        int groupNum = int.Parse(inputs[0]);
        int maxSeats = int.Parse(inputs[1]);


        int[] occupiedSeats = new int[groupNum];
        string[] inputs2 = Console.ReadLine().Split();
        for (int i = 0; i < groupNum; ++i) {
            occupiedSeats[i] = int.Parse(inputs2[i]);
        }
        
        int startCount = 0;
        int remainedSeats = maxSeats;

        for (int i = 0; i < groupNum; ++i)
        {
            if (occupiedSeats[i] > remainedSeats)
            {
                startCount++;
                remainedSeats = maxSeats;
            }
            remainedSeats -= occupiedSeats[i];
        }
        startCount++;

        Console.WriteLine(startCount);
    }
}

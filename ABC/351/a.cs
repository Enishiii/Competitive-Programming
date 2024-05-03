string [] s = Console.ReadLine().Split();
string[] t = Console.ReadLine().Split();

int s_sum = 1;

for (int i = 0; i < s.Count(); i++)
{
    s_sum += int.Parse(s[i]);
}

for (int i = 0; i < t.Count(); i++)
{
    s_sum -= int.Parse(t[i]);
}

Console.WriteLine(s_sum.ToString());

//14650 : 걷다보니 신천역 삼 (Small)
using System;

class Program
{
    public static void Main()
    {
        var N = int.Parse(Console.ReadLine());
        var dp = new int[10];

        dp[1] = 0;
        dp[2] = 2;

        for (int i = 3; i <= N; i++)
        {
            dp[i] = dp[i - 1] * 3;
        }

        Console.WriteLine(dp[N]);
    }
}
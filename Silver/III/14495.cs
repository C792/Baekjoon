//14495 : 피보나치 비스무리한 수열
using System;

class Program
{
    public static void Main()
    {
        var N = int.Parse(Console.ReadLine());
        var dp = new long[120];

        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;

        for (int i = 4; i <= N; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 3];
        }

        Console.WriteLine(dp[N]);
    }
}
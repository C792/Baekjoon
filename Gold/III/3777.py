#3777 : Computer Transformation
import sys
sys.setrecursionlimit(10**6)
dp=[0 for i in range(1000)]

def calc(a):
    if a==1:
        return 0
    elif dp[a]!=0:
        return dp[a]
    else:
        if dp[a-1]==0:
            calc(a-1)
        if a%2==0:
            dp[a]=dp[a-1]*2 + 1
            return dp[a]
        else:
            dp[a]=dp[a-1]*2 - 1
            return dp[a]

while True:
    try:
        n=int(input())
        print(calc(n))
    except EOFError:
        break
n=int(input())

dp=[0,2,4]

incre = 3

for i in range(3,n+1):
    dp.append(dp[i-1]+incre)
    if i%3!=0:
        incre+=1

print(dp[n])
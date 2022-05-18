#4355 : 서로소
import sys

lines = sys.stdin.readlines()

for line in lines:
    m=n=int(line)
    if n==0:
        break

    prime=[]
    i=2
    while m>i:
        if m%i==0:
            m/=i
            prime.append(i)
        else:
            i+=1
    prime.append(m)

    p = set(prime)

    for i in p:
        n*=(1-1/i)

    print(int(n))
#2824 : 최대공약수
from math import prod, gcd
input()
A = prod(list(map(int, input().split())))
input()
B = prod(list(map(int, input().split())))
print(str(gcd(A, B))[-9:])
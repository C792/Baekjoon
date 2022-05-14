#using input()

while True:
    try:
        a, b = map(int, input().split())
        print(a+b)
    except EOFError:
        break

#using stdin.readline()

import sys

lines = sys.stdin.readlines()

for line in lines:
    A, B = map(int, line.split())
    print(A+B)
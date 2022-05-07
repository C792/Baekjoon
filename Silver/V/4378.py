#4378 : 트ㅏㅊ; (쿼티)
from sys import stdin
while True:
    inp = stdin.readline().rstrip()
    if inp == '':
        break

    conv = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./"

    ans = ""

    for i in inp:
        if i == ' ':
            ans+=i
        else:
            ans += conv[conv.find(i)-1]

    print(ans)
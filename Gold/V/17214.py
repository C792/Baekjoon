#17214 : 다항함수의 적분
import re

f = input()
ans = ''

if f != '0':
    l = re.findall('-?\d+x', f)
    if l:
        n = str(int(l[0][:-1]) // 2)
        if n[0].isdigit() or n[0] == '+':
            sgn = ''
        else:
            sgn = '-'

        if n in ['1', '-1']: 
            ans += sgn + 'xx'
        else:
            ans += n + 'xx'

    c = re.findall('[-, +]?\d+$', f)
    if c:
        n = c[0]
        if n not in ['+0', '-0']:
            if n[0].isdigit() or n[0] == '+':
                sgn = '+'
            else:
                sgn = '-'

            if n == '1':
                ans += 'x'
            elif n in ['-1', '+1']:
                ans += sgn + 'x'
            else:
                ans += n + 'x'
    ans += '+W'

else:
    ans = 'W'

print(ans)
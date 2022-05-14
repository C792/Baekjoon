#1287 : 할 수 있다
import re

eq = input()

if len(re.findall('[+\-*/]',eq)) + 1 != len(re.findall('\d+',eq)):
    print('ROCK')
    quit()
    
eq = eq.replace('/','//').replace('()','@').replace('**','@')

try:
    print(eval(eq))
except:
    print('ROCK')
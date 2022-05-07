# c,d=input().split()
# chk=1
# if float(c)<1:
#     chk=0
# a,e=c.split('.')
# a=int(a)
# i=int(len(e))
# l=0
# for j in e:
#     l+=1
#     if j!='0':
#         break
# a*=10**i
# a+=int(e)
# b=int(d)
# l*=b
# ans = str(a**b)
# if chk==0:
#     exstr=""
#     for i in range(l):
#         exstr+="0"
#     ans=exstr+ans
#     f=ans[-i*b+l:]
#     ans="0"
# else:
#     f=ans[-i*b:]
#     ans=ans[:-i*b]
# print(ans+'.'+f)
a,b=input().split()
p = len(a[a.index('.')+1:])
a = a.replace('.','')
r = str(int(a)**int(b))
p=str((10**p)**int(b))
i = len(r)-len(p)+1
if i >=0:
    print(r[:i]+'.'+r[i:])
else:
    print('0.'+'0'*(-i)+r)
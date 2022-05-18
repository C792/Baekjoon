#11689 : GCD(n,k)=1
m=n=int(input())

prime=[]
i=2
while m>=i*i:
    if m%i==0:
        m/=i
        prime.append(i)
        while m%i==0:
            m/=i
        i+=1
    else:
        i+=1
if m!=1:
    prime.append(int(m))

for i in prime:
    n*=(1-1/i)

print(int(n))
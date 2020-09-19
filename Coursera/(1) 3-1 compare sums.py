#python3
n=input()
n=int(n)

x=0
y=0

m=input()
a=m.split()
for i in a:
    i=float(i)
    #i*=1000
    #i=int(i)
    #print(i)
    x+=i

p=input()
b=p.split()
for i in b:
    i=float(i)
    #i*=1000
    #i=int(i)
    #print(i)
    y+=i

#print(x)
#print(y)

if x==y:
    print("SUM(A)=SUM(B)")
elif x>y:
    if x-y<10**(-4)/2:
        print("SUM(A)=SUM(B)")
    else:
        print("SUM(A)>SUM(B)")
elif x<y:
    if y-x<10**(-4)/2:
        print("SUM(A)=SUM(B)")
    else:
        print("SUM(A)<SUM(B)")

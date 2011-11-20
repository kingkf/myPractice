n = raw_input()
n = int(n)
a=raw_input()
a=a.split()
for i in range(0,n):
    a[i]=int(a[i])

count=0
if sum(a)%2==0:
    for i in a:
        if i%2==0:
            count=count+1
else:
    for i in a:
        if i%2!=0:
            count=count+1

print count
   




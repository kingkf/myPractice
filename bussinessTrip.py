k = raw_input()
k = int(k)
a = raw_input()
a = a.split(' ')
for i in range(0,12):
    a[i] = int(a[i])
a.sort()
s = 0
i = len(a)-1
count = 0
while s<k and i>=0:
    s = s + a[i]
    i = i - 1
    count = count + 1
if s<k:
    print -1
else:
    print count

n=raw_input()
n=int(n)
k=raw_input()
k=int(k)
likedic={}
for i in range(0,k):
	s=raw_input()
	s=s.split(' ')
	if int(s[0]) not in likedic:
		likedic[int(s[0])]=[]
		likedic[int(s[0])].append(int(s[1]))
	else:
		likedic[int(s[0])].append(int(s[1]))
	
m=raw_input()
m=int(m)
dislikedic=[]
for i in range(0,m):
	s=raw_input()
	s=s.split(' ')
	s[0]=int(s[0])
	s[1]=int(s[1])
	dislikedic.append(s)
istest=[0]*(n+1)

result=[]
for i in range(1,n+1):
	count=0
	res=[]
	if istest[i]==0:
		stack=[]
		stack.append(i)
		while len(stack)>0:
			now=stack.pop()
			istest[now]=1
			res.append(now)
			count=count+1
			if now in likedic:
				temp=likedic[now]
			else:
				temp=[]
			for t in temp:
				if istest[t]==0:
					stack.append(t)
	result.append([count,res])
result=sorted(result)
print result
temp=result.pop()
i=0
while i<len(dislikedic):
	if dislikedic[i][0] in temp[1] and dislikedic[i][1] in temp[1]:
		temp=result.pop()
		i=0
	else:
		i=i+1
print temp[0]













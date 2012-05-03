num=raw_input()
length=len(num)
if num[0]=='0':
	print '-1'
elif length<3:
	print '-1'
elif length-2<7:
	print max(int(num[0])+int(num[1])+int(num[2::]),int(num[0:length-2])+int(num[length-2])+int(num[length-1]),int(num[0])+int(num[1:length-1])+int(num[length-1]))
else:


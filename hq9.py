s=raw_input()
y=0
for e in s:
	if e=='H' or e=='Q' or e=='9':
		print 'YES'
		y=1
		break;
if y==0:
	print 'NO'

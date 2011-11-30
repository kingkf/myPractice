n=raw_input()
n=int(n)

dic={}
order=[]
for i in range(0,n):
    line=raw_input()
    line=line.split()
    if line[0] not in dic.keys():
        dic[line[0]]=int(line[1])
    else:
        dic[line[0]]=dic[line[0]]+int(line[1])
    order.append((line[0],dic[line[0]]))
maxValue=max(dic.values())
for a,b in order:
    if b>=maxValue and dic[a]==maxValue:
        print a
        break


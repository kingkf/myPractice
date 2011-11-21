inputfile = open('bhaarat.text','r')
outputfile = open('out.text','w')
out=[]
for line in inputfile:
    a=line.split()
    if a[1][0] == 'H' or a[1][0] == 'S':
        out.append(line)
out.append('23. English')
out=''.join(out)
outputfile.write(out)
inputfile.close()
outputfile.close()


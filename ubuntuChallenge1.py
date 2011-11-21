i=99
b=""
while i>1:
    print "%d bottles of beer on the wall, %d bottles of beer." % (i,i)
    if i==2:
        print "Take one down and pass it around, %d bottle of beer on the wall." % (i-1)
    else:
        print "Take one down and pass it around, %d bottles of beer on the wall." % (i-1)
    print ''
    i=i-1
print "1 bottle of beer on the wall, 1 bottle of beer.\nTake one down and pass it around, no more bottles of beer on the wall."
print "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall."

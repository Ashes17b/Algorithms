def isHeap(l):
    if l == None:
        return False
    for i in range(len(l)):
        if 2*i + 1 < len(l) and int(l[i]) > int(l[2*i + 1]) or 2*i + 2 < len(l) and int(l[i]) > int(l[2*i + 2]):
            return False
    return True

f = open("in.txt", "r")
l = []
for x in f:
    x = x.split()
    l.append(x)
f.close()

l.remove(l[0])
l = l[0]
print(l)

out = open("output.txt", "w")
out.write('Yes') if isHeap(l) is True else out.write('No')
out.close()

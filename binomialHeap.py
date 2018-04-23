fin = open("input.txt", "r")
fout = open("output.txt", "w")
N = int(''.join(fin.read().split()))
if N <= 0:
    fout.write('-1\n')
else:
    result = []
    while N > 0:
        i = 0
        while pow(2, i) <= N:
            i += 1
        result.insert(0, i - 1)
        N -= pow(2, i - 1)
    for i in result:
        fout.write(str(i) + '\n')
fout.close()
fin.close()


#
#  main.cpp
#  diskProblem29
#
#  Created by Anton on 2/18/18.
#  Copyright 2018 Anton. All rights reserved.
#

import math

arrDiscs = []

def lenDisk(R, i, box):
    r = -1
    k = i - 1
    while(k > -1):
        x = 2*math.sqrt(arrDiscs[k]*R)
        if box[k] + x >= r:
            r = box[k] + x
            result = k
        k -= 1
    return result

def solution(box, countDiscs):
    box[0] = arrDiscs[0]
    for i in range(1, countDiscs):
        disk = lenDisk(arrDiscs[i], i, box)
        box[i] = box[disk] + 2*math.sqrt(arrDiscs[disk]*arrDiscs[i])

def printToFileLenBox(fout, box, countDiscs):
    lenBox = 0
    for i in range(0, countDiscs):
        if box[i] + arrDiscs[i] >= lenBox:
            lenBox = box[i] + arrDiscs[i]
    fout.write(str("{0:.5f}".format(lenBox)) + '\n')

fin = open("in.txt", "r")
fout = open("out.txt", "w")
countDiscs = int(fin.readline())
for disk in fin:
    arrDiscs.append(float(''.join(disk.split())))
fin.close()
#Packing in a box
box = countDiscs*[0]
solution(box, countDiscs)
#Find length Box
printToFileLenBox(fout, box, countDiscs)
fout.close()

# -*- coding: utf-8 -*-
"""
Code 07_06
"""

list1 = []
list2 = []
value = 1
for i in range(0,3) :
    for k in range(0,4) :
        list1.append(value)
        value += 1
    list2.append(list1)
    list1 = []

for i in range(0,len(list2)) :
    for k in range(0,len(list2[i])) :
        print("%3d" % list2[i][k], end=" ")
    print("")


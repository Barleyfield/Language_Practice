# -*- coding: utf-8 -*-
"""
Code 07_bonus3
Matrix Add

"""

list1 = []
list2 = []
list3 = []
list4 = []
num = 0

print("첫 번째 행렬 입력\n")
for i in range(0,3) :
    for k in range(0,4) :
        num = int(input(str(i+1) + "행 " + str(k+1) + "열의 값: "))
        list2.append(num)
    list1.append(list2)
    list2 = []
        
        
print("두 번째 행렬 입력\n")
for i in range(0,3) :
    for k in range(0,4) :
        num = int(input(str(i+1) + "행 " + str(k+1) + "열의 값: "))
        list4.append(num)
    list3.append(list4)
    list4 = []        
    
print("첫 번째 행렬\n")
for i in range(0,3) :
    for k in range(0,4) :
        print("%d " % list1[i][k], end="")
    print("")

print("두 번째 행렬\n")
for i in range(0,3) :
    for k in range(0,4) :
        print("%d " % list3[i][k], end="")
    print("")
    
print("합\n")
for i in range(0,3) :
    for k in range(0,4) :
        list1[i][k] += list3[i][k]
        print("%d " % list1[i][k], end="")
    print("")
# -*- coding: utf-8 -*-
"""
Created on Tue Dec 11 00:44:46 2018

@author: Isaac

Lambda and Map Practice
람다, 맵 연습

"""

hap = lambda num1, num2 : num1+num2
print(hap(10,20))

myList = [1,2,3,4,5]
add10 = lambda num : num+10
myList = list(map(add10, myList))
print(myList)

myList2 = [num for num in range(10,20)]
myList2 = list(map(lambda num : num+10, myList2))
print(myList2)

myList3 = [1,2,3,4]
myList4 = [11,12,13,14]
hapList = list(map(lambda n1, n2 : n1+n2, myList3, myList4))
print(hapList)


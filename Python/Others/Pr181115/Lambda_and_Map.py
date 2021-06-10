# -*- coding: utf-8 -*-
"""
Created on Thu Nov 15 09:59:15 2018

@author: Barley

Lambda and Map

"""

myList = [1,2,3,4,5]
add10 = lambda num : num + 10   # 단순한 함수는 lambda로 줄일 수 있다.
myList = list(map(add10,myList))    
print(map(add10,myList))        # map을 직접 출력하면 <map object at 0x00000210259E0630> 가 뜬다.
print("myList : " + str(myList))

list1 = [1,2,3,4]
list2 = [10,20,30,40]
hapList = list(map(lambda n1,n2 : n1 + n2,list1,list2))     # 2개의 리스트 합을 구하는 간단한 방법!
print("hapList : " + str(hapList))
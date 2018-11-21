# -*- coding: utf-8 -*-
"""
Created on Wed Nov 21 20:23:14 2018

@author: Isaac

Lambda와 map을 알아보자

"""

myList = [1,2,3,4,5]
add10 = lambda num : num + 10
myList = list(map(add10, myList))
print(map(add10,myList))        # map 함수를 직접적으로 출력하면 덧셈은 수행되지만 그 결과가 저장된 장소를 출력.
                                # 예 : <map object at 0x000002ABCB2D93C8>
print(list(map(add10,myList)))
print(myList)

# 더 간결하게!
myList2 = [6,7,8,9,10]
myList2 = list(map(lambda num : num+10, myList2))
print(myList2)


# 두 리스트 더하기
list1 = [1,2,3,4]
list2 = [10,20,30,40]
hapList = list(map(lambda n1,n2 : n1+n2, list1, list2))
print(hapList)
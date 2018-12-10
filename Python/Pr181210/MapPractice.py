# -*- coding: utf-8 -*-
"""
Created on Mon Dec 10 22:40:30 2018

@author: Isaac

Map Practice
Map함수 연습

결과 : 
['2019', '12', '31']
0번째 타입 : <class 'str'>
1번째 타입 : <class 'str'>
2번째 타입 : <class 'str'>
[2019, 12, 31]
0번째 타입 : <class 'int'>
1번째 타입 : <class 'int'>
2번째 타입 : <class 'int'>

"""

before = ['2019', '12', '31']
print(before)
for i in range(len(before)) :
    print("%d번째 타입 : " % i, end='')
    print(type(before[i]))

after = list(map(int, before))
print(after)
for i in range(len(after)) :
    print("%d번째 타입 : " % i, end='')
    print(type(after[i]))
# -*- coding: utf-8 -*-
"""
Created on Mon Dec 10 19:27:46 2018

@author: Isaac

Comprehension (함축) Practice

"""

# 지금까지 배운 리스트 만드는 법
numList = []
for num in range(1,6) :
    numList.append(num)
print(numList)

# Comprehension (함축) 적용
numList2 = [num for num in range(1,6)]
print(numList2)

# Comprehension을 적용한 제곱식 만들기
numList3 = [num*num for num in range(1,6)]
print(numList3)

# Comprehension을 적용한 1~20 숫자 중 3의 배수로만 적용된 리스트
numList4 = [num for num in range(1,21) if (num%3==0)]
print(numList4)

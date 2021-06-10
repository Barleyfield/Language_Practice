# -*- coding: utf-8 -*-
"""
Created on Mon Dec 10 19:33:11 2018

@author: Isaac

Multiple List Access
동시에 여러 리스트에 접근

"""

# zip 함수를 이용해 동시에 여러 리스트에 접근
foods = ['떡볶이', '짜장면', '라면', '피자', '맥주', '치킨', '삼겹살']
sides = ['오뎅', '단무지', '김치']
for food, side in zip(foods, sides) :
    print(food, '-->', side)

# 두 리스트를 튜플이나 딕셔너리로 짝지을 때도 활용 가능
tupList = list(zip(foods, sides))
dic = dict(zip(foods, sides))
print(tupList)
print(dic)


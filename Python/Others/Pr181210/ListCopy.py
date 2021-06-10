# -*- coding: utf-8 -*-
"""
Created on Mon Dec 10 19:38:23 2018

@author: Isaac

List Copy
리스트 복사

"""

# 얕은 복사
oldList = ['짜장면', '탕수육', '군만두']
newList = oldList
print(newList)
oldList[0] = '짬뽕'
oldList.append('깐풍기')
print(newList)

print("-----------")

# 깊은 복사
oldList = ['짜장면', '탕수육', '군만두']
newList = oldList[:]
print(newList)
oldList[0] = '짬뽕'
oldList.append('깐풍기')
print(newList)
print(oldList)


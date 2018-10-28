# -*- coding: utf-8 -*-
"""
Created on Tue Oct 23 02:41:22 2018

@author: Isaac
"""

list = [30,20,20,10]
# 해당 값 모두 제거
for i in range(list.count(20)) :
    list.remove(20)
# list.remove(20) # 1개만 제거
del(list[0])
print(list)
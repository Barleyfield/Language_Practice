# -*- coding: utf-8 -*-
"""
Created on Tue Dec 11 01:06:21 2018

@author: Isaac

Count to 1 - Recursive
1까지 세는 재귀함수

"""

def count(num) :
    if (num >= 1) :
        print(num, end=' ')
        count(num - 1)
    else :
        print()
        return

count(10)
count(20)


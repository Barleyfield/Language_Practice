# -*- coding: utf-8 -*-
"""
Created on Mon Dec 10 23:23:20 2018

@author: Isaac

List Return
함수가 리스트를 반환

"""

def multi(v1, v2) :
    retList = []
    res1 = v1 + v2
    res2 = v1 - v2
    retList.append(res1)
    retList.append(res2)
    return retList

myList = []
hap, sub = 0,0

myList = multi(100, 200)
hap = myList[0]
sub = myList[1]
print("multi()에서 돌려준 값 : %d, %d" % (hap, sub))


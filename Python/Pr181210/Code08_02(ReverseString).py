# -*- coding: utf-8 -*-
"""
Created on Mon Dec 10 20:59:51 2018

@author: Isaac

Reverse String
문자열 거꾸로

"""

inStr, outStr = "", ""
count, i = 0,0

inStr = input("문자열 입력 : ")
count = len(inStr)

outStr = inStr[::-1]

'''
for i in range(0, count) :
    outStr += inStr[count-(i+1)]
'''
print(outStr)


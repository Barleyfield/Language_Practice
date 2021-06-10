# -*- coding: utf-8 -*-
"""
Created on Thu Nov  1 08:56:59 2018

@author: Barley

String reverse

"""
inStr, outStr = "", ""
count, i = 0, 0

inStr = input("문자열을 입력하세요 : ")
count = len(inStr)

for i in range(0, count) :
    outStr += inStr[count - (i + 1)]
    # 알고리즘 기억하기!
    # outStr에는 inStr[길이-1] ~ inStr[0] 순으로 inStr의 반대 순서로 원소가 채워진다.

print("내용을 거꾸로 출력 : %s " % outStr)

# -*- coding: utf-8 -*-
"""
Created on Tue Nov 13 03:01:06 2018

@author: Isaac

숫자 지우기

"""

inStr = input("문자열 : ")
outStr = ""

for i in range(0, len(inStr)) :
    if not ( (ord(inStr[i]) >= ord('0')) and (ord(inStr[i]) <= ord('9')) )  :
        outStr += inStr[i]
# if문 : 입력받은 문자열의 i번째 문자가 0과 9 사이가 아니라면 (ASCII로 비교)
# 출력할 문자열에 (outStr) 넣

print("숫자 제거 : " + outStr)




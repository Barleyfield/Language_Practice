# -*- coding: utf-8 -*-
"""
Created on Tue Nov 13 03:07:42 2018

@author: Isaac

문자열 개수 세기

대문자, 소문자, 숫자, 한글, 기타

"""

inStr = input("문자열을 입력하세요 : ")
upper, lower, number, hangul, other = 0, 0, 0, 0, 0


for i in range(0, len(inStr)) :
    if( (ord(inStr[i]) >= ord('A')) and (ord(inStr[i]) <= ord('Z')) ) :
        upper += 1
    elif( (ord(inStr[i]) >= ord('a')) and (ord(inStr[i]) <= ord('z')) ) :
        lower += 1
    elif( (ord(inStr[i]) >= ord('0')) and (ord(inStr[i]) <= ord('9')) ) :
        number += 1                
    elif( (ord(inStr[i]) >= ord('가')) and (ord(inStr[i]) <= ord('힣')) ) :
        hangul += 1            # 한글의 처음은 '가', 끝은 '힣'
    else :
        other += 1

print("대문자 : %d, 소문자 : %d, 숫자 : %d, 한글 : %d, 기타 : %d"
      % (upper, lower, number, hangul, other))


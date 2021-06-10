# -*- coding: utf-8 -*-
"""
Created on Tue Oct 23 02:20:18 2018

내가 만든 문자열 거꾸로 코드

@author: Isaac
"""

inStr = input("문자열 입력 : ")
inStr = inStr[::-1]
# inStr.reverse() : 이건 오류가 난다. 순수 '리스트'에만 동작하는 듯
print(inStr)


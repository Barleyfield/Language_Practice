# -*- coding: utf-8 -*-
"""
Created on Mon Dec 10 21:23:10 2018

@author: Isaac

Parentheses
문자열 앞뒤로 괄호 붙이기

"""

ss = input("입력 : ")
print("출력 : ", end='')

if (ss.startswith('(') == False) :
    print("(", end="")

print(ss, end="")

if (ss.endswith(')') == False) :
    print(")", end="")


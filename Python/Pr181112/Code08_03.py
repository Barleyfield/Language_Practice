# -*- coding: utf-8 -*-
"""
Created on Mon Nov 12 21:06:04 2018

@author: Isaac

"""
ss = input('입력 문자열 : ')
print("출력 문자열 : ", end="")

if (ss.startswith("(") == False) :
    print("(", end="")

print(ss, end="")

if (ss.startswith(')') == False) :
    print(")", end="")

        


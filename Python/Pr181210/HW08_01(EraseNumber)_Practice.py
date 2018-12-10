# -*- coding: utf-8 -*-
"""
Created on Mon Dec 10 23:01:36 2018

@author: Isaac
"""
str_output = ''
str_input = input("문자열 입력 : ")
for i in range(len(str_input)) :
    if not (str_input[i].isdigit()) :
        str_output += str_input[i]

print(str_input)
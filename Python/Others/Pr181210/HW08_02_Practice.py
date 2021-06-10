# -*- coding: utf-8 -*-
"""
Created on Mon Dec 10 22:55:36 2018

@author: Isaac

문자 구별

"""
count_lower = 0
count_num = 0
str_input = input("문자열 입력 : ")
for i in range(len(str_input)) :
    if(str_input[i].islower()) :
        count_lower += 1
    elif (str_input[i].isdigit()) :
        count_num += 1
        
print(count_lower)
print(count_num)

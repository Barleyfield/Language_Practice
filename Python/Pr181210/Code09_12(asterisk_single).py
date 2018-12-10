# -*- coding: utf-8 -*-
"""
Created on Tue Dec 11 00:06:35 2018

@author: Isaac

*para
매개변수의 개수를 지정하지 않고 전달

"""

def para_func(*para) :
    result = 0
    for num in para :
        result += num
        
    return result

hap = 0
hap = para_func(10,20)
print("매개변수 10, 20 합 : %d" % hap)
hap = para_func(10,20,30,40,50,60)
print("매개변수 10, 20, 30, 40, 50, 60 합 : %d" % hap)


# -*- coding: utf-8 -*-
"""
Created on Wed Nov 21 22:47:12 2018

@author: Isaac
"""

def factorial(num) :
    if (num <= 1) :
        return num
    else :
        return num * factorial(num-1)

print(factorial(4))
print(factorial(10))
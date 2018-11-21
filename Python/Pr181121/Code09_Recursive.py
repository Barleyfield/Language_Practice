# -*- coding: utf-8 -*-
"""
Created on Wed Nov 21 22:42:40 2018

@author: Isaac
"""

def count(num) :
    if(num>=1) :
        print(num, end=" ")
        count(num-1)
    else:
        return

count(10)
count(20)
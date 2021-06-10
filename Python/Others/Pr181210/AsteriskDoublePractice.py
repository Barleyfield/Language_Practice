# -*- coding: utf-8 -*-
"""
Created on Tue Dec 11 00:11:36 2018

@author: Isaac

Asterisk Double Practice
함수 매개변수 앞에 ** 붙임 (* 2개)

"""

def dic_func(**para) :
    for k in para.keys() :
        print("%s --> %d명입니다." % (k, para[k]))

dic_func(트와이스=9, 소녀시대=7, 걸스데이=4, 블랙핑크=4)



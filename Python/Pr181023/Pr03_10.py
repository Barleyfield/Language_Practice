# -*- coding: utf-8 -*-
"""
Created on Tue Oct 23 01:47:12 2018

// 16진수 판별하기

@author: Isaac
"""

while(True) :
    a = input('16진수 한 글자 입력 (-1 입력시 종료) : ')
    if(a == '-1') :
        break
    if( (ord(a) >= 48) and (ord(a) <= 57) ) :
        print("10진수 : %c" % a)
    elif( (ord(a) >= 65) and (ord(a) <= 69) )  :
        print("10진수 : %d" % (ord(a) - 55))
    else:
        print("16진수가 아닙니다.")
        

        
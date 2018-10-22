# -*- coding: utf-8 -*-
"""
Created on Tue Oct 23 02:05:56 2018

입력한 문자열을 거꾸로 출력하기

@author: Isaac
"""
inStr = ''

if __name__ == "__main__" :
    inStr = input('문자열 입력 : ')
    for i in range(len(inStr)-1,-1,-1) :
        print('%c' % inStr[i],end="")

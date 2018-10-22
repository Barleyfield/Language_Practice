# -*- coding: utf-8 -*-
"""
Created on Tue Oct 23 01:36:12 2018

@author: Isaac
"""

def myFunc() :
    print('함수를 호출합니다')


gVar = 100

if __name__ == '__main__' :
    print('메인 함수 부분이 실행됩니다.')
    myFunc()
    print('전역 변수 값 : ', gVar)
    
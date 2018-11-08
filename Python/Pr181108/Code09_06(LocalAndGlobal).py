# -*- coding: utf-8 -*-
"""
Created on Thu Nov  8 09:57:16 2018

@author: Barley

Local variable vs Global variable

"""

def func1() :
    # global a         # 이거 써 주면 전역 변수로 변환
    a = 10
    print("func1()에서 a값 : %d" % a)

def func2() :
    print("func2()에서 a값 : %d" % a)
    
## 전역 변수 선언 부분 ##
a = 20

func1()
func2()


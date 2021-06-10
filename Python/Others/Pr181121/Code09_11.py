# -*- coding: utf-8 -*-
"""
Created on Wed Nov 21 19:29:30 2018

@author: Isaac

매개변수 기본값 설정

"""

def para_func(v1,v2,v3=0) :
    result = 0
    result = v1 + v2 + v3
    return result

hap = 0

hap = para_func(10,20)
print("매개 변수가 2개인 함수를 호출한 결과 : %d" % hap)
hap = para_func(10,20,30)
print("매개 변수가 3개인 함수를 호출한 결과 : %d" % hap)



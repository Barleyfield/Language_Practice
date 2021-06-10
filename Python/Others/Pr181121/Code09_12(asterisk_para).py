# -*- coding: utf-8 -*-
"""
Created on Wed Nov 21 19:36:12 2018

@author: Isaac

*para : 매개 변수 개수 제한 없음. 대신 입력은 해 줘야 함.

"""

def para_func(*para) :
    result = 0
    for num in para :
        result = result + num

    return result

hap = 0

hap = para_func(10,20)
print("매개 변수가 2개인 함수를 호출한 결과 : %d" % hap)
hap = para_func(10,20,30)
print("매개 변수가 3개인 함수를 호출한 결과 : %d" % hap)



# -*- coding: utf-8 -*-
"""

Created on Wed Nov 21 17:31:48 2018

@author: Isaac

A는 지역 변수일까 전역 변수일까

"""

def func1() :
    global a    # 이 함수 안에서 a는 전역 변수.
                # global을 앞에 붙인다면 아무리 a를 미리 선언했어도 a는 10으로 바뀜.
    a = 10      # 지역 변수
    print("func1()에서 a값 : %d" % a)

def func2() :
    print("func2()에서 a값 : %d" % a)

a = 20      # 전역 변수

func1()
func2()






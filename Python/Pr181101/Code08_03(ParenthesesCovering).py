# -*- coding: utf-8 -*-
"""
Created on Thu Nov 1 09:37:20 2018

@author: 720-17

Space Remove

공백 제거 프로그램. 함수로 변형하였습니다.

"""

def SpaceRemove(s) :
    s2 = ''
    for i in range(0, len(s)) :
        if s[i] != ' ' :
            s2 += s[i]
    return s2

st = "공백을 제거합시다."
st2 = SpaceRemove(st)
print(st2)

            

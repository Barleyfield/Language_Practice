# -*- coding: utf-8 -*-
"""
Created on Mon Dec 10 22:20:25 2018

@author: Isaac

o to $
o를 $로 바꾸기

"""

ss = input("입력 문자열 : ")
print("출력 문자열 : ", end="")
for i in range(0, len(ss)) :
    if (ss[i] != 'o') :
        print(ss[i], end='')
    else :
        print("$", end='')
print()
print(ss.replace('$', 'o'))     # 한 줄로 고쳐 쓸 수 있음


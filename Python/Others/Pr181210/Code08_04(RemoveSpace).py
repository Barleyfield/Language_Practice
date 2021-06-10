# -*- coding: utf-8 -*-
"""
Created on Mon Dec 10 21:29:01 2018

@author: Isaac

Remove Space
앞, 뒤, 중간 공백까지 모두 제거

"""

inStr = input("공백 들어가게 문자열 입력 : ")
outStr = ''

for i in range(0, len(inStr)) :
    if (inStr[i] != ' ') :
        outStr += inStr[i]

print("원래 문자열 : " + '[' + inStr + ']')
print("공백 삭제 문자열 : " + '[' +outStr + ']')



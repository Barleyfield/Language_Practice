# -*- coding: utf-8 -*-
"""
Created on Tue Nov 13 00:23:01 2018

@author: Isaac
"""

inStr = "<<<파<<이>>썬>>>"
outStr = ""

for i in range(0, len(inStr)) :
    if ( (inStr[i] != '<') and (inStr[i] != '>') ) :
        outStr += inStr[i]

print("입력 : " + inStr)
print("결과 : " + outStr)
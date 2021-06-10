# -*- coding: utf-8 -*-
"""
Created on Mon Nov 12 21:08:59 2018

@author: Isaac
"""

ss = '    파      이       썬     '

print(ss.strip())
print(ss.lstrip())
print(ss.rstrip())

ss2 = '----파---이---썬----'
print(ss2.strip('-'))
ss2 = "<<<파 << 이 >> 썬>>>"
print(ss2.strip('<'))
print(ss2.strip('<>'))  # strip 안에 다른 문자와 공백 ' ' 을 같이 넣으면 공백도 삭제!


# -*- coding: utf-8 -*-
"""
Created on Tue Dec 11 00:14:19 2018

@author: Isaac
Lotto

"""

import random

def getNumber() :
    return random.randrange(1,46)

lotto = []
num = 0

print("로또 시작\n")
while True :
    num = getNumber()
    
    if lotto.count(num) == 0 :  # 중복 방지
        lotto.append(num)
        
    if len(lotto) >= 6 :
        break

print("추첨된 로또 번호 : ", end='')
lotto.sort()
for i in range(0,6) :
    print("%d " % lotto[i], end='')


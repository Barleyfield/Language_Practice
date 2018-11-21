# -*- coding: utf-8 -*-
"""
Created on Wed Nov 21 20:01:05 2018

@author: Isaac

Lotto

"""

import random

def getNumber() :
    return random.randrange(1,46)

# 전역 변수 선언 부분
lotto = []
num = 0

if __name__ == "__main__" :
    print("로또 추첨 시작~\n")
    
    while(True) :
        num = getNumber()
        if (lotto.count(num) == 0) :
            lotto.append(num)
        if (len(lotto)>6) :
            break
        
    print("추첨된 로또 번호 : ", end="")
    lotto.sort()
    for i in range(0,6) :
        print("%d " % lotto[i], end="")


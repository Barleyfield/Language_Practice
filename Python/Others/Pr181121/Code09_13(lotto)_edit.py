# -*- coding: utf-8 -*-
"""
Created on Wed Nov 21 20:14:11 2018

@author: Isaac

로또 번호 맞추기

"""
import random

def getNumber() :
    return random.randrange(1,46)

def InputNumber() :
    result_list = []
    print("로또 번호를 입력하세요", end="")
    for i in range(1,7) :
        num = int(input("%d번째 숫자 : " % i))
        result_list.append(num)
    return result_list
        

# 전역 변수 선언 부분
lotto = []
num = 0

if __name__ == "__main__" :
    print("로또 추첨 시작~\n")
    lotto_input = []
    lotto_input = InputNumber()
    correct = 0
    while(True) :
        num = getNumber()
        if (lotto.count(num) == 0) :
            lotto.append(num)
        if (len(lotto)>6) :
            break
    
    print("입력한 로또 번호 : ", end="")
    lotto_input.sort()
    for i in range(0,6) :
        print("%d " % lotto_input[i], end="")
    print()
    
    print("추첨된 로또 번호 : ", end="")
    lotto.sort()
    for i in range(0,6) :
        print("%d " % lotto[i], end="")
    print()
    
    for i in range(0,6) :
        if(lotto[i] == lotto_input[i]) :
            correct += 1
    print("%d개 맞추셨네요!" % correct, end="")
        
        



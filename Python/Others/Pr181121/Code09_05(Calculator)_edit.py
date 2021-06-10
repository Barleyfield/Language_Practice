# -*- coding: utf-8 -*-
"""
Created on Wed Nov 21 17:15:47 2018

@author: Isaac

Calculator 

"""

def calc(v1,v2,op) :
    result = 0
    if (op == '+') :
        result = v1 + v2
    elif (op == '-') :
        result = v1 - v2
    elif (op == '*') :
        result = v1 * v2
    elif (op == '/') :
        if(v2 == 0) :
            print("0으로 나눌 수 없습니다.")
            result = 0
        else :
            result = v1 / v2
    elif (op == '^') :      # 제곱
        result = v1 ** v2
    elif (op == '%') :      # 나머지
        result = v1 % v2
    else :
        result = 0
        print("잘못 입력하셨습니다.")
    return result

res = 0
var1, var2, oper = 0,0,""

oper = input("계산 입력 (+,-,*,/,^,%) : ")
var1 = int(input("첫 번째 수를 입력하세요 : "))
var2 = int(input("두 번째 수를 입력하세요 : "))
res = calc(var1, var2, oper)
print("계산기 : %d %s %d = %d" % (var1,oper,var2,res))
    


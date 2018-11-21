# -*- coding: utf-8 -*-
"""
142694 윤이삭 연습문제 10
피보나치 수열

"""
def Fibo(n) :
    if(n<=0) :
        return 0
    elif (n==1) :
        return 1
    else :
        return Fibo(n-1) + Fibo(n-2)

print(Fibo(7))
print(Fibo(9))
print(Fibo(30))

# -*- coding: utf-8 -*-
"""
Created on Wed May 19 13:15:05 2021

@author: Barley

Ch03-4 1이 될 때까지
어떤 수 N이 1이 될 때까지 다음 2가지 과정 중 하나를 반복적으로 선택해 수행하려고 한다.
단, 2번째 연산은 N이 K로 나누어떨어질 때만 선택할 수 있다.
1) N에서 1을 뺀다
2) N을 K로 나눈다.
예) N=17, K=4면 N-=1 수행 -> N=16, K=4. N/=4 2번 수행 시 N=1 가능
N과 K가 주어질 때 N이 1이 될 때까지 1번 혹은 2번의 과정을 수행해야 하는 최소 횟수를 구하라.

"""

n,k = map(int, input("N,K 입력 : ").split())
count = 0   # 계산 횟수 세기

while (n != 1) :
    if(n%k != 0) :
        n -= 1
    else :
        n /= k
    count += 1

print("최소 횟수 :", count)

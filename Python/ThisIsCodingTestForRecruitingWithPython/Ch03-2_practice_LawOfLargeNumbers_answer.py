# -*- coding: utf-8 -*-
"""
Created on Tue May 18 21:42:35 2021

@author: Barley

Ch03-2 실전문제 큰 수의 법칙 정답

"""

# N, M, K를 공백으로 구분해 입력받기
n,m,k = map(int, input().split())
# N개의 수를 공백으로 구분해 입력받기
data = list(map(int, input().split()))
data.sort()
first = data[n-1]
second = data[n-2]
result = 0

while True :
    for i in range(k) :
        if (m==0) :
            break
        result += first
        m -= 1
    if(m==0) :
        break
    result += second
    m -= 1

print(result)

# -*- coding: utf-8 -*-
"""
Created on Tue May 18 20:49:08 2021

@author: Barley

예제 3-1 거스름돈 정

그리디 알고리즘 활용 : 가지고 있는 동전 중에서 큰 단위가 항상 작은 단위의 배수.
 → 작은 단위의 동전을 종합해 다른 해가 나올 수 없다.

"""

n = int(input("거스름돈 : "))
count = 0

# 큰 단위의 화폐부터 차례로 확인
coin_types = [500,100,50,10]

for coin in coin_types :
    # 해당 화폐로 거슬러 줄 수 있는 동전의 개수 세기
    count += n // coin
    n %= coin

print(count)

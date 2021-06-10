# -*- coding: utf-8 -*-
"""
Created on Tue May 18 20:15:58 2021

@author: Barley

예제 3-1 거스름돈

조건 : 거스름돈은 항상 10의 배수

"""

money = int(input("거슬러줘야 할 돈 : "))
costs = [500,100,50,10]
coins = [0,0,0,0]

for i in range(0,4) :
    coins[i] = (int)(money / costs[i])
    money = (money - (costs[i]*coins[i]))

print(coins)
        
        


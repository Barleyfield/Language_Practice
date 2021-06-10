# -*- coding: utf-8 -*-
"""
Created on Wed May 19 09:11:01 2021

@author: Barley

Ch03-3 숫자 카드 게임
여러 개의 숫자 카드 중 가장 높은 숫자가 쓰인 카드 1장을 뽑는다.
규칙
- 숫자가 쓰인 카드들이 N x M 형태로 놓여 있다. 이때 N은 행의 개수이며, M은 열의 개수이다.
- 먼저 뽑고자 하는 카드가 포함된 행을 선택한다.
- 그다음 선택된 행에 포함된 카드들 중 카장 숫자가 낮은 카드를 뽑아야 한다.
- 따라서 처음에 카드를 골라낼 행을 선택할 때, 이후에 해당 행에서 가장 숫자가 낮은
카드를 뽑을 것을 고려하여 최종적으로 가장 높은 숫자의 카드를 뽑을 수 있도록 전략을
세워야 한다.

"""
n,m = input("N,M 입력 : ").split()
n = int(n)
m = int(m)

print("카드 입력 : ")
cards = [[int(x) for x in input().split()]for y in range(n)]

result = 0
for x in range(n) :
    cards[x].sort()
    if(x==0) :
        result = cards[x][0]
    else :
        if(result < cards[x][0]) :
            result = cards[x][0]
    

print(result)
        
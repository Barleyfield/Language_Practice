# -*- coding: utf-8 -*-
"""
Created on Wed May 19 13:07:58 2021

@author: Barley

Ch03-3 숫자 카드 게임 정답
"""

# N,M을 공백으로 구분하기
n,m = map(int, input().split())

result = 0
# 1줄씩 입력받아 확인
for i in range(n) :
    data = list(map(int, input().split()))
    # 현재 줄에서 가장 적은 수 찾기
    min_value = min(data)
    result = max(result, min_value)

# 최종 답안 출력
print(result)
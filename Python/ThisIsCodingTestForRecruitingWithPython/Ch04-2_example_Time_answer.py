# -*- coding: utf-8 -*-
"""
Created on Wed May 19 15:16:24 2021

@author: Barley

Ch04-2 예제 시각 정답

"""

# H 입력받기
h = int(input())

count = 0
for i in range(h+1) :
	for j in range(60) :
		for k in range(60) :
			# 매 시각 안에 3이 포함되어 있다면 카운트 증가
			if '3' in str(i) + str(j) + str(k) :
				count += 1

print(count)

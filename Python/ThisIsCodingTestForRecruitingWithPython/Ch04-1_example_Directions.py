# -*- coding: utf-8 -*-
"""
Created on Wed May 19 14:15:05 2021

@author: Barley

Ch04-1 예제 상하좌우
N x N 크기의 정사각형에서 N과 방향(L,R,U,D)가 주어졌을 때 최종 목적지 구하기
예) N=5, RRRUDD 입력 시 최종 좌표 (3,4) 출력
단, 정사각형 공간을 벗어나는 움직임 무시

"""

n = int(input("N 입력 : "))
directions = [x for x in input("방향들 입력 : ").split()]	# 좌표 입력
coord= [1,1]	# 현재 좌표

for x in directions :
	if (x=="L") :
		if(coord[1] == 1) :		# 왼쪽 끝에 있을 때
			continue
		else :
			coord[1] -= 1
	elif (x=="R") :
		if(coord[1] == n) :		# 오른쪽 끝에 있을 때
			continue
		else :
			coord[1] += 1
	elif (x=="U") :
		if(coord[0] == 1) :		# 제일 위에 있을 때
			continue
		else :
			coord[0] -= 1
	elif (x=="D") :
		if(coord[0] == n) :		# 제일 밑에 있을 때
			continue
		else : 
			coord[0] += 1
	else :
		continue

print(coord[0], coord[1])
			
		
			
		
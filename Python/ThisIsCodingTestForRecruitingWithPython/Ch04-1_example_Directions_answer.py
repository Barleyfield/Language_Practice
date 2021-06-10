# -*- coding: utf-8 -*-
"""
Created on Wed May 19 14:33:26 2021

@author: Barley

Ch04-1 예제 상하좌우 정답

"""

# N을 입력받기
n = int(input())
x,y = 1,1
plans = input().split()

# L,R,U,D에 따른 이동방향
dx = [0,0,-1,1]
dy = [-1,1,0,0]
move_types = ['L','R','U','D']

# 이동 계획을 하나씩 확인
for plan in plans :
	# 이동 후 좌표 구하기
	for i in range(len(move_types)) :
		if(plan == move_types[i]) :
			nx = x+dx[i]
			ny = y+dy[i]
	# 공간을 벗어나는 경우 무시
	if (nx<1 or ny<1 or nx>n or ny>n) :
		continue
	x,y = nx,ny

print(x,y)

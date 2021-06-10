# -*- coding: utf-8 -*-
"""
Created on Wed May 19 16:39:14 2021

@author: Barley

Ch04-3 실전문제 게임 개발

맵 : M x N 정사각형(M=가로,N=세로), 캐릭터가 있는 장소는 1x1의 정사각형
좌표 : (A,B)
캐릭터 움직임 매뉴얼
- 현재 위치에서 현재 방향을 기준으로 왼쪽 방향(반시계 방향으로 90도 회전한 방향)
부터 차례대로 갈 곳을 정한다.
- 캐릭터의 바로 왼쪽 방향에 아직 가보지 않은 칸이 존재한다면, 왼쪽 방향으로 회전
한 다음 왼쪽으로 1칸을 전진한다. 왼쪽 방향에 가보지 않은 칸이 없다면, 왼쪽 방향
으로 회전만 수행하고 1단계로 돌아간다.
- 만약 4방향 모두 이미 가본 칸이거나 바다로 되어 있는 칸인 경우에는, 바라보는
방향을 유지한 채로 1칸 뒤로 가고 1단계로 돌아간다. 단, 이때 뒤쪽 방향이 바다인
칸이라 뒤로 갈 수 없는 경우에는 움직임을 멈춘다.

입력 조건
(- 좌표 첫째 행 첫째 열 : 0,0인 것 같다.)
- 0:북쪽, 1:동쪽, 2:남쪽, 3:서쪽
- 0:육지, 1:바다
- 처음에 게임 캐릭터는 항상 육지에 위치

"""

n,m = map(int, input("N,M 입력 : ").split())
current_loc = [int(x) for x in input("캐릭터의 현재 위치와 방향 입력 : ").split()]


print("맵 입력 : ")
world_map = [[int(x) for x in input().split()] for y in range(m)]

directions = [0,1,2,3] # 방향
direction_ongoings = [[0,-1], [+1,0],[0,+1],[-1,0]]	# 해당 방향으로 진행
print(current_loc)
print(world_map)

# 방향 반시계 방향으로 순환하게 하기 : (4+처음 방향-i)%4
# 현재 위치에 지금 바라보는 방향으로 1칸 앞으로 갔을 때가 육지(0)인지 바다(1)인지 판단
# 육지일때 전진, 현재 위치 및 방향 수정, world_map에 가본 위치라고 '2'로 표시하기


next_dest = 0	# 임시로 사용할 다음 목적지
while True :
	for i in range(4) :
		next_dest = world_map[current_loc[0]+direction_ongoings[(4+current_loc[2]-i)%4][0]][current_loc[1]+direction_ongoings[(4+current_loc[2]-i)%4][1]]
		'''
		if(world_map
				[current_loc[0]+direction_ongoings[(4+current_loc[2]-i)%4][0]]
				[current_loc[1]+direction_ongoings[(4+current_loc[2]-i)%4][1]]
				== 0) :
			'''
		if(next_dest == 0) :
			current_loc[0] += direction_ongoings[(4+current_loc[2]-i)%4][0]
			current_loc[1] += direction_ongoings[(4+current_loc[2]-i)%4][1]
			current_loc[2] = (4+current_loc[2]-i)%4	# 현재 진행 방향으로 바꿔주기
			
			# 가봤음을 표시하기
			world_map[current_loc[0]+direction_ongoings[(4+current_loc[2]-i)%4][0]][current_loc[1]+direction_ongoings[(4+current_loc[2]-i)%4][1]] = 2
			
			print("Current Location : ", current_loc)
			break 		# 1칸 전진했으니 다음 목표 찾기
		else :
			print()
				


# print(world_map[current_loc[0]+direction_ongoings[(4+current_loc[2])%4][0]][current_loc[1]+direction_ongoings[(4+current_loc[2])%4][1]])
# print(world_map[(current_loc[0]+direction_ongoings[(4+current_loc[2])%4])][(current_loc[1]+direction_ongoings[(4+current_loc[2])%4])])


# 가봤으면 해당 좌표값을 2로 바꿔서 
'''
for x in range(m) :
	for y in range(n) :
		for i in range(4) :
			# if (world_map[x]+direction_ongoings[(4+current_loc[2]-i)%4]) :
			if (world_map[(current_loc[0]+direction_ongoings[(4+current_loc[2]-i)%4])]
					   [(current_loc[1]+direction_ongoings[(4+current_loc[2]-i)%4])]) :
'''
# -*- coding: utf-8 -*-
"""
Created on Wed May 19 15:24:55 2021

@author: Barley

Ch04-2 실전문제 왕실의 나이트
8x8 체스판에서 나이트가 이동할 수 있는 경우의 수 출력
가로는 a~h, 세로는 1~8
예) a1에 있으면 2가지 

"""

hori_loc = ['a','b','c','d','e','f','g','h']	# 가로 위치
verti_loc = [1,2,3,4,5,6,7,8]	 # 세로 위치
moves = [[-1,-2],[-2,-1],[+1,-2],[+2,-1],[-2,+1],[-1,+2],[+1,+2],[+2,+1]]	# 모든 움직임 경우의 수 
result = 0


knight = input("나이트의 현재 위치 : ")
# 인덱스에 1을 더해야 1~8이라는 위치를 출력
for move in moves :
	# print("나이트가 이동한 후 위치 : %d, %d" % (hori_loc.index(knight[0])+1 + move[0], (int)(knight[1]) + move[1]) )
	if( ((hori_loc.index(knight[0])+1) + move[0] >= 1) and
		((int)(knight[1]) + move[1] >= 1)
			) :
		result += 1
	

print("이동할 수 있는 경우의 수 : %d" % result)

# print(knight[0])
# print(hori_loc.index('b'))

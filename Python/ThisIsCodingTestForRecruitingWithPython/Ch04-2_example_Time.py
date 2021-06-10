# -*- coding: utf-8 -*-
"""
Created on Wed May 19 14:54:37 2021

@author: Barley

Ch04-2 예제 시각 
정수 N이 입력되면 00시 00분 00초부터 N시 59분 59초까지의 모든 시각 중에서
3이 하나라도 포함되는 모든 경우의 수는?
예) N=1이면 00시 00분 03초, 00시 13분 30초 등

"""

n = int(input("N 입력 : "))
result = 0
# h,m,t = 0,0,0	 # 시, 분, 초

for h in range(n+1) :
	for m in range(60) :
		for s in range(60) :
			if(		(h%10 == 3) or
					((int)(m/10) == 3) or (m%10 == 3) or
					((int)(s/10) == 3) or (s%10 == 3) ) :
				result += 1
				print("Time : %d:%d:%d" % (h,m,s))

print(result)
				
			
				
			
			


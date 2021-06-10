# -*- coding: utf-8 -*-
"""
Created on Tue May 18 20:59:39 2021

@author: Barley

Ch03-2 실전문제 큰 수의 법칙
- 다양한 수로 이루어진 배열(크기=N)이 있을 때 주어진 수를 M번 더하여 가장 큰 수를 만들기
- 배열의 특정한 인덱스(번호)에 해당하는 수가 연속해서 K번을 초과해 더해질 수 없다.
예) 2,4,5,4,6 배열, M=8, K=3이면 6+6+6+5+6+6+6+5 = 46
- 서로 다른 인덱스에 해당하는 수가 같은 경우에도 서로 다른 것으로 간주한다.
예) 3,4,3,4,3 배열, M=7, K=2이면 4+4+4+4+4+4+4 = 28

N : 배열의 크기
M : 숫자가 더해지는 횟수
K : 최대 연속 더하기 가능한 횟수

"""

n,m,k = input("N,M,K 순서대로 입력 : ").split()
n = int(n)
m = int(m)
k = int(k)

nums = [int(x) for x in input("배열에 들어갈 숫자들 입력 : ").split()]

# 내림차순 정렬 
nums.sort(reverse=True)

add_counter = 1
result = 0

'''
1. 큰 수가 하나만 있을 때
어차피 가장 큰 수를 만드는 것이므로 제일 큰 수 m번 더하고 2번째로 큰 수 1번 더해서
사이클을 돌리면 된다.
2. 큰 수가 2개 이상일 때 (즉 같은 큰 수가 여러 개일 때)
번갈아 2번씩 더하기 가능하므로 그냥 쭉 더하면 된다.
'''
if(nums[0] > nums[1]) :
    for i in range(m) :
        if(add_counter <= k) :
            result += nums[0]
            add_counter += 1
        else :
            add_counter = 1
            result += nums[1]
elif(nums[0] == nums[1]) :
    for i in range(m) :
        result += nums[0]
else :
    print("sort로 내림차순으로 정렬했는데도 nums[0]이 nums[1]보다 작다고?")

print("최종 결과 : %d" % result)
    
        
        
        

        
        



    

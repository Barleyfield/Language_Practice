# -*- coding: utf-8 -*-
"""
Created on Sun Oct 21 12:45:38 2018
Self Study 3-1 모래시계 출력
p. 67

@author: Isaac
"""

a = int(input('별의 개수를 입력하세요 : '))
left_num = 0; right_num = a-1;

star = []

for i in range(a) :
    star.append('*')

while(True) :
    if(star.count('*') < 1) :       # 별이 1개 이하면 가운데 인덱스만 별로 바꾸기.
        left_num = (int)(a/2)       # 왼쪽, 오른쪽 num은 각각 중앙으로 다시 맞추기.
        right_num = (int)(a/2)      # 그래야 밑에 있는 2번째 while문에서 다시 3개부터 출력.
        star[left_num] = '*'
        break
    for i in range(a):
        print(star[i], end="")
    star[left_num] = " "
    star[right_num] = " "
    left_num += 1
    right_num -= 1
    print("", end="\n")

while(True) :        
    if(star.count('*') == a) :
        break
    left_num -= 1
    right_num += 1
    star[left_num] = "*"
    star[right_num] = "*"
    for i in range(a) :
        print(star[i], end="")
    print("", end="\n")

input("Press Any key to exit")
    
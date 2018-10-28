# -*- coding: utf-8 -*-
"""
10개를 받아들여 가장 작은 값 출력 + 최솟값의 위치 출력

"""

aa = []


for i in range(0,10) :
    aa.append(0)
hap = 0


for i in range(0,10) :
    aa[i] = int(input(str(i+1) + "번째 숫자 : "))

# 리스트 함수 미사용
min = 0; minIndex = 0
min = aa[0]
for i in range(1, len(aa)):
    if min > aa[i]:
        min = aa[i]
        minIndex = i
print("가장 작은 값 : %d " % min)
print("가장 작은 값 위치 : " + str(minIndex+1))



# 리스트 함수 사용
bb = aa.copy()
bb.sort()
aa_least = bb[0]
aa_least_index = aa.index(aa_least)
print("가장 작은 값 : %d " % aa_least)
print("가장 작은 값 위치 : " + str(aa_least_index+1))


# -*- coding: utf-8 -*-
"""
Created on Mon Dec 10 19:47:43 2018

@author: Isaac

Make stack using list
스택을 이용한 리스트 구현

"""
def push(list_input, item) :        # 함수 안에서 전역 변수 사용 시 global 붙이기
    global top
    list_input.append(item)
    top += 1

def pop(list_input) :
    global top
    out_item = list_input.pop()
    top -= 1
    return out_item

parking = []
top = 0
push(parking, '자동차A')
push(parking, '자동차B')
push(parking, '자동차C')
print(parking, top)

outCar = pop(parking)
print(outCar, top)




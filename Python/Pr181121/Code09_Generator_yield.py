# -*- coding: utf-8 -*-
"""
Created on Wed Nov 21 22:54:53 2018

@author: Isaac

Generator and Yield

"""
def genFunc() :
    yield 1
    yield 2
    yield 3

print(list(genFunc()))

def genFunc2(num) :
    for i in range(0,num) :
        yield i
        print("제너레이터 진행 중")

for data in genFunc2(5) :
    print(data)


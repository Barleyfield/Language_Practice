# -*- coding: utf-8 -*-
"""
Created on Thu May 20 12:53:47 2021

@author: Barley

부록 A. 코딩 테스트를 위한 파이썬 문법

"""
from itertools import chain, combinations

# 리스트의 인덱싱과 슬라이싱
# a = [1,2,3,4,5,6,7,8]

# 부분집합(부분리스트)
def powerset(iterable) :
	s = list(iterable)
	return chain.from_iterable(combinations(s,r) for r in range(len(s)+1))

print(list(powerset([1,2,3])))



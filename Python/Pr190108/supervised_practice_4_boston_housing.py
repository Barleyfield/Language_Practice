# -*- coding: utf-8 -*-
"""
Created on Tue Jan  8 22:07:17 2019

@author: Isaac

지도 학습 연습하기 4 - 보스턴 주택 가격
- 회귀 분석용 실제 데이터셋
- 범죄율, 찰스 강 인접도, 고속도로 접근성 등의 정보로 1970년대 보스턴 주변의
  주택 평균 가격 예측

"""

import numpy as np
import scipy as sp
import pandas as pd
import matplotlib.pyplot as plt
import mglearn

from sklearn.datasets import load_boston
boston = load_boston()
print("데이터의 형태 : {}".format(boston.data.shape))
# 이 데이터 : 데이터 포인트 506개, 특성 13개

# 13개의 입력 특성뿐만 아니라 특성끼리 곱하여 의도적으로 확장 (상호 작용)
# → 특성 공학 (Featuer Engineering)
X,y = mglearn.datasets.load_extended_boston()
print("X.shape: {}".format(X.shape))
'''
(506, 104)가 나오는 이유?
중복조합 nHr = n+r-1Cr 이용하기.
13H2 = 13+2-1C2 = 91
처음 나온 13개 + 91개 = 총 104개
'''

print("y.shape: {}".format(y.shape)) # y.shape 쓰면 (506,) 처럼 왼쪽만 나옴.





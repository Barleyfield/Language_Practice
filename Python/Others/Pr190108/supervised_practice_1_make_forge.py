# -*- coding: utf-8 -*-
"""
Created on Tue Jan  8 21:00:36 2019

@author: Isaac

지도 학습 연습하기 1 - make_forge 사용

"""
# matplotlib 사용 시 matplotlib.pyplot을 불러 와야 범례가 제대로 표시됨.
# 그리고 한글 쓰니 깨진다.

import numpy as np
import scipy as sp
import matplotlib.pyplot as plt
import pandas as pd
import mglearn

# 데이터셋 만들기
# 인위적으로 만든 이진 분류 데이터셋
X, y = mglearn.datasets.make_forge()

# 산점도 그리기
mglearn.discrete_scatter(X[:, 0], X[:, 1], y)
plt.legend(["Class 0", "Class 1"], loc=4)
plt.xlabel("First characteristic")      # 첫 번째 특성
plt.ylabel("Second characteristic")     # 두 번째 특성
print("X.shape: {}".format(X.shape))




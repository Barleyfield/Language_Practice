# -*- coding: utf-8 -*-
"""
Created on Tue Jan  8 21:49:03 2019

@author: Isaac

지도 학습 연습하기 2 - make_wave() 사용

"""
# matplotlib 사용 시 matplotlib.pyplot을 불러 와야 범례가 제대로 표시됨.
# 그리고 한글 쓰니 깨진다.

import numpy as np
import scipy as sp
import matplotlib.pyplot as plt
import pandas as pd
import mglearn


# 회귀 알고리즘
# 인위적으로 만든 wave 데이터셋 사용
X, y = mglearn.datasets.make_wave(n_samples=40)
plt.plot(X,y,'o')
plt.ylim(-3, 3)
plt.xlabel("Characteristics")
plt.ylabel("Targets")

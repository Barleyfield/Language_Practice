# -*- coding: utf-8 -*-
"""
Created on Mon Jan  7 16:22:14 2019

@author: Isaac

Matplotlib Practice 1

"""
# Jupyter Notebook을 이용하여 브라우저에서 바로 이미지를 보기
# %matplotlib inline

import numpy as np
from scipy import sparse
import matplotlib.pyplot as plt

# -10에서 10까지 100개의 간격으로 나뉜 배열 생성
x = np.linspace(-10, 10, 100)
# sin 함수를 사용하여 y 배열 생성
y = np.sin(x)
# plot 함수는 한 배열의 값을 다른 배열에 대응하여 선 그래프를 그림
plt.plot(x, y, marker="x")






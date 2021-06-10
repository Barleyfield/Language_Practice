# -*- coding: utf-8 -*-
"""
Created on Tue Jan  8 22:23:10 2019

@author: Isaac

지도 학습 연습하기 5 - KNN
K-최근접 이웃 (K-Nearest Neighbors)

"""

import numpy as np
import scipy as sp
import pandas as pd
import matplotlib.pyplot as plt
import mglearn


# KNN 알고리즘 예시
# n_neighbors : 최근접 이웃 몇 개 사용?
mglearn.plots.plot_knn_classification(n_neighbors=3)

# scikit-learn을 사용해 KNN 적용하기
# 먼저 일반화 성능을 평가할 수 있도록 데이터를 훈련 세트와 테스트 세트로 나누기
from sklearn.model_selection import train_test_split
X,y = mglearn.datasets.make_forge()
X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0)

# KNeighborsClassifier를 import하고 객체 만들기
# 이 때, 이웃의 수 같은 매개 변수 지정
from sklearn.neighbors import KNeighborsClassifier
clf = KNeighborsClassifier(n_neighbors=3)

# 훈련 세트를 사용하여 분류 모델 학습
# X_train : 데이터, y_train : 클래스 레이블
clf.fit(X_train, y_train)

# 테스트 데이터에 대해 predict 메소드를 호출하여 예측
# 테스트 세트의 각 데이터 포인트에 대해 훈련 세트에서 가장 가까운 이웃을 계산한 다음, 가장 많은 클래스 찾기
print("테스트 세트 예측 : {}".format(clf.predict(X_test)))

# score 메소드로 모델 일반화 정확도 확인
print("테스트 세트 정확도 : {:.2f}".format(clf.score(X_test, y_test)))








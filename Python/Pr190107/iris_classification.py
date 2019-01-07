# -*- coding: utf-8 -*-
"""
Created on Mon Jan  7 17:45:27 2019

@author: Isaac

붓꽃의 품종 분류하기
- 훈련/테스트 나누기
- KNN (K-Nearest Neighbors)
- 예측하기
- 모델 평가하기

"""


import numpy as np
import scipy as sp
import pandas as pd
import matplotlib as plt
import mglearn
from sklearn.model_selection import train_test_split
from sklearn.datasets import load_iris
from sklearn.neighbors import KNeighborsClassifier

iris_dataset = load_iris()

X_train, X_test, y_train, y_test = train_test_split(
        iris_dataset['data'], iris_dataset['target'], random_state = 0)
# random_state : 난수 초깃값. 이 값을 지정하면 코드는 항상 같은 결과를 출력한다.

print("X_train 크기 : {}".format(X_train.shape))
print("y_train 크기 : {}".format(y_train.shape))
print("X_test 크기 : {}".format(X_test.shape))
print("y_test 크기 : {}".format(y_test.shape))


# X_train 데이터를 사용해 데이터프레임 만들기
# 열의 이름은 iris_dataset.feature_names에 있는 문자열 사용
iris_dataframe = pd.DataFrame(X_train, columns=iris_dataset.feature_names)

# 데이터프레임을 사용해 y_train에 따라 색으로 구분된 산점도 행렬 제작
'''
pd.plotting.scatter_matrix(iris_dataframe, c=y_train, figsize=(15,15),
                           marker='o', hist_kwds={'bins':20}, s=60, alpha=.8,
                           cmap=mglearn.cm3)
'''


# KNN은 KNeighborsClassifier 클래스에 구현.
# 중요한 매개 변수는 이웃의 개수이다 (여기서는 1로 지정)
knn = KNeighborsClassifier(n_neighbors=1)

# 훈련 데이터셋으로부터 모델을 만들려면 knn 객체의 fit 메서드 사용
# 데이터 : X_train, 레이블 : y_train 사용
# fit 메소드는 knn 객체 자체를 반환하고 변경시킨다. 그래서 여기서는 print와 함께 사용하였다.
print(knn.fit(X_train, y_train))


# 예측하기
# 꽃받침 길이 5cm, 폭 2.9cm / 꽃잎 길이 1cm, 폭 0.2cm 붓꽃 찾음. 이 붓꽃의 품종 찾기.
# 측정값을 numpy 배열로 만들기 (샘플의 수 * 특성의 수)
# 붓꽃 하나의 측정값은 2차원 numpy 배열에 행으로 들어간다.
# (scikit-learn은 항상 데이터가 2차원 배열일 것으로 예상)
X_new = np.array([[5, 2.9, 1, 0.2]])
print("X_new.shape : {}".format(X_new.shape))

# 예측에는 knn 객체의 predict 메소드 사용
prediction = knn.predict(X_new)
print("예측 : {}".format(prediction))
print("예측한 타겟의 이름 : {}".format(iris_dataset['target_names'][prediction]))


# 모델 평가하기
# 정확도를 계산하여 모델의 성능 평가.
y_pred = knn.predict(X_test)
print("테스트 세트에 대한 예측값: \n {}".format(y_pred))
print("테스트 세트의 정확도 : {:.2f}".format(np.mean(y_pred == y_test)))
print("테스트 세트의 정확도 (knn.score 이용) : {:.2f}".format(knn.score(X_test, y_test)))









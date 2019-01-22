'''

파이썬 라이브러리를 활용한 머신 러닝
Ch.5 모델 평가와 성능 향상
5.1 교차 검증
5.1.1 scikit-learn의 교차 검증


'''

import numpy as np
import scipy as sp
import pandas as pd
import matplotlib.pyplot as plt
import mglearn

from sklearn.model_selection import cross_val_score     # scikit-learn에 있는 교차 검증하는 함수. 매개 변수 : 모델, 훈련 데이터
# 참고 : cross_val_score은 모델을 반환하지 않는다.
from sklearn.datasets import load_iris
from sklearn.linear_model import LogisticRegression

# iris 데이터셋에 적용한 LogisticRegression을 평가하기
iris = load_iris()
logreg = LogisticRegression()

# 데이터셋을 나열 순서대로 k-fold로 나누었을 경우 - 0부터 나열되기 때문에 정확히 훈련되지 않는다.
print("Iris 레이블 (순서대로) : \n{}".format(iris.target))

scores = cross_val_score(logreg, iris.data, iris.target, cv=6)        # cross_val_score의 기본값은 3-fold.
print("교차 검증 점수 : {}".format(scores))
print("교차 검증 평균 점수 : {:.2f}".format(scores.mean()))             # 평균을 나타내려면 mean 사용



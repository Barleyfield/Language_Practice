'''

파이썬 라이브러리를 활용한 머신 러닝
Ch.5 모델 평가와 성능 향상
5.1.3 계층별 k-겹 겨차 검증과 그 외 전략들
교차 검증 상세 옵션

ML_practice_2.py에서 가져옴


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
from sklearn.model_selection import KFold

# iris 데이터셋에 적용한 LogisticRegression을 평가하기
iris = load_iris()
logreg = LogisticRegression()

# 데이터셋을 나열 순서대로 k-fold로 나누었을 경우 - 0부터 나열되기 때문에 정확히 훈련되지 않는다.
print("Iris 레이블 (순서대로) : \n{}".format(iris.target))

scores = cross_val_score(logreg, iris.data, iris.target, cv=6)        # cross_val_score의 기본값은 3-fold.
print("교차 검증 점수 : {}".format(scores))
print("교차 검증 평균 점수 : {:.2f}".format(scores.mean()))             # 평균을 나타내려면 mean 사용


# KFold 분할기 사용
# 용도 : 다른 사람의 결과를 재현하기 위해 분류 데이터셋에 기본 k-겹 교차 검증 사용
# n_splits=3으로 설정 시 iris 데이터의 클래스 개수인 3개와 같기 때문에 아무것도 학습할 수 없다.
kfold = KFold(n_splits=5)
print("\nKFold 분할기 사용")
print("교차 검증 점수 : \n{}".format(cross_val_score(logreg, iris.data, iris.target, cv=kfold)))

# KFold의 shuffle 매개변수를 True로 설정하면 샘플의 순서를 섞을 수 있다.
# random_state 매개변수로 특정 state(난수)일 때의 결과를 볼 수 있다.
kfold2 = KFold(n_splits=3, shuffle=True, random_state=0)
print("교차 검증 점수 (shuffle) : \n{}".format(cross_val_score(logreg, iris.data, iris.target, cv=kfold2)))

'''
LOOCV (Leave One Out Cross Validation)
Fold 하나에 샘플 하나만 들어 있는 k-겹 교차 검증
각 반복에서 하나의 데이터 포인트를 선택해 테스트 세트로 사용
작은 데이터셋에 더 효과적
'''
from sklearn.model_selection import LeaveOneOut
loo = LeaveOneOut()
scores = cross_val_score(logreg, iris.data, iris.target, cv=loo)
print("\nLOOCV 사용")
print("교차 검증 분할 횟수 : ", len(scores))
print("평균 정확도 : {:.2f}".format(scores.mean()))





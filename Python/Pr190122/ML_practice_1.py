'''

파이썬 라이브러리를 활용한 머신 러닝
Ch.5 모델 평가와 성능 향상
지도 학습 모델 평가와 매개변수 선택

'''

import numpy as np
import scipy as sp
import pandas as pd
import matplotlib.pyplot as plt
import mglearn

from sklearn.datasets import make_blobs
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split

# 인위적인 데이터셋 제작
X, y = make_blobs(random_state=0)

# 데이터와 타겟 레이블을 훈련 세트와 테스트 세트로 분할
X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0)

# 모델 객체를 만들고 훈련 세트로 학습 (fit)
logreg = LogisticRegression().fit(X_train, y_train)

# 모델을 테스트 세트로 평가 (score)
print("테스트 세트 점수 : {:.2f}".format(logreg.score(X_test, y_test)))

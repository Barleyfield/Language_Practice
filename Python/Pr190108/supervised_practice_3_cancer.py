# -*- coding: utf-8 -*-
"""
Created on Tue Jan  8 21:55:37 2019

@author: Isaac

지도 학습 연습하기 3 - 위스콘신 유방암 데이터셋 사용
- 각 종양은 양성(benign), 악성(malignant)으로 레이블되어 있음
- 조직 데이터를 기반으로 종양이 악성인지를 예측

"""

import numpy as np
import scipy as sp
import pandas as pd
import matplotlib.pyplot as plt
import mglearn

# scikit-learn에 있는 load_breast_cancer 함수로 데이터 불러옴
from sklearn.datasets import load_breast_cancer
cancer = load_breast_cancer()
print("cancer.keys() : \n{}".format(cancer.keys()))
print("유방암 데이터의 형태 : {}".format(cancer.data.shape))
print("클래스별 샘플 개수 : \n{}".format(
        {n: v for n, v in zip(cancer.target_names, np.bincount(cancer.target))}))

# feature_names 속성을 사용하면 각 특성의 의미를 알 수 있음
print("특성 이름 : \n{}".format(cancer.feature_names))




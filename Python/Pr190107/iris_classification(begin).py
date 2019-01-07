# -*- coding: utf-8 -*-
"""
Created on Mon Jan  7 17:01:19 2019

@author: Isaac

붓꽃의 품종 분류하기 - 데이터 살펴보기

"""

import numpy as np
import scipy as sp
import matplotlib as plt
import pandas as pd
import mglearn
from sklearn.datasets import load_iris

iris_dataset = load_iris()
print("iris_dataset의 키 : \n{}".format(iris_dataset.keys()))

# iris 데이터셋에 대한 간략한 설명
print("iris dataset 설명 : ")
print(iris_dataset['DESCR'] + "\n...")

# target_names : 우리가 예측하려는 붓꽃 품종의 이름을 문자열 배열로 가지고 있음
print("타깃의 이름 : {}".format(iris_dataset['target_names']))

# feature_name : 각 특성을 설명하는 문자열 리스트
print('특성의 이름 : \n{}'.format(iris_dataset['feature_names']))

# data : 꽃잎의 길이와 폭, 꽃받침의 길이와 폭을 수치 값으로 가지고 있는 numpy 배열
print("data의 타입 : {}".format(type(iris_dataset['data'])))
print("data의 크기 : {}".format(iris_dataset['data'].shape)) # shape : numpy 배열의 구조를 표현
print("data의 처음 다섯 행 : \n{}".format(iris_dataset['data'][:5]))  # 다섯 붓꽃의 꽃잎 폭은 모두 0.2cm이다. 첫 번째 꽃이 가장 긴 5.1cm의 꽃받침을 가졌다.

# target 배열 : 샘플 붓꽃의 품종을 담은 numpy 배열
print("target의 타입 : {}".format(type(iris_dataset['target'])))
print("target의 크기 : {}".format(iris_dataset['target'].shape))
print("타겟 : \n{}".format(iris_dataset['target']))         # 숫자의 의미 : iris['target_names'] 배열의 인덱스.
                                                            # 0 : setosa, 1 : versicolor, 2 : virginica
                                                            




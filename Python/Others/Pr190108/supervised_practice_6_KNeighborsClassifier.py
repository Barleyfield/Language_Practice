# -*- coding: utf-8 -*-
"""
Created on Tue Jan  8 22:37:37 2019

@author: Isaac

지도 학습 연습하기 6 - KNeighborsClassifier 분석


"""

import numpy as np
import scipy as sp
import pandas as pd
import matplotlib.pyplot as plt
import mglearn

# supervised_practice_5_KNN에서 가져옴
from sklearn.model_selection import train_test_split
X,y = mglearn.datasets.make_forge()
X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0)

from sklearn.neighbors import KNeighborsClassifier
clf = KNeighborsClassifier(n_neighbors=3)
clf.fit(X_train, y_train)
# --------


fig, axes = plt.subplots(1, 3, figsize=(10,3))

for n_neighbors, ax in zip([1,3,9], axes) :
    # fit 메소드는 self 객체를 반환
    # 그래서 객체 생성과 fit 메소드를 한 줄 안에 쓸 수 있다.
    clf = KNeighborsClassifier(n_neighbors=n_neighbors).fit(X,y)
    mglearn.plots.plot_2d_separator(clf, X, fill=True, eps=0.5, ax=ax,
                                     alpha=.4)
    mglearn.discrete_scatter(X[:,0], X[:,1], y, ax=ax)
    ax.set_title("{} Neighbors".format(n_neighbors))
    ax.set_xlabel("Characteristic 0")
    ax.set_ylabel("Characteristic 1")

axes[0].legend(loc=3)

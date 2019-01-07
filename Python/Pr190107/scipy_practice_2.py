# -*- coding: utf-8 -*-
"""
Created on Mon Jan  7 16:16:59 2019

@author: Isaac

SciPy Practice 2

COO 포맷을 이용해 희소 행렬 만들기
(COO 포맷 : Coordinate Format)
자세한 내용 : http://www.scipy-lectures.org의 2.5절

"""

import numpy as np
from scipy import sparse

data = np.ones(4)
row_indices = np.arange(4)
col_indices = np.arange(4)
eye_coo = sparse.coo_matrix((data, (row_indices, col_indices)))
print("COO 표현 : \n{}".format(eye_coo))



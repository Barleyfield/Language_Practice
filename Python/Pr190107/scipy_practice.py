# -*- coding: utf-8 -*-
"""
Created on Mon Jan  7 16:06:00 2019

@author: Isaac

SciPy Practice

"""
import numpy as np
from scipy import sparse
# sparse : 부족한, 희박한

# 대각선 원소는 1이고 나머지는 0인 2차원 numpy 배열 만들기
eye = np.eye(4)
print("NumPy 배열 : \n{}".format(eye))

# numpy 배열을 CSR 포맷의 scipy 희소 행렬로 변환
# 0이 아닌 원소만 저장
sparse_matrix = sparse.csr_matrix(eye)
print("SciPy의 CSR 행렬 : \n{}".format(sparse_matrix))






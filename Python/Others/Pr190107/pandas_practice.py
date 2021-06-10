# -*- coding: utf-8 -*-
"""
Created on Mon Jan  7 16:26:33 2019

@author: Isaac

pandas practice 1

딕셔너리를 사용하여 DataFrame 만들기

"""

import pandas as pd

# 회원 정보가 들어간 간단한 데이터셋 생성
data = {'Name' : ["John", "Anna", "Peter", "Linda"],
        'Location' : ["New York", "Paris", "Berlin", "London"],
        'Age' : [24, 13, 53, 33]
        }

data_pandas = pd.DataFrame(data)

# Ipython.display는 Jupyter Notebook에서 DataFrame을 예쁘게 출력해줌
display(data_pandas)

# Age 열의 값이 30 이상인 모든 행을 선택
display(data_pandas[data_pandas.Age > 30])





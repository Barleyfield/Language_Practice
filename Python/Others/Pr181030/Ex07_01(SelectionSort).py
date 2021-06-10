# -*- coding: utf-8 -*-
"""
Created on Tue Oct 30 09:18:05 2018

@author: Barley

Selection Sort Example

"""

import random

data = []
i,k = 0,0

## Main Code ##
if __name__ == "__main__" :
    for i in range(0,10) :
        tmp = random.randrange(0,100000)
        data.append(tmp)
    print("정렬 전 데이터 : ", end='')
    [print(num, end=' ') for num in data]
    
    for i in range(0, len(data) - 1) :
        for k in range(i+1, len(data)) :
            if data[i] > data[k] :          # SWAP
                tmp = data[i]
                data[i] = data[k]
                data[k] = tmp
    
    print('\n정렬 후 데이터 : ', end='')
    [print(num, end=' ') for num in data]
    

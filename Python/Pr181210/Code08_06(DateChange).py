# -*- coding: utf-8 -*-
"""
Created on Mon Dec 10 22:35:15 2018

@author: Isaac

Date Change
날짜 바꾸기
예 : 2019/12/31 입력 → 10년 후 : 2029년12월31일

"""

ss = input("날짜 입력 (연/월/일) : ")
ssList = ss.split('/')

print("입력한 날짜의 10년 후 : ", end='')
print(str(int(ssList[0]) + 10) + "년", end='')
print(ssList[1] + "월", end='')
print(ssList[2] + "일")




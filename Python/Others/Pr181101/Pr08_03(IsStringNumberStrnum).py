# -*- coding: utf-8 -*-
"""
Created on Thu Nov  1 09:58:59 2018

@author: Barley

글자? 숫자? 글자+숫자?


"""

st = input("문자열 입력 (영어 또는 숫자) : ")


if ( st.isalpha() and (not st.isdigit()) ) :
    print("글자입니다.")
elif ( (not st.isalpha()) and st.isdigit() ) :
    print("숫자입니다.")
elif st.isalnum() :
    print("글자 + 숫자입니다.")






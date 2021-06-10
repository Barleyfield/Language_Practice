# -*- coding: utf-8 -*-
"""
Created on Tue Nov  6 09:04:49 2018

@author: Barley

Swap Upper <-> lower not using swapcase()

"""

def swap_case(s) :
    ch = ""
    outStr = ""
    
    for i in range(len(s)) :
        ch = s[i]
        if( (ord(s[i]) >= ord("A")) and (ord(s[i]) <= ord("Z"))) :
            ch = ch.lower()
        elif( (ord(s[i]) >= ord("a")) and (ord(s[i]) <= ord("z")) ) :
            ch = ch.upper()
        outStr += ch
    
    return outStr


if __name__ == "__main__" :
    input_str = input("문자열 입력 : ")
    new_str = swap_case(input_str)
    print(new_str)


# -*- coding: utf-8 -*-
"""
Created on Tue Nov  6 09:43:17 2018

@author: Barley

Substring Count

"""

first = input("Enter the first string : ").strip()
second = input("Enter the second string : ").strip()

remainingLength = len(second)
startingIndex = 0;
result = -1
while(len(first) <= remainingLength) :
    if (first != second[startingIndex : startingIndex + len(first)]) :
        startingIndex += 1
        remainingLength -= 1
    else :
        result = startingIndex
        break

if (result != -1) :
    print(first, " is a substring of ", second)
else : 
    print(first, " is not a substring of ", second)

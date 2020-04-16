# -*- coding: utf-8 -*-
"""
Created on Fri Apr 17 02:22:34 2020

@author: Barley

텍스트파일을 읽어 한 문장으로 출력한다.
"""
# 텍스트 파일 읽기
f = open("./illegal_trade_word.txt", "r", encoding='UTF8')
words = f.readlines()
query = ""

# 텍스트에서 개행 문자 제거
words = [line.rstrip() for line in words]
for word in words :
    query = query + word + " OR "

print(query)


'''
while True :
    line = f.readline()
    if not line: break
    line.rstrip('\n')
    word_query = word_query + line + ' OR '
    print(line)
'''

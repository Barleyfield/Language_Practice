# -*- coding: utf-8 -*-
"""
8명의 학생과 10개의 문제
답안은 2차원 리스트에 저장

"""
from random import randint

def getRandomCharacter(ch1, ch2) :
    return chr(randint(ord(ch1), ord(ch2)))

def getRandomUpper() :
    return getRandomCharacter('A', 'E')


answers_row = []
answers = []

for i in range(0,8) :
    for k in range(0,10) :
        mark = getRandomUpper()
        print(mark, end=" ")
        answers_row.append(mark)
    answers.append(answers_row)
    answers_row = []
    print("")

keys = ['D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D']

for i in range(len(answers)) :
    CorrectCount = 0                    # 맞은 개수는 i가 증가될 때마다 초기화
    for k in range(len(answers[i])) :  # len(answers_row)로 하면 틀린다!
        if(answers[i][k] == keys[k]) :
            CorrectCount += 1
    print(str(i+1) + "번 학생의 정답 수는 " + str(CorrectCount) + "개입니다.")
        


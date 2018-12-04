# -*- coding: utf-8 -*-
"""
Created on Tue Dec  4 09:39:02 2018

@author: Barley

"""
from myTurtle import *
import turtle
inStr = ''
swidth, sheight = 300, 300
tX, tY, tAngle, tSize = [0] * 4

# 메인 #
turtle.title("거북이 글자쓰기(모듈버전)")
turtle.shape('turtle')
turtle.setup(width = swidth + 50, height = sheight + 50)
turtle.screensize(swidth, sheight)
turtle.penup()
turtle.speed(5)

inStr = getString()

for ch in inStr :
    tX, tY, tAngle, txtSize = getXYAS(swidth, sheight)
    r,g,b = getRGB()
    turtle.goto(tX,tY)
    turtle.left(tAngle)
    
    turtle.pencolor((r,g,b))
    turtle.write(ch, font=("맑은 고딕", txtSize, 'bold'))



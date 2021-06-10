# -*- coding: utf-8 -*-
"""
Created on Tue Dec 11 00:39:58 2018

@author: Isaac

Turtle Gives String
거북이가 문자열 출력

"""

from myTurtle import *
import turtle

inStr = ''
swidth, sheight = 300, 300
tX, tY, tAngle, tSize = [0] * 4

turtle.title('거북이 글자쓰기(모듈버전)')
turtle.shape('turtle')
turtle.setup(width = swidth + 50, height = sheight + 50)
turtle.screensize(swidth, sheight)
turtle.penup()
turtle.speed(5)

inStr = getString()

for ch in inStr :
    tX, tY, tAngle, txtSize = getXYAS(swidth, sheight)
    r,g,b = getRGB()
    
    turtle.goto(tX, tY)
    turtle.left(tAngle)
    
    turtle.pencolor((r,g,b))
    turtle.write(ch, font=('맑은 고딕', txtSize, 'bold'))

turtle.done()


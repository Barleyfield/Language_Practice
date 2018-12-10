# -*- coding: utf-8 -*-
"""
Created on Tue Dec 11 02:07:22 2018

@author: Isaac

TK Image button
이미지를 누르면 대화 상자 출력

"""

from tkinter import *
from tkinter import messagebox

def myFunc() :
    messagebox.showinfo("사과 버튼", "사과가 귀엽죠?")

window = Tk()

photo = PhotoImage(file = "apple.gif")
button1 = Button(window, image=photo, command=myFunc)
button1.pack()

window.mainloop()


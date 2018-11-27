# -*- coding: utf-8 -*-
"""
Created on Tue Nov 27 09:41:52 2018

@author: Barley

Image Button

"""
from tkinter import *
from tkinter import messagebox

def myFunc() :
    messagebox.showinfo("강아지 버튼", "귀여운 강아지!")
    
    
window = Tk()
photo = PhotoImage(file = "gif/dog2.gif")
button1 = Button(window, image=photo, command=myFunc)
button2 = Button(window, text="파이썬 종료", fg="red", command=quit)
# command=quit을 설정한 버튼을 누르고 창을 종료하면 Python IDLE이 닫힌다.

button1.pack()
button2.pack()

window.mainloop()

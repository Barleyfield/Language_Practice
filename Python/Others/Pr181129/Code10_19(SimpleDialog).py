# -*- coding: utf-8 -*-
"""
Created on Thu Nov 29 10:01:42 2018

@author: Barley

Simple Dialog about dice

"""

from tkinter import *
from tkinter.simpledialog import *

window = Tk()
window.geometry("400x100")

label1 = Label(window, text="입력된 값")
label1.pack()
value = askinteger("확대배수", "주사위 숫자(1~6)를 입력하세요", minvalue=1, maxvalue=6)
label1.configure(text=str(value))
window.mainloop()


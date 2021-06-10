# -*- coding: utf-8 -*-
"""
Created on Tue Dec  4 09:02:20 2018

@author: Barley

"""

from tkinter import *
from tkinter.simpledialog import *

window = Tk()
window.geometry("400x100")

label1 = Label(window, text="입력된 값: ")
label1.pack()
ss=askstring("시작 1", "인사말?")  # 첫 번째 : 제목, 두 번째 : 질문
value = askinteger("확대배수", "주사위 숫자(1~6)을 입력하세요.", minvalue=1, maxvalue=6)

label1.configure(text=str(value))
window.mainloop()



# -*- coding: utf-8 -*-
"""

Created on Tue Nov 27 09:08:48 2018

@author: Barley

Label

"""

from tkinter import *
window = Tk()

label1 = Label(window, text="Cookbook~Python을")
label2 = Label(window, text="열심히", font=("궁서체",30),fg="blue")
label3 = Label(window, text="공부 중입니다.", bg="magenta", width=100, height=5)

label1.pack()
label2.pack()
label3.pack()

window.mainloop()

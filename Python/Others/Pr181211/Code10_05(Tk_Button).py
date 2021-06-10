# -*- coding: utf-8 -*-
"""
Created on Tue Dec 11 02:05:18 2018

@author: Isaac
"""

from tkinter import *
window = Tk()

button1 = Button(window, text="파이썬 종료", fg="red", command=quit)
button1.pack()

window.mainloop()
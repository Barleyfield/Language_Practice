# -*- coding: utf-8 -*-
"""
Created on Tue Dec 11 01:56:06 2018

@author: Isaac
"""

from tkinter import *
window = Tk()

photo = PhotoImage(file = "apple.gif")
label1 = Label(window, image=photo)
label1.pack()

window.mainloop()

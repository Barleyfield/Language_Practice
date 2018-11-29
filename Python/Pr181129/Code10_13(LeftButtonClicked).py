# -*- coding: utf-8 -*-
"""
Created on Thu Nov 29 09:06:57 2018

@author: Barley

Left Button Clicked

"""

from tkinter import *
from tkinter import messagebox

def clickLeft(event) :
    messagebox.showinfo("마우스", "마우스 왼쪽 버튼이 클릭됨")

window = Tk()
window.bind("<Button-1>",clickLeft)
window.mainloop()


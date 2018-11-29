# -*- coding: utf-8 -*-
"""
Created on Thu Nov 29 09:55:03 2018

@author: Barley

Menu in Window

"""

from tkinter import *
from tkinter import messagebox

def func_open() :
    messagebox.showinfo("메뉴선택", "열기 메뉴를 선택함")
    
def func_copy() :
    messagebox.showinfo("메뉴선택", "복사 메뉴를 선택함")

def func_paste() :
    messagebox.showinfo("메뉴선택", "붙여넣기 메뉴를 선택함")

def func_exit() :
    window.quit()
    window.destroy()

window = Tk()

mainMenu = Menu(window)
window.config(menu = mainMenu)

fileMenu = Menu(mainMenu)
mainMenu.add_cascade(label="파일", menu=fileMenu)
fileMenu.add_command(label="열기", command=func_open)
fileMenu.add_command(label="복사", command=func_copy)
fileMenu.add_command(label="붙여넣기", command=func_paste)
fileMenu.add_separator()
fileMenu.add_command(label="종료", command=func_exit)

window.mainloop()



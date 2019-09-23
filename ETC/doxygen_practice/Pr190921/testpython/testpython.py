import os

"""
@brief testpython
@details Test Python file for Doxygen practice
@author Barley
@date 2019-09-21
@version 1.0
"""

def getValue(num) :
    """Documentation of getValue
    Add 1 to parameter and return the value.
    """
    num = num + 1
    return num



if __name__ == "__main__" :  
    """Documentation of main
    Input a number and return +1 value.
    """
    number = int(input("input number : "))
    print(getValue(number))
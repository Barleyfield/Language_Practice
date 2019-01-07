# -*- coding: utf-8 -*-
"""
Created on Mon Jan  7 16:54:41 2019

@author: Isaac

Library Version Check

"""

import sys
print("Python 버전 : {}".format(sys.version))

import pandas as pd
print("pandas 버전 : {}".format(pd.__version__))

import matplotlib
print("matplotlib 버전 : {}".format(matplotlib.__version__))

import numpy as np
print("NumPy 버전 : {}".format(np.__version__))

import scipy as sp
print("SciPy 버전 : {}".format(sp.__version__))

import IPython
print("IPython 버전 : {}".format(IPython.__version__))

import sklearn
print("scikit-learn 버전 : {}".format(sklearn.__version__))

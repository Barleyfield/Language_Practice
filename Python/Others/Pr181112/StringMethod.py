# -*- coding: utf-8 -*-
"""
Created on Mon Nov 12 21:00:26 2018

@author: Isaac

"""

ss = "Python is easy. 그래서 Programming이 재미있습니다 ^^. 물론 모든 공부가 다 재미있지는 않죠 ^^ 그래도 파이팅~"
print(ss.upper())
print(ss.lower())
print(ss.swapcase())
print(ss.title())

print(ss.count('공부'))
print(ss.find('공부'), ss.rfind('공부'), ss.find('공부', 5), ss.find('없다'))
print(ss.index('공부'), ss.rindex('공부'), ss.index('공부', 5)) # ss.index("없다") 는 오류 출력.
print(ss.startswith('Python'), ss.startswith('Python', 10), ss.endswith('~'))


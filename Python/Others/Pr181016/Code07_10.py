# -*- coding: utf-8 -*-
"""
Created on Tue Oct 16 09:46:38 2018

@author: Barley
"""

foods = {"떡볶이":"오뎅",
         "짜장면":"단무지",
         "라면":"김치",
         "피자":"피클",
         "맥주":"땅콩",
         "치킨":"치킨무",
         "삼겹살":"상추"
         };

while(True):
    myfood = input(str(list(foods.keys())) + "중 좋아하는 음식은?: ")
    if myfood in foods :
        print("<%s> 궁합 음식은 <%s>입니다." % (myfood, foods.get(myfood)))
    elif myfood == "끝" :
        break
    else :
        print("그런 음식은 없습니다.")
        


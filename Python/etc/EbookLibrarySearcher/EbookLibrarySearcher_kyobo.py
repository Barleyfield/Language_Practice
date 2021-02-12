# -*- coding: utf-8 -*-
"""
Created by Barleyfield
Ebook library searcher v0.1
Only work in Gyeonggi cyber library.
"""

import requests
from bs4 import BeautifulSoup

book_name = input("Enter E-book name : ")
url_string = "http://ebook.namgu.gwangju.kr:8080/Kyobo_T3_Mobile/Phone/Main/Ebook_List.asp?sortType=3&keyword=" + book_name
webpage = requests.get(url_string)

soup = BeautifulSoup(webpage.content, "html.parser")

try :
    # len(soup)까지 해야 최대 범위까지 자동으로 출력.
    for x in range(len(soup)) :    
        print(soup.find_all("h3")[x].get_text())
# 책이 없으면 AttributeError: 'NoneType' object has no attribute 'string' 오류 출력
except AttributeError as AttErr :
    print("There is no book")
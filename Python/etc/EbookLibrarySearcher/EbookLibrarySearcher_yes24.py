# -*- coding: utf-8 -*-
"""
Created by Barley
Ebook Library Searcher - Yes24 ver.

"""
import requests
from bs4 import BeautifulSoup

yes24_query = "/xml.asp?startCount=0&currentPage=1&viewResultCount=20&mode=search&display=list&sortType=&category_id=&deviceType=2&strSearch="
url_string = "http://elib.gbgs.go.kr:80"
url_string_gwangju = "http://ebook.citylib.gwangju.kr:80/YES24/xml.asp?&startCount=0&currentPage=1&viewResultCount=20&mode=search&display=list&sortType=&category_id=&deviceType=2&strSearch="

book_name = input("전자책 검색 : ")
webpage = requests.get(url_string_gwangju+book_name)
soup = BeautifulSoup(webpage.content, "lxml")
# print(soup)
books = soup.select("pdName")
for book in books :
    print(book.text)

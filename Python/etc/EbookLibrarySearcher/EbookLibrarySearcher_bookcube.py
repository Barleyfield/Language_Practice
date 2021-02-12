# -*- coding: utf-8 -*-
"""
Created by Barley
Ebook Library Searcher - Bookcube ver.

"""
import requests
from bs4 import BeautifulSoup

bookcube_query = "/FxLibrary/product/list/?page=1&keyoption2=0&category=&searchoption=1&searchType=search&keyword="
url_string = "http://elib.gbgs.go.kr:8080"
url_string_jeonnam = "http://ebook.jne.go.kr:8084"

book_name = input("전자책 검색 : ")
webpage = requests.get(url_string+bookcube_query+book_name)
soup = BeautifulSoup(webpage.content, "html.parser")
# print(soup)
# books = soup.select("li.subject > a")
books = soup.select("div.subject")
for book in books :
    if(book.text.find("...")<0) :
        print(book.text)

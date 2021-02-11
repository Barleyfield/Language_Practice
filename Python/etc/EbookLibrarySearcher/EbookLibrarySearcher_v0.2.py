# -*- coding: utf-8 -*-
"""
Created by Barleyfield
Ebook library searcher v0.2
- Add multiple ebook libraries.

"""

import requests
from bs4 import BeautifulSoup

print("전자책 검색기")
print("※ 정확한 도서명을 입력하는 것이 좋습니다.")
book_name = input("전자책 검색 : ")

kyobo_query = "/Kyobo_T3_Mobile/Phone/Main/Ebook_List.asp?sortType=3&keyword="
kyobo_query_2 = "/search/searchList.ink?schDvsn=000&orderByKey=&schTxt="
library = {
    "경기도사이버도서관(교보문고)":"http://ebook.golibrary.go.kr:8091",
    "광산구통합도서관(교보문고)": "http://210.179.176.19:8000",
    "광주광역시립도서관(소장)(교보문고)": "http://ebook.citylib.gwangju.kr:80",
    "광주광역시립도서관(구독)(교보문고new)": "http://citylib.dkyobobook.co.kr:80",
    "남부대 전자도서관(교보문고)":"http://ebook.nambu.ac.kr:88",
    "강진군도서관(교보문고)":"http://www.gjlib.go.kr:8080",
    "강남구전자도서관(교보문고)":"http://ebook.gangnam.go.kr:80",
    "경산시립도서관(교보문고)":"http://elib.gbgs.go.kr:8085",
    "오산시중앙도서관(교보문고)":"http://elib.osanlibrary.go.kr:80",
    "경남대표도서관(교보문고)":"http://elib.gyeongnam.go.kr:8091",
    "청주시립도서관(교보문고)":"http://cjelib.cheongju.go.kr:8080",
    "청주시립도서관(구독)(교보문고new)": "http://cjelib.dkyobobook.co.kr:80",
    "광주광역시교육청 통합도서관(소장)(교보문고)":"http://libebook.gen.go.kr:80",
    "광주광역시교육청 통합도서관(구독)(교보문고new)":"http://libgen.dkyobobook.co.kr",
    "광주광역시 서구 통합도서관(소장)(교보문고)": "http://ebooks.seogu.gwangju.kr:80",
    "광주광역시 서구 통합도서관(구독)(교보문고new)": "http://seogulib.dkyobobook.co.kr"
    }

library_dict = dict(library)
library_name = library_dict.keys()
library_url = library_dict.values()

# 도서 검색 시작
print("------------------------")
for name, url in library_dict.items() :
    print("* " + name + " *")
    if name.find('교보문고new') >= 0 :
        # 교보문고new 형식 웹페이지면 kyobo_query_2 적용
        webpage = requests.get(url+kyobo_query_2+book_name)
    else :
        webpage = requests.get(url+kyobo_query+book_name)
        
    soup = BeautifulSoup(webpage.content, "html.parser")
    try :
        if name.find('교보문고new') >= 0 :
            books = soup.select("li.tit > a")
        else :
            books = soup.select("h3.subject")

        for book in books :
            print(book.text)
        print("------------------------")

    except :
        print("오류 발생")
# -*- coding: utf-8 -*-
"""
Created by Barley
전자도서관 검색기
지원 플랫폼 : 교보도서관, YES24, 북큐브

* Library used : requests, BeautlfiulSoup, lxml
"""

import requests
from bs4 import BeautifulSoup

print("전자책 검색기 by Barley")
print("※ 정확한 도서명/출판사명을 입력하는 것이 좋습니다.")
print("※ 현재 전북교육청 대출은 교보만 가능. 나머지는 로그인 불가")
print("※ 광주 남구 전자도서관(교보문고old) 정확한 주소 찾기")
book_name = input("전자책 검색 : ")

kyobo_query = "/Kyobo_T3_Mobile/Phone/Main/Ebook_List.asp?sortType=3&keyword="
kyobo_query_2 = "/search/searchList.ink?schDvsn=000&orderByKey=&schTxt="
yes24_query = "/xml.asp?startCount=0&currentPage=1&viewResultCount=20&mode=search&display=list&sortType=&category_id=&deviceType=2&strSearch="
bookcube_query = "/FxLibrary/product/list/?page=1&keyoption2=0&category=&searchoption=1&searchType=search&keyword="
library = {
    "경기도사이버도서관(교보문고old)":"http://ebook.golibrary.go.kr:8091",
    "광산구통합도서관(교보문고old)": "http://210.179.176.19:8000",
    "광주 남구 전자도서관(교보문고old)": "http://ebook.namgu.gwangju.kr:80",
    "광주 남구 전자도서관(yes24)": "http://ebook.namgu.gwangju.kr:8080",
    "광주광역시립도서관(소장)(교보문고old)": "http://ebook.citylib.gwangju.kr:80",
    "광주광역시립도서관(구독)(교보문고new)": "http://citylib.dkyobobook.co.kr:80",
    "광주광역시립도서관(yes24)": "http://ebook.citylib.gwangju.kr:80/YES24",
    "남부대 전자도서관(교보문고old)":"http://ebook.nambu.ac.kr:88",
    "남부대 전자도서관(yes24)": "http://ebook.nambu.ac.kr:88/YES24",
    "강진군도서관(교보문고old)":"http://www.gjlib.go.kr:8080",
    "강남구전자도서관(교보문고old)":"http://ebook.gangnam.go.kr:80",
    "경산시립도서관(교보문고old)":"http://elib.gbgs.go.kr:8085",
    "경산시립도서관(yes24)":"http://elib.gbgs.go.kr:80",
    "경산시립도서관(북큐브new)": "http://elib.gbgs.go.kr:8080",
    "오산시중앙도서관(교보문고old)":"http://elib.osanlibrary.go.kr:80",
    "경남대표도서관(교보문고old)":"http://elib.gyeongnam.go.kr:8091",
    "청주시립도서관(교보문고old)":"http://cjelib.cheongju.go.kr:8080",
    "청주시립도서관(구독)(교보문고new)": "http://cjelib.dkyobobook.co.kr:80",
    "광주광역시교육청 통합도서관(소장)(교보문고old)":"http://libebook.gen.go.kr:80",
    "광주광역시교육청 통합도서관(구독)(교보문고new)":"http://libgen.dkyobobook.co.kr",
    "광주광역시 서구 통합도서관(소장)(교보문고old)": "http://ebooks.seogu.gwangju.kr:80",
    "광주광역시 서구 통합도서관(구독)(교보문고new)": "http://seogulib.dkyobobook.co.kr",
    "영천시립도서관(yes24)": "http://www.yclib.go.kr:8080",
    "전남대학교 전자도서관(yes24)" : "http://ebook.jnu.ac.kr:8800/YES24",
    "전남대학교 전자도서관(북큐브old)": "http://ebook.jnu.ac.kr:8088",
    "전남도립도서관(yes24)": "http://152.99.134.221:8080",
    "전라북도교육청 통합도서관(교보문고old)": "http://ebook.jbe.go.kr:10011",
    "전라북도교육청 통합도서관(yes24)": "http://ebook.jbe.go.kr:10061",
    "전라북도교육청 통합도서관(북큐브old)": "http://ebook.jbe.go.kr:10046",
    "전라남도교육청 통합도서관(교보문고old)": "http://ebook.jne.go.kr:8100",
    "전라남도교육청 통합도서관(yes24)" : "http://ebook.jne.go.kr:8080/B2B_JNE",
    "전라남도교육청 통합도서관(북큐브old)": "http://ebook.jne.go.kr:8084",
	"광주남구도서관(교보문고old)": "http://ebook.namgu.gwangju.kr:8000/"
    
    }

library_dict = dict(library)
# library_name = library_dict.keys()
# library_url = library_dict.values()

# 도서 검색 시작
print("------------------------")
for name, url in library_dict.items() :
    print("* " + name + " *")
    if name.find('교보문고new') >= 0 :
        # 교보문고new 형식 웹페이지면 kyobo_query_2 적용
        webpage = requests.get(url+kyobo_query_2+book_name)
    elif name.find('교보문고old') >= 0 :
        webpage = requests.get(url+kyobo_query+book_name)
    elif name.find('yes24') >= 0 :
        webpage = requests.get(url+yes24_query+book_name)
    elif name.find('북큐브') >= 0 :
        webpage = requests.get(url+bookcube_query+book_name)
        
    # Yes24의 경우 XML로 응답을 받아 오기 때문에 lxml을 쓰는 게 더 빠르다고 한다.
    if name.find('yes24') >= 0 :
        soup = BeautifulSoup(webpage.content, "lxml")
    else :
        soup = BeautifulSoup(webpage.content, "html.parser")
        
    try :
        if name.find('교보문고new') >= 0 :
            books = soup.select("li.tit > a")
        elif name.find('교보문고old') >= 0 :
            books = soup.select("h3.subject")
        elif name.find('yes24') >= 0 :
            books = soup.select("pdName")
        elif name.find('북큐브old') >= 0 :
            books = soup.select("li.subject")
        elif name.find('북큐브new') >= 0 :
            books = soup.select("div.subject")           
            
            
        for book in books :
            # 북큐브의 경우 결과들 아래에 ...으로 제목이 짤린 결과가 하나 더 나온다.
            # = 결과 중복 생략용
            if(book.text.find("...") < 0) :
                print(book.text)
        print("------------------------")

    except :
        print("오류 발생")
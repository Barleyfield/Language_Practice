# -*- coding: utf-8 -*-
"""
Created on Thu Apr 16 11:02:29 2020

author: Barley
source : https://jeongwookie.github.io/2019/06/10/190610-twitter-data-crawling/

"""

import datetime
import time
import GetOldTweets3 as got
import pandas as pd
# import matplotlib.pyplot as plt
from bs4 import BeautifulSoup
from random import uniform
from tqdm import tqdm_notebook

tweet_list = []
days_range = []
now = datetime.datetime.now()

# 수집 기간 설정 
# [현재 파일 실행 날짜 - 1] ~ [현재 파일 실행 날짜]
start_date = datetime.datetime.strptime((now - datetime.timedelta(days=1)).strftime("%Y-%m-%d"), "%Y-%m-%d")
start_date_string = start_date.strftime("%Y-%m-%d")
end_date = datetime.datetime.strptime((now + datetime.timedelta(days=1)).strftime("%Y-%m-%d"), "%Y-%m-%d")
end_date_string = end_date.strftime("%Y-%m-%d")
date_generated = [start_date + datetime.timedelta(days=x) \
                  for x in range(0, (end_date-start_date).days)]

for date in date_generated :
    days_range.append(date.strftime("%Y-%m-%d"))

# 트윗 수집 기준 정의
tweetCriteria = got.manager.TweetCriteria()\
                            .setQuerySearch('각종아이디판매 OR 아이디판매 OR ㄴㅔㅇㅣ버계정판매') \
                            .setSince(start_date_string)\
                            .setUntil(end_date_string)\
                            .setMaxTweets(10)       # -1개면 무한 수집
                            
# GetOldTweets3로 수집
print("데이터 수집 중... 기간 : {} ~ {}".format(days_range[0], days_range[-1]))
start_time = time.time()
tweet = got.manager.TweetManager.getTweets(tweetCriteria)

# 메타데이터 정리
for index in tqdm_notebook(tweet) :
    # 메타데이터 목록
    username = index.username
    link = index.permalink
    
    try :
        personal_link = 'https://twitter.com/' + username
    # 팔로잉 수 또는 팔로워가 공개되지 않은 트위터 계정은 수집 시 AttributeError 발생
    # 오류 발생 시 링크 출력
    except AttributeError :
        print("AttributeError 발생 게시물 : {}".format(link))
        print("AttributeError 발생 계정 : {}".format(personal_link))
    #info_list = [username, personal_link, link]
    info_list = ["윤이삭", "불법거래", personal_link, "트위터"]
    tweet_list.append(info_list)
    # 공격적인 크롤링으로 인한 랜덤 휴식시간 추가 (트위터의 크롤링 차단 방지)
    time.sleep(uniform(1,2))



print("수집 끝! 걸린 시간 : {0:0.2f} 분".format((time.time()-start_time)/60))
print("총 트윗 개수 : {}".format(len(tweet)))
print(tweet_list)

# CSV 파일로 저장
twitter_df = pd.DataFrame(tweet_list, columns=["신고자명", "구분", "URL", "비고(특이사항 등)"])
twitter_df.to_csv("개인정보_불법유통_방지_모니터링단_신고_윤이삭_{}.csv".format(days_range[-1]), encoding='utf-8-sig')

    

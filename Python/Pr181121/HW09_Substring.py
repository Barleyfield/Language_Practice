# -*- coding: utf-8 -*-
"""
142694 윤이삭 Substring 함수 만들기

<실행예>
Enter the first string: asdf
Enter the second string: vfrtgasdfnhy
asdf is a substring of vfrtgasdfnhy
Enter the first string: 깊은바다
Enter the second string: 파란하늘은 깊은바다와 같다
깊은바다 is a substring of 파란하늘은 깊은바다와 같다

"""


def Substring(subst,st) :
    if(st.find(subst) == -1) :
        print("%s에 해당하는 문자열이 없습니다." % subst)
    else :
        start_loc = st.find(subst)                          # Start Location. 부분문자열의 시작 위치
        print("%s is a substring of %s" % (subst,st))         # 0번째부터 계산하기 때문에 몇 번째인가를 반환하려면 1 더해주기
        print("부분문자열의 위치는 %d번째부터 %d번째까지입니다." % ( (start_loc+1), (start_loc+1+len(subst)) ))

if __name__ == "__main__" :
    substring = input("Enter the first string : ")
    string = input("Enter the second string : ")
    Substring(substring,string)
    
    
        
        

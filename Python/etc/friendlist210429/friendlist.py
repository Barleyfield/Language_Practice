# -*- coding: utf-8 -*-
"""
Created on Thu Apr 29 13:39:23 2021

@author: Barley

파일 수정 : https://ballentain.tistory.com/11

"""

def printData() :
    # f = open("friends.txt", 'r', encoding='utf-8')
    f = open("friends.txt", 'r')
    while True :
        line = (f.readline()).strip('\n')   # strip으로 개행 문자 제
        if not line :
            break
        friend_info = line.split(';')
        print(friend_info)
    f.close()
    print("print out all data...")
    
def inputData() :
    print("Input Data...")
    # f = open("friends.txt", 'a', encoding='utf-8')
    f = open("friends.txt", 'a')
    friend_name = input("친구의 이름은? : ")
    friend_num = input("친구의 학번은? : ")
    friend_address = input("친구의 주소는? : ")
    friend_info = '\n' + friend_name + ';' + friend_num + ';' + friend_address
    f.write(friend_info)
    f.close()
    print("성공적으로 자료를 추가했습니다.")

def deleteData() :
    print("delete Data...")
    friend_name = input('삭제할 친구의 이름은? : ')
    f = open('friends.txt', 'r')
    
    # 친구 정보 위치 찾고 텍스트 수정
    new_data = ''
    friends_list = f.readlines()
    friends_list_index = 0  # 찾는 친구가 몇 번째에 있는지 인덱스 출력
    for friend in friends_list :
        if friend.find(friend_name) >= 0 :
            # 해당하는 친구를 찾았으면 그대로 건너뛰
            continue
        else :
            new_data += friend
        friends_list_index += 1

    # 새로운 데이터는 문자열을 하나로 붙인 텍스트이므로 write 사용    
    f = open('friends.txt', 'w')
    f.write(new_data)
    f.close()
    print("성공적으로 자료를 삭제했습니다.")
    
def editData() :
    print("edit Data...")
    friend_name = input('수정할 친구의 이름은? : ')
    f = open('friends.txt', 'r') 
    
    # 새로운 친구 정보 입력
    friend_name_new = input('친구의 새 이름 : ')
    friend_num_new = input('친구의 새 학번 : ')
    friend_address_new = input('친구의 새 주소 : ')
    friend_info_new = friend_name_new + ';' + friend_num_new + ';' + friend_address_new + '\n'
    print('친구의 새 정보 : ' + friend_info_new)
    
    # 친구 정보 위치 찾고 텍스트 수정
    new_data = ''
    friends_list = f.readlines()
    friends_list_index = 0  # 찾는 친구가 몇 번째에 있는지 인덱스 출력
    for friend in friends_list :
        if friend.find(friend_name) >= 0 :
            # print("친구 정보 : " + friend)
            # print("몇 번째? : " + str(friends_list_index))
            new_data += friend_info_new
        else :
            new_data += friend
        friends_list_index += 1

    # 새로운 데이터는 문자열을 하나로 붙인 텍스트이므로 write 사용    
    f = open('friends.txt', 'w')
    f.write(new_data)
    f.close()
    print("성공적으로 자료를 수정했습니다.")

def readFile() :
    print("read Data from File")
    f = open('friends.txt', 'r')
    data = f.read()
    print(data)
    f.close()
    print("성공적으로 자료를 읽었습니다.")

def writeFile() :
    print("write Data to file")
    print("성공적으로 자료를 파일에 저장했습니다.")
    
menu = 0
# record = list()
# friends = list(list())

while menu != 9 :
    print("--Main Menu--")
    print("1. 친구 정보 출력")
    print("2. 친구 정보 추가")
    print("3. 친구 정보 삭제")
    print("4. 친구 정보 수정")
    print("5. 파일 자료 읽어오기")
    print("6. 파일에 자료 저장")   # 작성한 자료를 저장하기
    print("9. 종료")
    menu = int(input("메뉴를 선택하세요 : "))
    if menu == 1 :
        printData()
    elif menu == 2 :
        inputData()
    elif menu == 3 :
        deleteData()
    elif menu == 4 :
        editData()
    elif menu == 5 :
        readFile()
    elif menu == 6 :
        writeFile()

print("프로그램 종료")

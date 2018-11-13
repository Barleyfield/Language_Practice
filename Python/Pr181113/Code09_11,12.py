def para_func(v1,v2,v3=0) :
    result = 0
    result = v1 + v2 + v3
    return result

def para_func2(*para) :     # * 붙이면 튜플 형태로 받기. 리스트 넣으면 동작 안 함!
    result = 0
    for num in para :
        result = result + num

    return result

def para_func3(**para) :    # ** 붙이면 딕셔너리 형태로 받기
    for k in para.keys() :
        print("%s : %d명입니다." % (k,para[k]))

hap = 0
hap = para_func2(10,20)
print("매개 변수가 2개인 함수 호출 : %d" % hap)

para_func3(트와이스=9, 소녀시대=7, 걸스데이=4, 블랙핑크=4)

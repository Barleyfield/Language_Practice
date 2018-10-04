'''
142694 전자컴퓨터공학부 윤이삭

Ch 6-8
입력한 숫자의 2배만큼 별 출력
별 모양 유니코드 : \u2605

'''
#-*- coding: utf-8 -*-

# 자릿수 구하는 함수
# n이 1 이하가 나올 때까지 10으로 나눈다.
def getDigit(n) :
	digit_return = 0
	while(1) :			# 반복문. n을 계속해서 10으로 나눈다.
		if(n>=1):
			n /= 10		
			digit_return += 1
		else:
			break		# n을 10으로 나누었을 때 1 미만으로 나온다면 반복문을 탈출한다.
	return digit_return


star_num_input = int(input("숫자를 여러 개 입력하세요 : "));	# 숫자 입력
digit = getDigit(star_num_input) - 1		# 숫자의 자릿수 구하기
digit_list = []						        # 자릿수를 저장하는 배열.
num_temp = 0						        # 배열에 넣기 전 사용하는 임시 자릿수 변수

while(digit >= 0) :                         # 0 이상으로 설정해야 마지막 숫자가 잘리지 않는다.
	num_temp = int((star_num_input / (10**digit)))	# 해당 자릿수의 숫자를 num_temp에 저장한다.
							                # int형으로 지정해야 배열을 반복문에서 제대로 사용할 수 있다.

	# 10**digit으로 나누어 몫을 저장한 후, 나머지는 다시 (10**(digit-1))로 나눌 준비를 한다.
	digit_list.append(num_temp)			    # 배열에 저장.
	star_num_input %= (10**digit)			# 맨 앞 자릿수를 제거한 나머지 수 구하기
	digit -= 1					            # 자릿수 하나 줄이기
 


for i in range(len(digit_list)) :			# 몇 자리 수인지만큼 반복 (3자리수면 3번 반복)
    for j in range(digit_list[i]) :			# 자릿수만큼 반복 (3번째 자리가 7이면 7번 반복)
        print("\u2605\u2605", end="")		# 별을 출력하고 공백으로 마무리. 그래야 강제 개행되지 않음.
    print("", end="\n")					    # 공백을 출력하고 개행 문자로 마무리. 그래야 한 번 더 개행되지 않음.



input("Press Enter to end")



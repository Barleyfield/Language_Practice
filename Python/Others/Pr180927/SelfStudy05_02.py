first_num = int(input("첫 번째 숫자를 입력하세요: "))
second_num = int(input("두 번째 숫자를 입력하세요: "))
increase_num = int(input("더할 숫자를 입력하세요: "))
result = 0

for i in range(first_num, second_num+1, increase_num) :
    result += i

print("%d+%d+...+%d는 %d입니다." % (first_num, (first_num + increase_num), second_num, result))

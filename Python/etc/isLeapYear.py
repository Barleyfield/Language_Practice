year = int(input("연도 입력: "))

isLeapYear = ( (year % 4 == 0) and (year % 100 != 0) ) or (year % 400 == 0)

print(year, "년은 윤년입니까? ", isLeapYear)

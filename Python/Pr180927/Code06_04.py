num = int(input("몇까지 더할까? : "))
i=0; result=0

for i in range(0,num+1,1) :
    result += i

print("\n%d" % result)

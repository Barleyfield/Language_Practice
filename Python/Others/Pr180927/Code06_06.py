i=0; dan=0

dan = int(input("몇 단? : "))

for i in range(1,10,1) :
    print("%d X %d = %d" % (dan, i, dan*i), end="\n")

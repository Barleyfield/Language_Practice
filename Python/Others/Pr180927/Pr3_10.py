while(1) :
    char_input = input('16진수 한글자 입력 (-1 : 종료)  : ')
    if(type(char_input) == 'int'):
        if( (char_input >= 0) and (char_input <= 9) ) :
            print(char_input)
    else:
        if( (char_input >= 'A') and (char_input <= 'F') ) :
            if(char_input == 'A') :
                print(10)
            elif(char_input == 'B') :
                print(11)
            elif(char_input == 'C') :
                print(12)
            elif(char_input == 'D') :
                print(13)
            elif(char_input == 'E') :
                print(14)
            elif(char_input == 'F') :
                print(15)
            else :
                print("Wrong Input")

print("End!")
                
            
            

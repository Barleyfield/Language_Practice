import base64

# File name or path
filepath_encode = "encoded.txt"
filepath_decode = "decoded.txt"


# Encode string data once
def stringToBase64(s):
	return base64.b64encode(s.encode('utf-8'))

# Encode string data for loop (made this function because of difference between utf-8 and ascii)
def stringToBase64_ascii(s):
	s_binary = base64.b64encode(s.encode('utf-8'))
	s_ascii = s_binary.decode('ascii')
	return s_ascii

# Decode base64 data once
def base64ToString(b):
	return base64.b64decode(b).decode('utf-8')

# Encode binary file data
def fileToBase64(filepath):
	fp = open(filepath, "rb")
	data = fp.read()
	fp.close()
	return base64.b64encode(data).decode('utf-8')
	
	
if __name__ == "__main__" :
	menu = int(input("Encode or Decode? (1: Encode, 2: Decode) : "))
	if(menu == 1) :
		iter_number = int(input("How many times will you encode? : "))
		text = input("Which text do you want to encode? : ")

		for i in range(iter_number) :
			encode_text = stringToBase64_ascii(text)
			text = encode_text
		print(text)
		
		f = open(filepath_encode, 'w')
		f.write(text)
		f.close()
	elif(menu == 2) :
		iter_number = int(input("How many times will you decode? : "))
		text = input("Which text do you want to decode? : ")
		
		for i in range(iter_number) :
			decode_text = base64ToString(text)
			text = decode_text
		print(text)
		
		f = open(filepath_decode, 'w')
		f.write(text)
		f.close()
	
	else :
		print("Wrong input")

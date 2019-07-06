all: hello.o hello

hello.o: hello.asm
	nasm -f elf64 hello.asm
hello: hello.o
	ld -o hello hello.o

clean:
	rm -f hello.o hello

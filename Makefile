all:
	echo "error : listen.o file doesnt exist."
all : term_init.c main.c Event_listener.c
	@echo "==> compiling Evenet_listener.c ..."
	@gcc -c Event_listener.c -o listen.o
	@echo "==> compiling term_init.c ... "
	@gcc -c term_init.c -o init.o 
	@echo "==> compiling main.c ..."
	@gcc -c main.c -o main.o
	
	@echo "==> linking object files ..."
	@gcc main.o init.o listen.o -o output 

clean : main.o init.o listen.o
	@echo "==> removing dependencies ..."
	@rm main.o init.o listen.o

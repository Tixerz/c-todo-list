all:
	echo "error : listen.o file doesnt exist."
all : term_init.c main.c Event_listener.c ./display/blit.c ./display/comps/display_main_menu.c
	@echo "==> compiling Evenet_listener.c ..."
	@gcc -c Event_listener.c -o listen.o
	@echo "==> compiling term_init.c ... "
	@gcc -c term_init.c -o init.o
	@echo "==> compiling main.c ..."
	@gcc -c main.c -o main.o
	@echo "-=-=-=-= compiling display dependencies =-=-=-=-"
	@echo "==> compiling blit.c ..."
	@gcc -c ./display/blit.c -o blit.o
	@echo "==> compiling display_main_menu.c ..."
	@gcc -c ./display/comps/display_main_menu.c -o display_main_menu.o
	@echo "==> linking object files ..."
	@gcc main.o init.o listen.o  display_main_menu.o blit.o -o output
	@echo "==> removing dependencies ..."
	@rm main.o init.o listen.o blit.o display_main_menu.o

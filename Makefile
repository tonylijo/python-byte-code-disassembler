INCLUDEFLAGS := -I./ 
CFLAGS := -c
CC := gcc
OBJFLAG := -o
pydis: main.o decode.o
	$(CC) main.o decode.o $(OBJFLAG) pydis
decode.o: decode.c opcode.h
	$(CC) $(CFLAGS) $(INCLUDEFLAGS) decode.c
main.o: main.c
	$(CC) $(CFLAGS) main.c
clean: main.o decode.o
	rm main.o decode.o pydis

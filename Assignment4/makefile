#Dana Curca, 250976773, dcurca
CC = gcc
CFLAGS = -std=c99 
RMFLAGS = -f
EXNAME = ciphers

#Makefile for ciphers.c
$(EXNAME): ciphers.o cipher_main.o
	$(CC) $(CFLAGS) -o $(EXNAME) ciphers.o cipher_main.o
ciphers.o: ciphers.c ciphers.h
	$(CC) $(CFLAGS) -c ciphers.c
cipher_main.o: cipher_main.c ciphers.h
	$(CC) $(CFLAGS) -c cipher_main.c 
clean:
	rm $(RMFLAGS) $(EXNAME) *.o core 
test: 
	$(EXNAME)

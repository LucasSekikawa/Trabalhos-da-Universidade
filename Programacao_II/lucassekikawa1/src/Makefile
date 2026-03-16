CC = gcc
CFLAGS = -Wall -g
LIBS = -lm

tudo: juros
	mkdir -p ../bin
	mv juros ../bin

juros: juros.o arquivos.o calculos.o prints.o
	$(CC) $(CFLAGS) -o juros juros.o arquivos.o calculos.o prints.o $(LIBS)

juros.o: juros.c
	$(CC) $(CFLAGS) -c juros.c -o juros.o

arquivos.o: arquivos.c
	$(CC) $(CFLAGS) -c arquivos.c -o arquivos.o

calculos.o: calculos.c
	$(CC) $(CFLAGS) -c calculos.c -o calculos.o

prints.o: prints.c
	$(CC) $(CFLAGS) -c prints.c -o prints.o

limpa:
	rm -f *~ *.bak core

faxina: limpa
	rm -f juros.o arquivos.o calculos.o prints.o juros
	rm -rf ../bin/juros

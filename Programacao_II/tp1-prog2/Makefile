CC = gcc
CFLAGS = -Wall -g
LIBS = -lm

tudo: executavel
	mkdir lucassekikawa1/bin
	cp executavel lucassekikawa1/bin

executavel: juros.o arquivos.o calculos.o prints.o
	$(CC) $(CFLAGS) -o executavel juros.o arquivos.o calculos.o prints.o $(LIBS)

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
	rm -f juros.o arquivos.o calculos.o prints.o executavel
	rm -rf lucassekikawa1/bin
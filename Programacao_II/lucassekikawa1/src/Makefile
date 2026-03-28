CC = gcc
CFLAGS = -Wall -g
LIBS = -lm

OBJETOS = juros.o arquivos.o calculos.o prints.o processamento.o

tudo: juros
	mkdir -p ../bin
	mv juros ../bin

juros: $(OBJETOS)
	$(CC) $(CFLAGS) -o juros $(OBJETOS) $(LIBS)

juros.o: juros.c
	$(CC) $(CFLAGS) -c juros.c -o juros.o

arquivos.o: arquivos.c
	$(CC) $(CFLAGS) -c arquivos.c -o arquivos.o

calculos.o: calculos.c
	$(CC) $(CFLAGS) -c calculos.c -o calculos.o

prints.o: prints.c
	$(CC) $(CFLAGS) -c prints.c -o prints.o

processamento.o: processamento.c
	$(CC) $(CFLAGS) -c processamento.c -o processamento.o

limpa:
	rm -f *~ *.bak core

faxina: limpa
	rm -f $(OBJETOS) juros
	rm -rf ../bin/juros
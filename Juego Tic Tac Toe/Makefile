CC=gcc
CFLAGS=`pkg-config --cflags gtk+-3.0`
LFLAGS=`pkg-config --libs gtk+-3.0`
SRC=./ProyectoC_Grupo_8.c
EXE=exe

all:
	$(CC) $(CFLAGS) $(SRC) -o $(EXE) $(LFLAGS)

run:
	./exe

clean:
	rm exe

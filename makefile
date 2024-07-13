CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lncurses
SRC = main.c Components/Window/Widget.c

# Objetivo principal
all: main

# Objetivo específico app1
app1: VALUE=20
app1: main

# Regla de compilación principal
main: $(SRC)
	$(CC) $(CFLAGS) -DVALUE=$(VALUE) $(SRC) -o main $(LDFLAGS)

# Regla para limpiar archivos generados
clean:
	rm -f main

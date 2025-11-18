CC=gcc
CFLAGS=-Wall -std=c99

all: fractals

fractals: main.c mandelbrot.c burningship.c tricorn.c
<TAB>$(CC) $(CFLAGS) -o fractals main.c mandelbrot.c burningship.c tricorn.c -lm

clean:
<TAB>rm -f fractals *.o *.txt

all: make_pixels
	./a.out

make_pixels: make_pixels.c
	gcc make_pixels.c

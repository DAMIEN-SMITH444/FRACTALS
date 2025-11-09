Fractal Set Generators in C

This repo contains simple C programs generating three famous fractals:

    Mandelbrot set

    Julia set

    Tricorn (Mandelbar) set

Each program uses the escape-time algorithm and outputs a PPM image file.
Description

    Mandelbrot: iterates zn+1=zn2+czn+1=zn2+c with z0=0z0=0.

    Julia: fixes cc, iterates zn+1=zn2+czn+1=zn2+c with z0z0 from the pixel coordinates.

    Tricorn: iterates zn+1=zn‾2+czn+1=zn2+c (complex conjugate squared).

How to Compile & Run
gcc -o mandelbrot mandelbrot.c -lm
gcc -o julia julia.c -lm
gcc -o tricorn tricorn.c -lm

./mandelbrot
./julia
./tricorn

This generates mandelbrot.ppm, julia.ppm, and tricorn.ppm.
Viewing Images

Use any image viewer supporting PPM, or convert to PNG:

bash
convert mandelbrot.ppm mandelbrot.png

Notes & Ideas

    Adjust MAX_ITER for more detail or speed.

    Change complex plane boundaries to zoom.

    Modify color schemes for variation.

License

MIT License — free to use and modify.

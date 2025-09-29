# Mandelbrot Fractal Generator in C

Generates the Mandelbrot fractal and outputs it as a `.ppm` image file.

## Usage
1. Compile:
   gcc mandelbrot.c -o mandelbrot -lm
2. Run:
   ./mandelbrot
3. Open `mandelbrot.ppm` in an image viewer.

## Parameters
- Change `WIDTH` / `HEIGHT` for image size.
- Change `MAX_ITER` for detail level.
- Adjust `x_min`, `x_max`, `y_min`, `y_max` for zoom.

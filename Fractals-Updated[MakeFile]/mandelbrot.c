#include <stdio.h>
#include <complex.h>
#include "mandelbrot.h"

#define WIDTH 420
#define HEIGHT 236
#define MAXITER 3000

int mandelbrot(double complex c) {
    double complex z = 0;
    int n = 0;
    while (cabs(z) <= 2.0 && n < MAXITER) {
        z = z * z + c;
        n++;
    }
    return n == MAXITER;
}

void mandelbrot_generate(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) return;

    double xmin = -2.5, xmax = 1.0;
    double ymin = -1.0, ymax = 1.0;
    for (int py = 0; py < HEIGHT; py++) {
        for (int px = 0; px < WIDTH; px++) {
            double x = xmin + (xmax - xmin) * px / (WIDTH - 1);
            double y = ymin + (ymax - ymin) * py / (HEIGHT - 1);
            double complex c = x + y * I;
            int inside = mandelbrot(c);
            fprintf(fp, inside ? "00" : "  ");
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

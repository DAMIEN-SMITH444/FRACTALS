#include <stdio.h>
#include <complex.h>
#include "tricorn.h"

#define WIDTH 420
#define HEIGHT 236
#define MAXITER 3000

int tricorn(double complex c) {
    double complex z = 0;
    int n = 0;
    while (cabs(z) <= 2.0 && n < MAXITER) {
        z = conj(z) * conj(z) + c;
        n++;
    }
    return n == MAXITER;
}

void tricorn_generate(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) return;

    double xmin = -2.0, xmax = 2.0;
    double ymin = -2.0, ymax = 2.0;
    for (int py = 0; py < HEIGHT; py++) {
        for (int px = 0; px < WIDTH; px++) {
            double x = xmin + (xmax - xmin) * px / (WIDTH - 1);
            double y = ymin + (ymax - ymin) * py / (HEIGHT - 1);
            double complex c = x + y * I;
            int inside = tricorn(c);
            fprintf(fp, inside ? "00" : "  ");
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

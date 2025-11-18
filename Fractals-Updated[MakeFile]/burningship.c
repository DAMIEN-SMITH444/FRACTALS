#include <stdio.h>
#include <complex.h>
#include <math.h>
#include "burningship.h"

#define WIDTH 420
#define HEIGHT 236
#define MAXITER 5000

int burningship(double complex c) {
    double complex z = 0;
    int n = 0;
    while (cabs(z) <= 2.0 && n < MAXITER) {
        double a = creal(z), b = cimag(z);
        a = fabs(a);
        b = fabs(b);
        z = a + b * I;
        z = z * z + c;
        n++;
    }
    return n == MAXITER;
}

void burningship_generate(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) return;

    double xmin = -2.2, xmax = 1.2;
    double ymin = -2.0, ymax = 1.0;
    for (int py = 0; py < HEIGHT; py++) {
        for (int px = 0; px < WIDTH; px++) {
            double x = xmin + (xmax - xmin) * px / (WIDTH - 1);
            double y = ymin + (ymax - ymin) * py / (HEIGHT - 1);
            double complex c = x + y * I;
            int inside = burningship(c);
            fprintf(fp, inside ? "00" : "  ");
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

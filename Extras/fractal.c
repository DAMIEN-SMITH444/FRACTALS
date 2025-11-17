#include <stdio.h>
#include <complex.h>

#define WIDTH 420
#define HEIGHT 236
#define MAX_ITER 3000

int mandelbrot(double complex c) {
    double complex z = 0;
    int n = 0;

    while (cabs(z) <= 2.0 && n < MAX_ITER) {
        z = z*z + c;
        n++;
    }

    return (n == MAX_ITER);
}

int main() {
    FILE *fp = fopen("mandelbrot_16x9.txt", "w");
    if (!fp) return 1;

    // Standard view of Mandelbrot
    double x_min = -2.5, x_max = 1.0;
    double y_min = -1.0, y_max = 1.0;

    for (int py = 0; py < HEIGHT; py++) {
        for (int px = 0; px < WIDTH; px++) {

            double x = x_min + (x_max - x_min) * px / (WIDTH - 1);
            double y = y_min + (y_max - y_min) * py / (HEIGHT - 1);

            double complex c = x + y * I;
            int inside = mandelbrot(c);

            fprintf(fp, inside ? "00" : "11");
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return 0;
}

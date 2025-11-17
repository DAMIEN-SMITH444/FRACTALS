#include <stdio.h>
#include <complex.h>
#include <math.h>

#define WIDTH 420
#define HEIGHT 236
#define MAX_ITER 5000

int burningship(double complex c) {
    double complex z = 0;
    int n = 0;

    while (cabs(z) <= 2.0 && n < MAX_ITER) {
        double a = creal(z);
        double b = cimag(z);

        // absolute values
        a = fabs(a);
        b = fabs(b);

        z = (a + b * I) * (a + b * I) + c;
        n++;
    }

    return (n == MAX_ITER);
}

int main() {
    FILE *fp = fopen("burningship.txt", "w");
    if (!fp) return 1;

    // Good viewing window
    double x_min = -2.2, x_max = 1.2;
    double y_min = -2.0, y_max = 1.0;

    for (int py = 0; py < HEIGHT; py++) {
        for (int px = 0; px < WIDTH; px++) {
            double x = x_min + (x_max - x_min) * px / (WIDTH - 1);
            double y = y_min + (y_max - y_min) * py / (HEIGHT - 1);

            double complex c = x + y * I;

            int inside = burningship(c);
            fprintf(fp, inside ? "00" : "11");
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return 0;
}

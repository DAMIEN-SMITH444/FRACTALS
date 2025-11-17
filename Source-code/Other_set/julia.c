#include <stdio.h>
#include <complex.h>
#include <math.h>

#define WIDTH 420
#define HEIGHT 236
#define MAX_ITER 3000

// Multibrot function: z^(power) + c
int multibrot(double complex c, int power) {
    double complex z = 0;
    int n = 0;

    while (cabs(z) <= 2.0 && n < MAX_ITER) {
        // raise z to given power
        double complex zp = cpow(z, power);
        z = zp + c;
        n++;
    }

    return (n == MAX_ITER); // inside set
}

int main() {
    FILE *fp = fopen("multibrot.txt", "w");
    if (!fp) return 1;

    // choose the multibrot exponent here
    int power = 4;   // change to 4 for z^4 + c

    double x_min = -2.0, x_max = 2.0;
    double y_min = -1.5, y_max = 1.5;

    for (int py = 0; py < HEIGHT; py++) {
        for (int px = 0; px < WIDTH; px++) {
            double x = x_min + (x_max - x_min) * px / (WIDTH - 1);
            double y = y_min + (y_max - y_min) * py / (HEIGHT - 1);

            double complex c = x + y * I;

            int inside = multibrot(c, power);
            fprintf(fp, inside ? "00" : "11");
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return 0;
}

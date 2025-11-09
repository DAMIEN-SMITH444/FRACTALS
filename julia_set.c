#include <stdio.h>
#include <complex.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 500

// Compute escape time for Julia set: z_{n+1} = z_n^2 + c
int julia(double complex z, double complex c) {
    int n = 0;
    while (cabs(z) <= 2.0 && n < MAX_ITER) {
        z = z*z + c;
        n++;
    }
    return n;
}

int main() {
    FILE *fp = fopen("julia.ppm", "w");
    if (!fp) { printf("Error: cannot open file.\n"); return 1; }
    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    double x_min = -2.0, x_max = 2.0;
    double y_min = -2.0, y_max = 2.0;
    // You can change c to explore different Julia sets!
    double complex c = -0.7 + 0.27015*I; // Classic "frond" pattern

    for (int py = 0; py < HEIGHT; py++) {
        for (int px = 0; px < WIDTH; px++) {
            double x = x_min + (x_max - x_min) * px / (WIDTH - 1);
            double y = y_min + (y_max - y_min) * py / (HEIGHT - 1);
            double complex z = x + y*I;

            int iter = julia(z, c);

            int r = (iter % 256);
            int g = (iter * 5 % 256);
            int b = (iter * 13 % 256);
            if (iter == MAX_ITER) { r = g = b = 0; }

            fprintf(fp, "%d %d %d ", r, g, b);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("Julia image written to julia.ppm\n");
    return 0;
}

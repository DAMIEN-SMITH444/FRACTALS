#include <stdio.h>
#include <complex.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 500

int mandelbrot(double complex c) {
    double complex z = 0;
    int n = 0;
    while (cabs(z) <= 2.0 && n < MAX_ITER) {
        z = z*z + c;
        n++;
    }
    return n;
}

int main() {
    FILE *fp = fopen("mandelbrot.ppm", "w");
    if (!fp) {
        printf("Error: cannot open file.\n");
        return 1;
    }

    // PPM header
    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    // Bounds of complex plane
    double x_min = -2.0, x_max = 1.0;
    double y_min = -1.5, y_max = 1.5;

    for (int py = 0; py < HEIGHT; py++) {
        for (int px = 0; px < WIDTH; px++) {
            double x = x_min + (x_max - x_min) * px / (WIDTH - 1);
            double y = y_min + (y_max - y_min) * py / (HEIGHT - 1);
            double complex c = x + y*I;

            int iter = mandelbrot(c);

            // Color mapping
            int r = (iter % 256);
            int g = (iter * 5 % 256);
            int b = (iter * 13 % 256);

            if (iter == MAX_ITER) { r = g = b = 0; } // inside set → black

            fprintf(fp, "%d %d %d ", r, g, b);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    printf("Mandelbrot image written to mandelbrot.ppm\n");
    return 0;
}

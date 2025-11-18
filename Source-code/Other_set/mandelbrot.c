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

void render(double x_min, double x_max, double y_min, double y_max, int zoom_level) {
    char filename[50];
    sprintf(filename, "mandelbrot_zoom_%d.txt", zoom_level);

    FILE *fp = fopen(filename, "w");
    if (!fp) return;

    for (int py = 0; py < HEIGHT; py++) {
        for (int px = 0; px < WIDTH; px++) {

            double x = x_min + (x_max - x_min) * px / (WIDTH - 1);
            double y = y_min + (y_max - y_min) * py / (HEIGHT - 1);

            double complex c = x + y * I;

            int inside = mandelbrot(c);
            fprintf(fp, inside ? "0" : "1");
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    printf("Saved: %s\n", filename);
}

int main() {
    double x_min = -2.5, x_max = 1.0;
    double y_min = -1.0, y_max = 1.0;

    int zoom_level = 1;
    char choice;

    while (1) {
        render(x_min, x_max, y_min, y_max, zoom_level);

        printf("Zoom again? (y/n): ");
        fflush(stdout);       // force prompt to show
        scanf(" %c", &choice); // space before %c fixes buffer issue

        if (choice != 'y' && choice != 'Y')
            break;

        // CENTER POINT
        double cx = (x_min + x_max) / 2.0;
        double cy = (y_min + y_max) / 2.0;

        // shrink view window
        double xrange = (x_max - x_min) / 2.0;
        double yrange = (y_max - y_min) / 2.0;

        x_min = cx - xrange / 2.0;
        x_max = cx + xrange / 2.0;
        y_min = cy - yrange / 2.0;
        y_max = cy + yrange / 2.0;

        zoom_level++;
    }

    return 0;
}

#include <stdio.h>
#include <complex.h>

#define WIDTH 420       // Output width (number of pixels/characters per row)
#define HEIGHT 236      // Output height (number of rows)
#define MAX_ITER 3000   // Maximum iterations before assuming point escapes

// Function to check if a complex number 'c' belongs to the Mandelbrot set
int mandelbrot(double complex c) {
    double complex z = 0;   // Initial z value
    int n = 0;              // Iteration counter

    // Iterate until |z| exceeds 2 (escape radius) or we hit MAX_ITER
    while (cabs(z) <= 2.0 && n < MAX_ITER) {
        z = z*z + c;        // Core Mandelbrot iteration
        n++;
    }

    // Return 1 if point is inside (never escaped), otherwise 0
    return (n == MAX_ITER);
}

int main() {
    // Open output file for writing
    FILE *fp = fopen("mandelbrot_16x9.txt", "w");
    if (!fp) return 1;  // If file fails to open, exit early

    // Define the viewing window of the Mandelbrot set
    double x_min = -2.5, x_max = 1.0;   // Horizontal range
    double y_min = -1.0, y_max = 1.0;   // Vertical range

    // Loop through each pixel (row by row)
    for (int py = 0; py < HEIGHT; py++) {
        for (int px = 0; px < WIDTH; px++) {

            // Map pixel coordinates to complex plane (linear interpolation)
            double x = x_min + (x_max - x_min) * px / (WIDTH - 1);
            double y = y_min + (y_max - y_min) * py / (HEIGHT - 1);

            // Create complex number c = x + yi
            double complex c = x + y * I;

            // Determine if point belongs to Mandelbrot set
            int inside = mandelbrot(c);

            // Write "00" for inside, "11" for outside
            fprintf(fp, inside ? "00" : "11");
        }
        fprintf(fp, "\n"); // New line after each row
    }

    fclose(fp); // Close file
    return 0;   // Successful exit
}

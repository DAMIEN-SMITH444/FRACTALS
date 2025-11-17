#include <stdio.h>      // For file operations (fopen, fprintf, printf, fclose)
#include <complex.h>    // For complex number support in C (double complex, I, cabs)

#define WIDTH 800       // Width of the output image in pixels
#define HEIGHT 800      // Height of the output image in pixels
#define MAX_ITER 500    // Maximum number of iterations for Mandelbrot calculation

// Function to compute the number of iterations before escaping
// Takes a complex number 'c' as input
int mandelbrot(double complex c) {
    double complex z = 0;   // Start with z = 0 (the initial point)
    int n = 0;              // Iteration counter

    // Keep iterating until |z| > 2 (escape condition) or we hit MAX_ITER
    while (cabs(z) <= 2.0 && n < MAX_ITER) {
        z = z*z + c;        // Mandelbrot formula: z = z^2 + c
        n++;
    }
    return n;   // Return the number of iterations taken before escaping
}

int main() {
    // Open a file in write mode to store the output image in PPM format
    FILE *fp = fopen("mandelbrot.ppm", "w");
    if (!fp) {
        printf("Error: cannot open file.\n");
        return 1;   // Exit if file cannot be created
    }

    // Write the PPM header
    // P3 means plain text format
    // WIDTH HEIGHT define image size
    // 255 is the maximum color value
    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    // Define the range of the complex plane to map onto the image
    double x_min = -2.0, x_max = 1.0;   // Real axis range
    double y_min = -1.5, y_max = 1.5;   // Imaginary axis range

    // Loop over each pixel in the image
    for (int py = 0; py < HEIGHT; py++) {
        for (int px = 0; px < WIDTH; px++) {
            
            // Map pixel coordinates (px, py) to complex plane (x, y)
            double x = x_min + (x_max - x_min) * px / (WIDTH - 1);
            double y = y_min + (y_max - y_min) * py / (HEIGHT - 1);
            double complex c = x + y*I; // Construct complex number c = x + iy

            // Compute how many iterations it takes for c to escape
            int iter = mandelbrot(c);

            // Color mapping based on number of iterations
            int r = (iter % 256);           // Red channel varies with iterations
            int g = (iter * 5 % 256);       // Green channel uses a multiplier
            int b = (iter * 13 % 256);      // Blue channel uses another multiplier

            // Points inside the Mandelbrot set (did not escape) → Black
            if (iter == MAX_ITER) { 
                r = g = b = 0; 
            }

            // Write pixel color to file
            fprintf(fp, "%d %d %d ", r, g, b);
        }
        fprintf(fp, "\n");  // Newline at the end of each row
    }

    // Close the file
    fclose(fp);
    printf("Mandelbrot image written to mandelbrot.ppm\n");
    return 0;
}

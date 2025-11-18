#include <stdio.h>
#include "mandelbrot.h"
#include "burningship.h"
#include "tricorn.h"

int main() {
    int choice;
    printf("Choose a fractal to generate:\n");
    printf("1. Mandelbrot\n2. Burning Ship\n3. Tricorn\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            mandelbrot_generate("mandelbrot.txt");
            break;
        case 2:
            burningship_generate("burningship.txt");
            break;
        case 3:
            tricorn_generate("tricorn.txt");
            break;
        default:
            printf("Invalid choice.\n");
    }
    printf("Done!\n");
    return 0;
}

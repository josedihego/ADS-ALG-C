#include <stdio.h>
#include <complex.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_ITERATIONS 1000

void drawMandelbrot() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double realPart = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            double imagPart = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;

            double complex z = realPart + imagPart * I;
            double complex c = z;

            int iterations;
            for (iterations = 0; iterations < MAX_ITERATIONS; iterations++) {
                if (cabs(z) > 2.0) {
                    break;
                }
                z = z * z + c;
            }

            // Map the number of iterations to a grayscale value
            int color = (iterations % 8) * 16;

            if (iterations == MAX_ITERATIONS) {
                putchar(' ');  // Inside the Mandelbrot Set
            } else {
                putchar('0' + color);
            }
        }
        putchar('\n');
    }
}

int main() {
    printf("Generating the Mandelbrot Set:\n\n");
    drawMandelbrot();

    return 0;
}

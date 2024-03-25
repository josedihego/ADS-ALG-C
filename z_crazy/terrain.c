#include <stdio.h>
#include <math.h>
#include <noise/noise.h>

#define WIDTH 80
#define HEIGHT 40

// Function to generate Perlin noise for 3D terrain
double perlin(double x, double y) {
    const double frequency = 0.1;
    const double amplitude = 10.0;

    return amplitude * noise2(x * frequency, y * frequency);
}

// Function to draw the 3D terrain
void drawTerrain() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Map ASCII characters based on the terrain height
            double terrainHeight = perlin((double)x, (double)y);

            if (terrainHeight > 0.5) {
                putchar('#');  // Hill
            } else if (terrainHeight < -0.5) {
                putchar('.');  // Valley
            } else {
                putchar(' ');  // Flat ground
            }
        }
        putchar('\n');
    }
}

int main() {
    printf("Generating 3D terrain:\n\n");
    drawTerrain();

    return 0;
}

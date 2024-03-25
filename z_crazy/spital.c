#include <stdio.h>
#include <math.h>

void drawSpiral(int numTurns) {
    const double pi = 3.14159265358979323846;
    const int width = 40;
    const int height = 20;

    char canvas[height][width];

    // Initialize canvas with spaces
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            canvas[i][j] = ' ';
        }
    }

    double angle, radius;
    int x, y;

    for (int step = 0; step < numTurns * 360; step++) {
        angle = step * (pi / 180.0);
        radius = 0.1 * angle;

        x = width / 2 + radius * cos(angle);
        y = height / 2 + 0.5 * radius * sin(angle);

        if (x >= 0 && x < width && y >= 0 && y < height) {
            canvas[y][x] = '*';
        }
    }

    // Print the canvas
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            putchar(canvas[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    printf("Generating a spiral pattern:\n\n");
    drawSpiral(5); // You can adjust the number of turns to change the complexity of the pattern

    return 0;
}

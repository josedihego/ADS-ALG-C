#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayElapsedTime(clock_t elapsed) {
    int hours = elapsed / CLOCKS_PER_SEC / 3600;
    int minutes = (elapsed / CLOCKS_PER_SEC % 3600) / 60;
    int seconds = elapsed / CLOCKS_PER_SEC % 60;
    int milliseconds = (elapsed % CLOCKS_PER_SEC) * 1000 / CLOCKS_PER_SEC;

    printf("%02d:%02d:%02d.%03d\n", hours, minutes, seconds, milliseconds);
}

int main() {
    printf("Stopwatch - Press Enter to record lap time, 'q' to quit\n\n");

    clock_t start_time, lap_time;
    start_time = lap_time = clock();

    char input;
    int lap_count = 1;

    while (1) {
        displayElapsedTime(clock() - start_time);

        input = getchar();

        if (input == '\n') {
            printf("Lap %d: ", lap_count++);
            displayElapsedTime(clock() - lap_time);
            lap_time = clock();
        } else if (input == 'q' || input == 'Q') {
            break;
        }
    }

    printf("Total Elapsed Time: ");
    displayElapsedTime(clock() - start_time);

    return 0;
}

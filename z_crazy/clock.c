#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 25
#define HEIGHT 5

// Function to display a digit using ASCII art
void displayDigit(int digit) {
    const char* digits[10][5] = {
        {"  ***  ", " *   * ", "*     *", "*     *", " *   * ", "  ***  "}, // 0
        {"   *   ", "  **   ", "   *   ", "   *   ", "   *   ", " ***** "}, // 1
        {" ***** ", "      *", "  **** ", " *     ", "*      ", " ***** "}, // 2
        {" ***** ", "      *", "  **** ", "      *", "      *", " ***** "}, // 3
        {"*      ", "*    * ", "*    * ", "*******", "      *", "      *"}, // 4
        {" ***** ", "*      ", " ***** ", "      *", "      *", " ***** "}, // 5
        {" ***** ", "*      ", " ***** ", "*     *", "*     *", " ***** "}, // 6
        {" ***** ", "      *", "      *", "      *", "      *", "      *"}, // 7
        {" ***** ", "*     *", " ***** ", "*     *", "*     *", " ***** "}, // 8
        {" ***** ", "*     *", " ***** ", "      *", "      *", " ***** "}  // 9
    };

    for (int i = 0; i < 5; i++) {
        printf("%s ", digits[digit][i]);
        putchar('\n');
    }
}

// Function to display the current time as a digital clock
void displayDigitalClock() {
    while (1) {
        time_t t;
        struct tm *tm_info;

        time(&t);
        tm_info = localtime(&t);

        int hour = tm_info->tm_hour;
        int minute = tm_info->tm_min;
        int second = tm_info->tm_sec;

        // Display the time
        printf("Current Time: %02d:%02d:%02d\n\n", hour, minute, second);

        // Display the digits of the current hour, minute, and second
        for (int i = 0; i < 5; i++) {
            displayDigit(hour / 10);
            displayDigit(hour % 10);
            printf("   ");
            displayDigit(minute / 10);
            displayDigit(minute % 10);
            printf("   ");
            displayDigit(second / 10);
            displayDigit(second % 10);
            printf("\n");
        }

        // Clear the console (for a smoother update)
        sleep(1);
        printf("\033[H\033[J");
    }
}

int main() {
    displayDigitalClock();
    return 0;
}

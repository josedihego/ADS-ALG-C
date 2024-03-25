#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main() {
    char str[] = "maria 3 5 jose 3.15 -1 (7,9.7) 4";
    char* token = strtok(str, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || token[0] == '-') {  // integer or float
            if (strchr(token, '.') != NULL) {  // float
                float f = atof(token);
                printf("Float: %.2f\n", f);
            } else {  // integer
                int i = atoi(token);
                printf("Integer: %d\n", i);
            }
        } else if (strchr(token, '(') != NULL) {  // 2D point
            float x, y;
            sscanf(token, "(%f,%f)", &x, &y);
            printf("2D Point: (%.1f,%.1f)\n", x, y);
        } else {  // string
            printf("String: %s\n", token);
        }
        token = strtok(NULL, " ");
    }
    return 0;
}

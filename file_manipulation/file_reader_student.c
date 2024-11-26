#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp_in = fopen("student.in", "r");
    FILE *fp_out = fopen("student.out", "w");

    if (fp_in == NULL || fp_out == NULL)
    {
        printf("Files cannot be oppened");
        return EXIT_FAILURE;
    }

    char line[255];
    const char space[] = " ";
    const char student_separators[] = "(,)";
    char *outer_context;
    char *inner_context;

    while (fgets(line, sizeof(line), fp_in) != NULL)
    {
        double sum = 0.0;
        int qnt = 0;

        char *slice = strtok_r(line, space, &outer_context);
        while (slice != NULL)
        {
            char *name = strtok_r(slice, student_separators, &inner_context);
            char *score = strtok_r(NULL, student_separators, &inner_context);
            sum = sum + atof(score); // Convert score to double
            qnt = qnt + 1;
            slice = strtok_r(NULL, space, &outer_context);
        }

        float average = sum / qnt;
        fprintf(fp_out, "Class average: %.2f\n", average);
    }

    fclose(fp_in);
    fclose(fp_out);
    return EXIT_SUCCESS;
}

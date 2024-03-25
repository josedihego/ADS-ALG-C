#include <stdio.h>
#include <stdlib.h>

//OK
void passingAddressOfConstants(const int *num1, int *num2)
{
    *num2 = *num1;
}
//ERROR
void passingAddressOfConstants2(const int *num1, int *num2)
{
    *num1 = 100; // ERROR
    *num2 = 200;
}

int main()
{
    //OK
    const int limit = 100;
    int result = 5;
    passingAddressOfConstants(&limit, &result);

    // ERROR
    const int limit = 100;
    passingAddressOfConstants2(&limit, &limit); // ERROR

    return 0;
}
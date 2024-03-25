#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main() {
    setlocale(LC_ALL, "pt_BR.ISO-8859-1");

    wchar_t c1 = L'é';
    wchar_t c2 = L'e';

    if (c1 < c2) {
        wprintf(L"%lc é menor que %lc\n", c1, c2);
    } else {
        wprintf(L"%lc é menor que %lc\n", c2, c1);
    }

    return 0;
}
    
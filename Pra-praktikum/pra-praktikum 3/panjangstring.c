// NIM             : 18221076
// Nama            : Gevyndo Gunawan
// Tanggal         : 18 September 2022
// Topik praktikum : Pra-praktikum 3
// Deskripsi       : Implementasi fungsi panjangString 

#include "panjangstring.h"
#include <stdio.h>

int panjangString(char *x)
{
    int count = 0;
    while (*x != '\0')
    {
        count += 1;
        x += 1;
    }
    return count;
}
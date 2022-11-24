// NIM             : 18221076
// Nama            : Gevyndo Gunawan
// Tanggal         : 21 Oktober 2022
// Topik praktikum : Pra-praktikum 7
// Deskripsi       : Implementasi aritmatika.h

#include <stdio.h>
#include "aritmatika.h"

boolean isOperator(char input)
{
    return (input == '+') || (input == '-') || (input == '*') || (input == '/');
}

int hitung(int angka1, int angka2, char op)
{
    int result;
    if (op=='+') result=angka1+angka2;
    else if (op=='-') result=angka1-angka2;
    else if (op=='*') result=angka1*angka2;
    else if (op=='/') result=angka1/angka2;
    return result;
}

int eval(char *input, int length)
{
    Stack S;
    CreateEmpty(&S);
    int i, num1, num2, result;

    for (i = 0; i < length; i++)
    {
        if (!isOperator(input[i]))
            Push(&S, input[i] - '0');
        else
        {
            Pop(&S, &num2);
            Pop(&S, &num1);
            result = hitung(num1, num2, input[i]);
            Push(&S, result);
        }
    }
    Pop(&S, &result);
    return result;
}
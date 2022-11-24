// NIM             : 18221076
// Nama            : Gevyndo Gunawan
// Tanggal         : 21 Oktober 2022
// Topik praktikum : Pra-praktikum 7
// Deskripsi       : Cek palindrom pada stack

#include "stack.h"
#include <stdio.h>

Stack ReverseStack(Stack s)
{
    int temp;
    Stack S;
    CreateEmpty(&S);
    while (!IsEmpty(s))
    {
        Pop(&s, &temp);
        Push(&S, temp);
    }
    return S;
}

int main()
{
    int x;
    Stack s1;
    CreateEmpty(&s1);
    scanf("%d", &x);
    while (x != 0)
    {
        Push(&s1, x);
        scanf("%d", &x);
    }
    if (!IsEmpty(s1))
    {
        int a, b;
        boolean isPalindrom = true;
        Stack s2 = ReverseStack(s1);
        while (!IsEmpty(s1) && isPalindrom)
        {
            Pop(&s1, &a);
            Pop(&s2, &b);
            if (a != b){
                isPalindrom = false;
            }
        }
        if (isPalindrom){
            printf("Palindrom\n");
        }
        else{
            printf("Bukan Palindrom\n");
        }
    }
    else{
        printf("Stack kosong\n");
    }
    return 0;
}
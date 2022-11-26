// Nama             : Gevyndo Gunawan
// NIM              : 18221076
// Topik Praktikum  : Set & Map Hash
// Deskripsi        : implememtasi hashmap.c

#include <stdio.h>
#include "hashmap.h"

void CreateEmpty(HashMap *M)
{
    M->Count = Nil;
    for (int i = 0; i < MaxEl; i++)
    {
        M->Elements[i].Key = Undefined;
        M->Elements[i].Value = Undefined;
    }
}

address Hash(keytype K)
{
    address index;
    index = K % MaxEl;
    return index;
}

valuetype Value(HashMap M, keytype k)
{
    int i = 0;
    while (i < MaxEl)
    {
        if (M.Elements[i].Key == k)
        {
            return M.Elements[i].Value;
        }
        i++;
    }
    return Undefined;
}

void Insert(HashMap *M, keytype k, valuetype v)
{
    boolean isMember = false;
    if (M->Count < MaxEl)
    {
        int i = 0;
        while (i < M->Count)
        {
            if (M->Elements[i].Key == k)
            {
                isMember = true;
            }
            i++;
        }

        if (isMember == false && M->Count < MaxEl)
        {
            if (M->Elements[Hash(k)].Key == Undefined)
            {
                M->Elements[Hash(k)].Key = k;
                M->Elements[Hash(k)].Value = v;
            }
            else
            {
                int j = 0;
                while (M->Elements[(Hash(k) + j) % MaxEl].Key != Undefined)
                {
                    j++;
                }
                M->Elements[(Hash(k) + j) % MaxEl].Key = k;
                M->Elements[(Hash(k) + j) % MaxEl].Value = v;
            }
            M->Count++;
        }
    }
}
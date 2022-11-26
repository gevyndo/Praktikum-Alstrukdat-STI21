// Nama             : Gevyndo Gunawan
// NIM              : 18221076
// Topik Praktikum  : Set & Map Hash
// Deskripsi        : implememtasi map.h

#include <stdio.h>
#include "map.h"

void CreateEmpty(Map *M)
{
    M->Count = Nil;
}

boolean IsEmpty(Map M)
{
    return M.Count == Nil;
}

boolean IsFull(Map M)
{
    return M.Count == MaxEl;
}

valuetype Value(Map M, keytype k)
{
    int i = 0;
    while (i < M.Count)
    {
        if (M.Elements[i].Key == k)
        {
            return M.Elements[i].Value;
        }
        i++;
    }
    return Undefined;
}

void Insert(Map *M, keytype k, valuetype v)
{
    if (!IsFull(*M))
    {
        if (!IsMember(*M, k))
        {
            M->Count++;
            M->Elements[M->Count - 1].Key = k;
            M->Elements[M->Count - 1].Value = v;
        }
    }
}

void Delete(Map *M, keytype k)
{
    if (M->Count == 1)
    {
        M->Count = Nil;
    }
    else
    {
        if (IsMember(*M, k))
        {
            int i = 0;
            while (i < M->Count && M->Elements[i].Key != k)
            {
                i++;
            }
            while (i < M->Count)
            {
                M->Elements[i].Key = M->Elements[i + 1].Key;
                M->Elements[i].Value = M->Elements[i + 1].Value;
                i++;
            }
            M->Count--;
        }
    }
}

boolean IsMember(Map M, keytype k)
{
    int i = 0;
    while (i < M.Count)
    {
        if (M.Elements[i].Key == k)
        {
            return true;
        }
        i++;
    }
    return false;
}
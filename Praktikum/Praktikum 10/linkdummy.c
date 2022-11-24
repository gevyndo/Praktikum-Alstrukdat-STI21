/*
Nama : Gevyndo Gunawan
NIM: 18221076   
Tanggal: 12 November 2022
Topik : Praktikum 10
Deskripsi: Implementasi linkdummy.h
*/

#include "linkdummy.h"
#include <stdio.h>
#include <stdlib.h>

/* Definisi list: */
/* List kosong: First(L) = Last(L) = dummy@ */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen dummy terletak pada last */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty(List L){
	return(First(L) ==Last(L));
}
/* Mengirim true jika list kosong: First(L) = dummy@
dan Last(L) = dummy@ */

/****************** PEMBUATAN LIST KOSONG ******************/
void MakeEmpty(List *L)
{
    address p;
    p = Alokasi(0);
    if(p != Nil)
    {
        First(*L) = p;
        Last(*L) = p;
    }
    else
    {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong, dengan satu elemen dummy */
/* Jika gagal maka First = Last = Nil dan list gagal terbentuk */

/****************** MANAJEMEN MEMORI ******************/
address Alokasi (ElType X)
{
	address p = (address) malloc(sizeof(Node));
	if(p != Nil)
	{
		Info(p) = X;
		Next(p) = Nil;
	}
	return p;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P)
{
    free(P);
}

address Search(List L, ElType X)
{
    address P = First(L);
    boolean found = false;

    while(!found && P != Last(L))
    {
        if(Info(P) == X)
        {
            found = true;
        }
        else
        {
            P = Next(P);
        }
    }
    if(found == true)
    {
        return P;
    }
    else
    {
        return Nil;
    }
};
/* Mencari apakah ada node list dengan info(P) = X */
/* Jika ada, mengirimkan address node tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsertFirst(List *L, ElType X)
{
    address P = Alokasi(X);
    if(P != Nil)
    {
        Next(P) = First(*L);
        First(*L) = P;
    }
}
/* I.S. List L terdefinisi */
/* F.S. Menambahkan elemen X sebagai elemen pertama List L */
void InsertLast(List *L, ElType X)
{
    if(IsEmpty(*L))
    {
        InsertFirst(L, X);
    }
    else
    {
        address P = Alokasi(X);
        if(P != Nil)
        {
            address last = First(*L);
            while(Next(last) != Last(*L))
            {
                last = Next(last);
            }
            Next(last) = P;
            Next(P) = Last(*L);
        }
    }
}
/* I.S. List L terdefinisi */
/* F.S. X ditambahkan sebagai elemen terakhir yang baru, */
/* yaitu menjadi elemen sebelum elemen dummy */
/* Alamat elemen dummy tidak berubah */

/*** PENGHAPUSAN ELEMEN ***/
void DeleteFirst(List *L, ElType *X)
{
    (*X) = Info(First(*L));
    address P = First(*L);
    First(*L) = Next(P);
    Dealokasi(P);
}
/* I.S. List tidak kosong */
/* F.S. X adalah elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DeleteLast(List *L, ElType *X)
{
    address last, prevLast;
    last = First(*L);
    prevLast = Nil;
    while(Next(last) != Last(*L))
    {
        prevLast = last;
        last = Next(last);
    }
    if(prevLast == Nil)
    {
        First(*L) = Last(*L);
    }
    else
    {
        Next(prevLast) = Last(*L);
    }
    (*X) = Info(last);
    Dealokasi(last);
}
/*
Nama : Gevyndo Gunawan
NIM: 18221076   
Tanggal: 12 November 2022
Topik: Pra-praktikum 10
Deskripsi: Implementasi listdp.h
*/
#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (((L).First) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    ((*L).First) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P;

    P = (address) malloc(1 * sizeof(ElmtList));

    if (P != Nil) {
        (P)->info = X;
        (P)->next = Nil;
    }

    return P;
}

void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address P = ((L).First);
    boolean Found;

    if (P == Nil) {
        Found = false;
    } else {
        while (((P)->next != ((L).First)) && ((P)->info != X)) {
            P = (P)->next;
        }
        Found = ((P)->info == X);
    }
    
    if (!Found) {
        return Nil;
    } else {
        return P;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P = Alokasi(X);

    if (P != Nil) {
        InsertFirst(L,P);
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P = Alokasi(X);

    if (P != Nil) {
        InsertLast(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P;
    DelFirst(L, &P);
    *X = (P)->info;
    Dealokasi(P);
}

void DelVLast (List *L, infotype * X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P;
    DelLast(L, &P);
    *X = (P)->info;
    Dealokasi(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    if (IsEmpty(*L)) {
        (P)->next = P;
    } else {
        address Last = ((*L).First);
        while ((Last)->next != ((*L).First)) {
            Last = (Last)->next;
        }
        (P)->next = ((*L).First);
        (Last)->next = P;
    }
    ((*L).First) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if (IsEmpty(*L)) {
        InsertFirst(L, P);
    } else {
        address Last = ((*L).First);
        while ((Last)->next != ((*L).First)) {
            Last = (Last)->next;
        }
        InsertAfter(L, P, Last);
    }
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    (P)->next = (Prec)->next;
    (Prec)->next = P;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = ((*L).First);
    
    if ((((*L).First))->next == ((*L).First)) {
        ((*L).First) = Nil;
    } else {
        address Last = ((*L).First);
        while ((Last)->next != ((*L).First)) {
            Last = (Last)->next;
        }
        ((*L).First) = (((*L).First))->next;
        (Last)->next = ((*L).First);
    }
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    address Last = ((*L).First);
    address Prec = Nil;

    while ((Last)->next != ((*L).First)) {
        Prec = Last;
        Last = (Last)->next;
    }

    *P = Last;
    if (Prec == Nil) {
        ((*L).First) = Nil;
    } else {
        (Prec)->next = ((*L).First);
    }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = (Prec)->next;
    (Prec)->next = ((Prec)->next)->next;
    (*Pdel)->next = Nil;
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    if (!IsEmpty(*L)) {
        address P = Search(*L, X);
        if (P != Nil) {

            if (P == ((*L).First)) {
                DelFirst(L, &P);

            } else {
                address Prec = ((*L).First);
                while ((Prec)->next != P) {
                    Prec = (Prec)->next;
                }
                DelAfter(L, &P, Prec);
            }

            Dealokasi(P);
        }
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    if (IsEmpty(L)) {
        printf("[]");
    } else {
        address P = ((L).First);

        printf("[");
        
        do {
            printf("%d", (P)->info);
            P = (P)->next;

            if (P != ((L).First)) {
                printf(",");
            }

        } while (P != ((L).First));

        printf("]");
    }
}
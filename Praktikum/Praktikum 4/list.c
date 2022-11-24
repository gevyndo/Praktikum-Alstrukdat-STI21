// NIM : 18221076
// Nama : Gevyndo Gunawan
// Tanggal : 23 September 2022
// Topik Praktikum : Pra-Praktikum 4
// Deskripsi : Implementasi list.h

#include <stdio.h>
#include "list.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
List MakeList(){
    List L;
    int i = 0;
    for (i; i < MaxEl; i++){
        L.A[i] = Mark;
    }
    return L;
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(List L){
    return (L.A[0] == Mark);
}
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
ElType Get(List L, IdxType i){
    return L.A[i];
}
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set(List *L, IdxType i, ElType v){
    L->A[i] = v;
    //(*L.Neff[i]=v;)
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(List L){
    int i = 0;
    while (L.A[i] != Mark && i<MaxEl){
        i++;
    }
    return i;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
IdxType FirstIdx(List L){
    return 0;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType LastIdx(List L){
    return Length(L)-1;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (List L, IdxType i){
    return (i >= 0 && i < MaxEl);
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean IsIdxEff (List L, IdxType i){
    return (i >= 0 && i < Length(L));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
boolean Search(List L, ElType X){
    int i = 0;
    while (L.A[i] != Mark){
        if (L.A[i] == X){
            return true;
        }
        i++;
    }
    return false;
}
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void InsertFirst(List *L, ElType X){
    if (Length(*L) == MaxEl){
        printf("List penuh\n");
    }
    else{
        int i = Length(*L);
        for (i; i > 0; i--){
            L->A[i] = L->A[i-1];
        }
        L->A[0] = X;
    }
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void InsertAt(List *L, ElType X, IdxType i){
    if (Length(*L) == MaxEl){
        printf("List penuh\n");
    }
    else if (i < 0 || i > Length(*L)){
        printf("Indeks tidak valid\n");
    }
    else{
        int j = Length(*L);
        for (j; j > i; j--){
            L->A[j] = L->A[j-1];
        }
        L->A[i] = X;
    }
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLast(List *L, ElType X){
    if (Length(*L) == MaxEl){
        printf("List penuh\n");
    }
    else{
        L->A[Length(*L)] = X;
    }
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void DeleteFirst(List *L){
    if (IsEmpty(*L)){
        printf("List kosong\n");
    }
    else{
        int i = 0;
        for (i; i < Length(*L)-1; i++){
            L->A[i] = L->A[i+1];
        }
        L->A[Length(*L)-1] = Mark;
    }
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void DeleteAt(List *L, IdxType i){
    if (IsEmpty(*L)){
        printf("List kosong\n");
    }
    else if (i < 0 || i >= Length(*L)){
        printf("Indeks tidak valid\n");
    }
    else{
        int j = i;
        for (j; j < Length(*L)-1; j++){
            L->A[j] = L->A[j+1];
        }
        L->A[Length(*L)-1] = Mark;
    }
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indekz */

void DeleteLast(List *L){
    if (IsEmpty(*L)){
        printf("List kosong\n");
    }
    else{
        L->A[Length(*L)-1] = Mark;
    }
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

List Concat(List L1, List L2){
    List L3;
    L3 = MakeList();
    int i = 0;
    for (i; i < Length(L1); i++){
        InsertLast(&L3, L1.A[i]);
    }
    int j = 0;
    for (j; j < Length(L2); j++){
        InsertLast(&L3, L2.A[j]);
    }
    return L3;
}
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */
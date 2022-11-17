/*
Nama : Gevyndo Gunawan
NIM: 18221076   
Tanggal: 12 November 2022
Topik: Pra-praktikum 10
Deskripsi: Implementasi listdp.h
*/

#include"listdp.h"
#include<stdio.h>
#include<stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
/* Mengirim true jika list kosong. Lihat definisi di atas. */
    return ((((L).First) == Nil)&&(((L).Last) == Nil));
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    (L)->First = Nil;
    (L)->Last = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka (P)->info=X, (P)->next=Nil, (P)->prev=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
    ElmtList *P=(ElmtList*)malloc(sizeof(ElmtList));
    if(P!=Nil){
        (P)->info = X;
        (P)->prev = Nil;
        (P)->next = Nil;
        return P;
    }
    else
    {
        return Nil;
    }
    
}
void Dealokasi (address P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
/* Mencari apakah ada elemen list dengan (P)->info=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    address check=Nil;
    if (!IsEmpty(L)){
        address P;
        P=((L).First);
        while(((P)->info!=X)&&((P)->next!=Nil)){
            P=(P)->next;
        }
        if((P)->info==X){
            check=P;
        }
    }
    return check;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address P=Alokasi(X);
    if(P!=Nil){
        InsertFirst(L,P);
    }
}
void InsVLast (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address P=Alokasi(X);
    if(P!=Nil){
        InsertLast(L,P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    address P;
    DelFirst(L,&P);
    *X = (P)->info;
    Dealokasi(P);
}
void DelVLast (List *L, infotype *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    address P;
    DelLast(L,&P);
    *X = (P)->info;
    Dealokasi(P);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    if(IsEmpty(*L)){
        ((*L).First)= P;
        ((*L).Last) = P;
    }
    else{
        InsertBefore(L,P,((*L).First));
    }
}
void InsertLast (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if(IsEmpty(*L)){
        InsertFirst(L,P);
    }
    else{
        InsertAfter(L,P,((*L).Last));
    }
}
void InsertAfter (List *L, address P, address Prec){
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    (P)->prev = Prec;
    (P)->next = (Prec)->next;
    (Prec)->next = P;
    if((P)->next == Nil){
        ((*L).Last) = P;
    }
    else{
        ((P)->next)->prev = P;
    }
    

}
void InsertBefore (List *L, address P, address Succ){
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
    (P)->prev = (Succ)->prev;
    (P)->next = Succ;
    (Succ)->prev = P;
    if((P)->prev == Nil){
        ((*L).First) = P;
    }
    else{
        ((P)->prev)->next = P;
    }
    
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    *P = ((*L).First);
    if(((*L).First)==((*L).Last)){
        ((*L).First)=Nil;
        ((*L).Last)=Nil;
    }
    else{
        ((*L).First)=(((*L).First))->next;
        (((*L).First))->prev = Nil;
    }
    (*P)->next=Nil;
    (*P)->prev=Nil;
}
void DelLast (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
    *P=((*L).Last);
    if(((*L).First)==((*L).Last)){
        ((*L).First)=Nil;
        ((*L).Last)=Nil;
    }
    else{
        ((*L).Last)=(((*L).Last))->prev;
        (((*L).Last))->next=Nil;
    }
    (*P)->next=Nil;
    (*P)->prev=Nil;
}
void DelP (List *L, infotype X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan (P)->info=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan (P)->info=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    address cari=Search(*L,X);
    if(cari!=Nil){
        address P=((*L).First),prec=Nil;
        while (P!=cari){
            prec=P;
            P=(P)->next;
        }
        if(prec==Nil){
            DelFirst(L,&cari);
        }
        else{
            DelAfter(L,&cari,prec);
        }
    }
}
void DelAfter (List *L, address *Pdel, address Prec){
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus (Prec)->next: */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel=(Prec)->next;
    if((*Pdel)->next==Nil){
        (Prec)->next=Nil;
        ((*L).Last)=Prec;
    }
    else{
        (Prec)->next = (*Pdel)->next;
        ((*Pdel)->next)->prev = Prec;
    }
    (*Pdel)->prev=Nil;
    (*Pdel)->next=Nil;
}
void DelBefore (List *L, address *Pdel, address Succ){
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus (Succ)->prev: */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel=(Succ)->prev;
    if((*Pdel)->prev==Nil){
        (Succ)->prev=Nil;
        ((*L).First)=Succ;
    }
    else{
        (Succ)->prev=(*Pdel)->prev;
        ((*Pdel)->prev)->next=Succ;
    }
    (*Pdel)->prev=Nil;
    (*Pdel)->next=Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    if (IsEmpty(L)){
        printf("[]");
    }
    else{
        address P=((L).First);
        printf("[");
        while(P!=Nil){
            if(P==((L).Last)){
                printf("%d",(P)->info);
            }
            else{
                printf("%d,",(P)->info);
            }
            P=(P)->next;
        }
        printf("]");
    }
}
void PrintBackward (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    if (IsEmpty(L)){
        printf("[]");
    }
    else{
        address P=((L).Last);
        printf("[");
        while(P!=Nil){
            if(P==((L).First)){
                printf("%d",(P)->info);
            }
            else{
                printf("%d,",(P)->info);
            }
            P=(P)->prev;
        }
        printf("]");
    }
}
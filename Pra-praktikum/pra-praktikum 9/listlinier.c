// NIM : 18221076
// Nama : Gevyndo Gunawan
// Tanggal : 6 November 2022
// Topik Praktikum : Pra-praktikum
// Deskripsi : Implementasi listlinier.h

#include"listlinier.h"
#include<stdio.h>
#include<stdlib.h>

boolean IsEmpty (List L){
/* Mengirim true jika list kosong */
    return First(L) == Nil;
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    First(*L)=Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    ElmtList *P=(ElmtList*)malloc(sizeof(ElmtList));
    if (P!=Nil){
        Info(P)=X;
        Next(P)=Nil;
        return P;
    }
    else{
        return Nil;
    }
    
}
void Dealokasi (address *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    free(*P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    address hasil=Nil;
    if (!IsEmpty(L)){
        address P=First(L);
        boolean found=false;
        while (P!=Nil&&!found){
            if (Info(P)==X){
                found=true;
                hasil=P;
            }
            else{
                P=Next(P);
            }
        }
    }
    return hasil;
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address tambah=Alokasi(X);
    if (tambah!=Nil){
        InsertFirst(L,tambah);
    }
}
void InsVLast (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address tambah=Alokasi(X);
    if (tambah!=Nil){
        InsertLast(L,tambah);
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    address hasil;
    DelFirst(L,&hasil);
    *X=Info(hasil);
    Dealokasi(&hasil);
}
void DelVLast (List *L, infotype *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    address hasil;
    DelLast(L,&hasil);
    *X=Info(hasil);
    Dealokasi(&hasil);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    Next(P)=First(*L);
    First(*L)=P;
}
void InsertAfter (List *L, address P, address Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P)=Next(Prec);
    Next(Prec)=P;
}
void InsertLast (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if(IsEmpty(*L)){
        Next(P)=Nil;
        First(*L)=P;
    }
    else{
        address x=First(*L);
        while (Next(x)!=Nil){
            x=Next(x);
        }
        InsertAfter(L,P,x);
    }
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    *P=First(*L);
    if (Next(*P)==Nil){
        CreateEmpty(L);
    }
    else{
        First(*L)=Next(First(*L));
    }
}
void DelP (List *L, infotype X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    address P=Search(*L,X);
    if(P!=Nil){
        address Acari=First(*L);
        address prec=Nil;
        address x;
        boolean found=(Info(Acari)==X);
        if (found){
            DelFirst(L,&P);
        }
        else{
            while (Acari!=Nil&&!found){
                if (Info(Acari)==X){
                    found=true;
                    DelAfter(L,&x,prec);
                }
                else{
                    prec=Acari;
                    Acari=Next(Acari);
                }
            }
        }
    }
    Dealokasi(&P);
}
void DelLast (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
    address x=First(*L);
    if (Next(x)==Nil){
        *P=First(*L);
        CreateEmpty(L);
    }
    else{
        address y=First(*L);
        while (Next(Next(y))!=Nil){
            y=Next(y);
        }
        DelAfter(L,P,y);
    }
}
void DelAfter (List *L, address *Pdel, address Prec){
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel=Next(Prec);
    if (Next(*Pdel)==Nil){
        Next(Prec)=Nil;
    }
    else{
        Next(Prec)=Next(Next(Prec));
    }
    
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    if (!IsEmpty(L)){
        address P=First(L);
        printf("[");
        while (P!=Nil){
            if (Next(P)!=Nil){
                printf("%d,",Info(P));
            }
            else{
                printf("%d",Info(P));
            }
            P=Next(P);
        }
        printf("]");
    }
    else{
        printf("[]");
    }
}
int NbElmt (List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    int count=0;
    if (!IsEmpty(L)){
        address P=First(L);
        while (P!=Nil){
            count+=1;
            P=Next(P);
        }
    }
    return count;
}
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
/* Mengirimkan nilai Info(P) yang maksimum */
    address P=First(L);
    infotype maks=Info(P);
    while (P!=Nil){
        if (Info(P)>maks){
            maks=Info(P);
        }
        P=Next(P);
    }
    return maks;
}
/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    CreateEmpty(L3);
    address pertama=First(*L1);
    address kedua=First(*L2);
    if (!IsEmpty(*L1)){
        First(*L3)=First(*L1);
        while(Next(pertama)!=Nil){
            pertama=Next(pertama);
        }
        Next(pertama)=kedua;
    }
    else{
        First(*L3)=First(*L2);
    }
    First(*L1)=Nil;
    First(*L2)=Nil;
}
address AdrMax (List L){
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
    infotype maks=Max(L);
    return Search(L,maks);
}
infotype Min (List L){
/* Mengirimkan nilai info(P) yang minimum */
    address P=First(L);
    infotype min=Info(P);
    while (P!=Nil){
        if (Info(P)<min){
            min=Info(P);
        }
        P=Next(P);
    }
    return min;
}
address AdrMin (List L){
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    infotype min=Min(L);
    return Search(L,min);
}
float Average (List L){
/* Mengirimkan nilai rata-rata info(P) */
    address P=First(L);
    float total=0;
    int count=NbElmt(L);
    while (P!=Nil)
    {
        total+=Info(P);
        P=Next(P);
    }
    return (total/count);
}
/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L){
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
    if(NbElmt(*L)>1){
        address pertama=First(*L);
        address P=First(*L);
        address sebelum=Nil;
        address sesudah=Nil;
        while (P!=Nil){
            sesudah=Next(P);
            Next(P)=sebelum;
            sebelum=P;
            P=sesudah;
        }
        First(*L)=sebelum;
    }
}
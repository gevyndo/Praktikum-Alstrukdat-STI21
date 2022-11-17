/*
Nama : Gevyndo Gunawan
NIM: 18221076   
Tanggal: 12 November 2022
Topik: Praaktikum 10
Deskripsi: Implementasi queuelist.h
*/

#include "queuelist.h"
#include <stdio.h>
#include <stdlib.h>

void Alokasi (address *P, infotype X){
	/* I.S. Sembarang */
	/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        	Next(P)=Nil */
	/*  	P=Nil jika alokasi gagal */
	/* ALGORITMA */
	*P = (address) malloc(sizeof(infotype));
    Info(*P) = X;
    Next(*P) = Nil;
}
void Dealokasi (address  P){
	/* I.S. P adalah hasil alokasi, P != Nil */
	/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
	/* ALGORITMA */
	free(P);
}
boolean IsEmpty (Queue Q){
	/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
	/* ALGORITMA */
	return((Head(Q) == Nil) && (Tail(Q) == Nil));
}
int NbElmt(Queue Q){
	/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
	/* KAMUS */
	address p;
	int count = 0;
	/* ALGORITMA */
	p = Head(Q);
    while (p != Nil) {
   	 count++;
   	 p = Next(p);
    }
    return count;
}
/*** Kreator ***/
void CreateEmpty(Queue * Q){
	/* I.S. sembarang */
	/* F.S. Sebuah Q kosong terbentuk */
	/* ALGORITMA */
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}
/*** Primitif Enqueue/Dequeue ***/
void Enqueue (Queue * Q, infotype X){
	/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
	jika alokasi berhasil; jika alokasi gagal Q tetap */
	/* Pada dasarnya adalah proses insert last */
	/* I.S. Q mungkin kosong */
	/* F.S. X menjadi TAIL, TAIL "maju" */
	/* KAMUS */
	address P;
	/* ALGORITMA */
    Alokasi(&P, X);
    if (IsEmpty(*Q)) {
   	 Head(*Q) = P;
    	Tail(*Q) = P;
	} else {
   	 Next(Tail(*Q)) = P;
   	 Tail(*Q) = P;
    }
}
void Dequeue(Queue * Q, infotype * X){
	/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
    	elemen HEAD */
	/* Pada dasarnya operasi delete first */
	/* I.S. Q tidak mungkin kosong */
	/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
	/* KAMUS */
	address P;
	/* ALGORITMA */
	*X = InfoHead(*Q);
	P = Head(*Q);
    Head(*Q) = Next(Head(*Q));
    if (Head(*Q) == Nil){
   	 Tail(*Q) = Nil;
	}
	Dealokasi(P);
}


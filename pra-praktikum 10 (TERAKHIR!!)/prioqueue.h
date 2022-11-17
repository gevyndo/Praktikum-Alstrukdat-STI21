/* File : prioqueue.h */
/* Representasi priority queue dengan list berkait dengan first (HEAD) dan last (TAIL) */
#ifndef _PRIOQUEUE_H
#define _PRIOQUEUE_H
#include "boolean.h"
#include <stdlib.h>

/* Konstanta */
#define Nil NULL

/* Deklarasi infotype */
typedef int infotype;

/* Queue dengan representasi berkait dengan pointer */
typedef struct tElmtQueue * address;
typedef struct tElmtQueue {
	int Prio;	// [1..3] dengan 3 adalah prioritas tertinggi
	infotype Info;
	address Next;
} ElmtQueue;

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct {
	address HEAD;  /* alamat penghapusan */
	address TAIL;  /* alamat penambahan */
} Queue;

/* Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->Info
#define InfoTail(Q) (Q).TAIL->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info
#define Prio(P) (P)->Prio

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X, int prio);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X,
        Next(P)=Nil, dan Prio(P)=prio */
/*      P=Nil jika alokasi gagal */
void Dealokasi (address  P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmpty (Queue Q);
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmt(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmpty(Queue * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk (i.e. Head(Q) = Nil dan Tail(Q) = Nil) */
/*** Primitif Add/Delete ***/
void Enqueue (Queue * Q, infotype X, int prio);
/* Proses: Mengalokasi X dan menambahkan X pada posisi setelah element dengan 
   prioritas yang lebih tinggi/sama, dan sebelum element dengan prioritas yang 
   lebih rendah jika alokasi berhasil; jika alokasi gagal Q tetap */
/* I.S. Q mungkin kosong */
/* F.S. X diletakkan setelah setelah element dengan prioritas yang lebih 
   tinggi/sama, dan sebelum element dengan prioritas yang lebih rendah.
   Apabila X diletakkan di posisi terakhir, maka TAIL = element X. */
void Dequeue (Queue * Q, infotype * X);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */

#endif

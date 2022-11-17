#include "linkstack.h"
#include <stdio.h>
#include <stdlib.h>


/* ********* PROTOTYPE MANAJEMEN MEMORI ********* */
void Alokasi(address *P, ElType X)
{
   *P = (address) malloc(1 * sizeof(Node));
	if(*P!=NULL){
			Info(*P) = X;
			Next(*P) = NULL;			
	}
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil */
/* P=Nil jika alokasi gagal */
void Dealokasi(address P)
{
	free(P);
}
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
/* Prototype manajemen memori */

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty(Stack S)
{
	return Top(S) == NULL;
}
/* Mengirim true jika Stack kosong: TOP(s) = NIL */

void CreateEmpty(Stack *S)
{
	Top(*S) = NULL;
}
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */

void Push(Stack *S, ElType X){
	address P;
	/* ALGORITMA */
	if (IsEmpty(*S)) {
   	 Alokasi(&Top(*S), X);
	} else {
   	 Alokasi(&P, X);
   	 if (P != Nil) {
   		 Next(P) = Top(*S);
   		 Top(*S) = P;
   	 }
    }
}
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */

void Pop(Stack *S, ElType *X)
{
	address p;
	*X = InfoTop(*S);
	p = Top(*S);
	Top(*S) = Next(Top(*S));
	Next(p) = NULL;
	free(p);
}

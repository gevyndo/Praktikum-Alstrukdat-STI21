/*
Nama : Gevyndo Gunawan
NIM: 18221076   
Tanggal: 12 November 2022
Topik: Pra-praktikum 10
Deskripsi: Implementasi listdp.h
*/

#include <stdio.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r) {
		int i = 0;
		address P = First(L);
    for (i=0; i<r; i++){
			P = Next(P);
		}
    infotype x=Info(P);
		return x;
	}

int main () {
  List L;
  CreateEmpty(&L);
  int r;
  int x;
  int y;
  scanf("%d", &x);
  if (x!=0){
    while (x!=0){
      InsVLast(&L, x);
      scanf("%d", &x);
    }
    scanf("%d",&r);
    printf("%d\n", ElemenKeN(L, r));
  } 
  else{
    scanf("%d",&y);
    printf("List Kosong\n");
  } 
  return 0;
}
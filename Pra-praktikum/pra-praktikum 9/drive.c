#include<stdio.h>
#include<stdlib.h>
#include"listlinier.h"
#include"listlinier.c"
int main(){
    List L,M,N;
    address P,Q;
    infotype maks1,maks2,r1,r2;
    int i,input,X,hitung1,hitung2;
    CreateEmpty(&L);
    InsVFirst(&L,9);
    for (i=0;i<5;i++){
        scanf("%d",&input);
        InsVLast(&L,input);
    }
    maks1=Max(L);
    hitung1=NbElmt(L);
    printf("Max: %d\n",maks1);
    printf("Elemen sebelum dihapus: %d\n",hitung1);
    DelVLast(&L,&X);
    printf("Nilai yang dihapus: %d\n",X);
    hitung2=NbElmt(L);
    printf("Elemen setelah dihapus: %d\n",hitung2);
    maks2=Max(L);
    printf("Max: %d\n",maks2);
    InversList(&L);
    PrintInfo(L);
    
    /*InsVFirst(&M,8);
    for (i=0;i<2;i++){
        scanf("%d",&input);
        InsVLast(&M,input);
    }
    PrintInfo(M);
    Konkat1(&L,&M,&N);
    PrintInfo(N);
    PrintInfo(L);
    PrintInfo(M);
    DelP(&M,9);
    PrintInfo(M);*/
}
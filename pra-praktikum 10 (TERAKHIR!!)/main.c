#include "listdp.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
	List L;
	CreateEmpty(&L);
	if (IsEmpty(L)) {
		printf("IsEmpty Acc\n");
	} else {
		printf("Salah\n");
	}
	PrintForward(L);
	PrintBackward(L);
	InsVFirst(&L, 3);
	InsVFirst(&L, 4);
	InsVFirst(&L, 5);
	InsVFirst(&L, 6);
	InsVFirst(&L, 7);
	InsVFirst(&L, 8);
	InsVFirst(&L, 9);
	PrintForward(L);
	PrintBackward(L);
	infotype X;
	DelVFirst(&L, &X);
	PrintForward(L);
	PrintBackward(L);
	return 0;
}

// NIM : 18221076
// Nama : Gevyndo Gunawan
// Tanggal : 23 September 2022
// Topik Praktikum : Pra-Praktikum 4
// Deskripsi : Implementasi array.h

#include "array.h"
#include "stdio.h"


void MakeEmpty (TabInt *T)
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    (*T).Neff = 0; 
}

int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
    if (IsEmpty(T)){
        return 0;
    }
    else{
        return T.Neff;
    }
}
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
{
    return IdxMax-IdxMin + 1;
}
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
{
    return IdxMin;
}
IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilpluskan sebuah elemen *** */
{
    return T.Neff;
}
ElType GetElmt (TabInt T, IdxType i)
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
{
    return T.TI[i];
}

void SetTab (TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
{
    IdxType i = 0;
    for (i; i < NbElmt(Tin) ; i++)
    {
       (*Tout).TI[i] = Tin.TI[i];
    }
    (*Tout).Neff = Tin.Neff;
}
void SetEl (TabInt *T, IdxType i, ElType v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
{
    (*T).TI[i] = v;
    SetNeff(T, (*T).Neff+1);
}

void SetNeff (TabInt *T, IdxType N)
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
{
    (*T).Neff = N;
}

boolean IsIdxValid (TabInt T, IdxType i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return ((i>= IdxMin) && (i<= IdxMax));
;
}
boolean IsIdxEff (TabInt T, IdxType i)
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return ((i>= IdxMin) && (i<= NbElmt(T)));

}

boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
    return T.Neff == 0;
}
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return T.Neff == IdxMax;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
{
    int i ;

    if (IsEmpty(T))
    {
        printf("Tabel kosong\n");
    }
    else{
        for (i = IdxMin ; i <= NbElmt(T) ; i++){
            printf("%d:%d\n", i, T.TI[i]);
        }
    }

}

TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */
{
	TabInt hasilplus;
	IdxType i = 1;

	for (i ; i <= NbElmt(T1); i++){
        hasilplus.TI[i] =  T1.TI[i] + T2.TI[i];
    }
    hasilplus.Neff = NbElmt(T1);
	return hasilplus;
}

TabInt MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */
{
    TabInt hasilmin;
    IdxType i = 1;

    for (i ; i <= NbElmt(T1); i++){
        hasilmin.TI[i] = T1.TI[i] - T2.TI[i];
    }
    hasilmin.Neff = NbElmt(T1);
    return hasilmin;
}

ElType ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
    IdxType i = IdxMin;
    ElType max = -99999;

    for (i ; i<= NbElmt(T); i++)
    {
        if (T.TI[i] > max)
        {
            max = T.TI[i];
        }
    }
    return max;
}

ElType ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
{
    IdxType i = IdxMin;
    ElType min = 99999;

    for (i ; i <= NbElmt(T); i++){
        if (T.TI[i] < min) {
            min = T.TI[i];
        }
    }
    return min;

}
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */
{
    IdxType i;
    ElType imax, max;

    max= T.TI[GetFirstIdx(T)];
    imax= GetFirstIdx(T);
    for (i = GetFirstIdx(T) + 1; i<= GetLastIdx(T); i++)
    {
        if (T.TI[i] > max)
        {
            imax = i;
            max = T.TI[i];
        }
    }
    return imax;
}

IdxType IdxMinTab (TabInt T)
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */
{
    IdxType i;
    ElType imin, min;

    min = T.TI[GetFirstIdx(T)];
    imin = GetFirstIdx(T);
    for (i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++){
        if (T.TI[i] < min){
            imin = i;
            min = T.TI[i];
        }
    }
    return imin;

}
#include <stdio.h>
#include <stdlib.h>
#include "list.h" //interface disertakan

void PrintList(const List L);

void PrintList(const List L){
	Position P = Header (L);
	do{
		P=Advance(P);
		printf("%d", Retrieve(P));
	}
	while (!IsLast(P,L));
	printf("\n");
}


int main(int argc, char *argv[]){
	List L= NULL;				//deklarasi NULL list(pointer tipe struct node bernilai null)
	Position P = NULL;			//deklarasi pointer tipe struct node untuk menunjuk posisi node sekarang
	
	L = Construct(L); 			//konstruksi linked list dengan memanggil fungsi struct
	X = Header(L);				//P sekarang berada pada L atau header dari linked list
	
	Insert(77, L, P);			//insert elemen-1 (setelah header)
	PrintList(L);				//cetak list
	
	P=Advance(P);				//P sekarang berada pada node ke-1
	Insert(100, L, P);			//insert elemen-2
	PrintList(L);				//cetak list
	
	P=Advance(P);				//P sekarang berada pada node ke-2
	Insert(277, L, P);			//insert elemen-3
	PrintList(L);				//cetak list
	
	return 0;
}

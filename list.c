#include <stdio.h>
#include <stdlib.h>
#include "list.h" //interface disertakan

struct Node{
	ElementType Element;
	Position Next;
};

List Construct(List L){
	L = malloc(sizeof(struct Node));
	if(L==NULL) printf("Memori Kosong dan Tidak Dapat Dialokasi!!!");
	L->Next = NULL;
	return L;
}

Position Header(List L){
	return L;
}

void Insert(ElementType X, List L, Position P){
	Position TmpCell=NULL;
	
	TmpCell = malloc(sizeof(struct Node));
	if(TmpCell == NULL) printf("Memori Kosong dan Tidak Dapat Dialokasi!!!");
	TmpCell->Element = X;
	TmpCell -> Next = P->Next;
	//P->Next = TmpCell; //timpa (overwrite) P->Next
}
Position Advance(Position P){
	return P->Next;
}
ElementType Retrieve(Position P){
	return P->Element;
}

int IsLast(Position P, List L){
	return P->Next == NULL;
}
      

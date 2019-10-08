typedef void ElementType; //deklarasi tipe data ElementType
/* preposessing kondisional, jika _LIST_H sudah didefinisikan
 dan di-include sebelumnya, maka tidak perlu didefinisikan kembali */
 
#ifndef _LIST_H //_LIST_H adalah nama makro
#define _LIST_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List Construct(List L);			//fungsi untuk membuat list(Header L)
void Insert (ElementType X, List L, Position P); //fungsi untuk insersi elemen

Position Header (List L); //fungsi untuk mengset L sebagai Header
Position Advance(Position P); /* fungsi untuk memajukan pointer posisi ke node /
								 elemen selanjutnya */

ElementType Retrieve(Position P); /* fungsi untuk mendapatkan (mengambil) nilai elemen
									pada posisi P */
int IsLast(Position P, List L); /* fungsi untuk mencek apakah node/elemen pada
									posisi P merupakan node/elemen terakhir */

#endif //Akhir dari _LIST_H


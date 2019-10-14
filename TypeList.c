#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tlist {
    size_t typeSize;
    size_t size;
    size_t _iterator;

    void (*push)(struct tlist**, char*);
    char* (*next)(struct tlist**);
    void (*pop)(struct tlist**, char*);
    void (*shift)(struct tlist**, char*);
    int (*rewind)(struct tlist**);

    char* addressSpace;

} TypeList;

char* _next(TypeList** l){
    if((*l)->_iterator < (*l)->size){
        (*l)->_iterator++;
        return ((char*) (*l)->addressSpace + ((*l)->_iterator * (*l)->typeSize));
    }else{
        return NULL;
    }
}

// C calls function __by value__, we need a Pointer to a Pointer in order to change its address (**int x -> *(x) = 0xDEADC0DE)
void _push(TypeList** l, char* b){
    // Allocate new Memory
    TypeList** oldpointer = l;
    TypeList* lPointer = (TypeList*) realloc(*l, sizeof(TypeList) + ((*l)->size+1) * (*l)->typeSize);
    if(lPointer == NULL) return;
    *l = lPointer;

    // Resize Actual List
    char* accessSpacePointer = (char*) realloc((*l)->addressSpace, (((*l)->size + 1) * (*l)->typeSize));
    if(accessSpacePointer == NULL) return;
    (*l)->addressSpace = (char*) accessSpacePointer;

    memcpy((void*) ((*l)->addressSpace + (((*l)->size+1) * (*l)->typeSize)), (void*) b, (*l)->typeSize);

    (*l)->size++;
    return;
}

void _pop(TypeList **l, char* buffer){
    for(int i = 0; i <= (*l)->size; i++){
        buffer[i] = *((*l)->addressSpace + ((((*l)->size) * ((*l)->typeSize)) + i));
    }

    void* lPointer = realloc((*l), sizeof(TypeList) + (((*l)->size-1) * (*l)->typeSize));
    if(lPointer == NULL) return;
    *l = lPointer;


    lPointer = realloc((*l)->addressSpace, (((*l)->size - 1) * (*l)->typeSize));
    if(lPointer == NULL) return;
    (*l)->addressSpace = (char*) lPointer;

    (*l)->size--;


}

void _shift(TypeList** l, char* buffer){

    printf("0-1: %p \n0-2: %p\n", 
        (*l)->addressSpace, ((char*) (*l)->addressSpace + ((*l)->_iterator * (*l)->typeSize)), 
        (int*)((char*) (*l)->addressSpace + ((*l)->_iterator * (*l)->typeSize))
    
    );

    // Put 1st element into char array <buffer>, i know this is spaghetti code, even i dont understand what is happening here.... but it works
    for(int i = (*l)->typeSize; i < (*l)->typeSize * 2; i++){
        buffer[i - (*l)->typeSize] = *(int*)((char*) (*l)->addressSpace + ((*l)->typeSize + (i - (*l)->typeSize)));
    }

    // Move all elements to n-1
    for(int i = 2; i < (*l)->size+1; ++i){
        memcpy((*l)->addressSpace + ((i-1) * (*l)->typeSize), (*l)->addressSpace + (i * (*l)->typeSize), (*l)->typeSize);
    }
    (*l)->size--;


    // Reallocate struct
    void* sPointer = realloc((*l), sizeof(TypeList) + (((*l)->size) * (*l)->typeSize));
    if(sPointer == NULL) return;
    *l = sPointer;

    // Reallocate list
    char* newPointer = realloc((*l)->addressSpace, (*l)->size * (*l)->typeSize);
    if(newPointer == NULL) return;
    (*l)->addressSpace = newPointer;
    return;
}

int _rewind(TypeList** l){
    int size = (*l)->_iterator;
    (*l)->_iterator = 0;
    return size;
}

TypeList* List(size_t type) {
    TypeList *list = (TypeList*) malloc(sizeof(TypeList));
    list->typeSize = type;
    list->size = 0;
    list->_iterator = 0;
    list->push = &_push;
    list->next = &_next;
    list->pop = &_pop;
    list->shift = &_shift;

    list->rewind = &_rewind;

    list->addressSpace = (char*) malloc(sizeof(char));
    return list;
}




int main(int argc, char** argv){
    TypeList* a = List(sizeof(int));
    int val = 8831;
    int value2 = 994122;
    int value3 = 391027;
    a->push(&a, (char*) &val);
    a->push(&a, (char*) &value2);
    a->push(&a, (char*) &value3);
    
    printf("List is now @%p\nLength: %li\n", a, a->size);

    char buffer[4] = {'\0', '\0', '\0', '\0'};
    a->pop(&a, (char*) buffer);
    printf("Popped of Value: %i\n", *((int*) buffer));

    int* i;
    while((i = (int*) a->next(&a)) != NULL){
        printf("[@%p]-> %i\n", i, *i);
    }

    char puffer[4] = {0x00, 0x00, 0x00, 0x00};
    a->shift(&a, (char*)puffer);
    printf("Shifted value: %i\n", *((int*) puffer));

    printf("Rewinding, internal counter was @%i\n", a->rewind(&a));
    
    int* x;
    while((x = (int*) a->next(&a)) != NULL){
        printf("[@%p]-> %i\n", x, *x);
    }

    printf("--- Initializing a second list ---\n");
    TypeList* newList = List(sizeof(int));
    int c = 4214124;
    int k = 53425;
    int l = 523875;
    newList->push(&newList, &c);
    newList->push(&newList, &k);
    newList->push(&newList, &l);



    int* o;
    int indx = 0;
    while((o = (int*) newList->next(&newList)) != NULL){
        printf("NewList[%i] = %i\n", indx, *o);
        indx++;
    }

    return 0;

}

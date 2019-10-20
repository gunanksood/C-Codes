#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _TypeList TypeList;

struct _TypeList {
    size_t size;
    size_t _typeSize;
    size_t _iterator;

    void(*push)(TypeList**, char*);
    char*(*get)(TypeList**, int);
    void(*remove)(TypeList**, int);
    char*(*next)(TypeList**);
    void(*rewind)(TypeList**);
    void(*pop)(TypeList**, char**);
    void(*shift)(TypeList**, char**);
    


    char* space;
};

char* _next(TypeList** list){
    TypeList* l = (*list);
    if(l->_iterator < l->size){
        l->_iterator++;
        return l->get(list, l->_iterator - 1);
    }else{
        return NULL;
    }
}
void _rewind(TypeList** list){
    (*list)->_iterator = 0;
    return;
}

void _push(TypeList** list, char* data){
    // Dereference Double Pointer (Pointer -> Pointer -> Actual Object) to (Pointer -> Actual Object)
    TypeList* l = (*list);

    // Allocate already claimed memory + the actual size of the list (size+1 * typeSize)
    TypeList* newPointer = (TypeList*) realloc(l, sizeof(*l) + (l->size+1 * l->_typeSize));
    if(newPointer == NULL) return;
    (*list) = newPointer;
    l = newPointer;

    char* newList = (char*) realloc(l->space, sizeof(l->space + (l->size + 1 * l->_typeSize)));
    if(newList == NULL) return;
    l->space = newList;

    // Copy <data> to the end of the list
    // End of the list = Address of list + (List Size * Type)
    
    // f.e. 0x7FFFD403A664 + (6 * 4) = 0x7FFFD403A67C
    // The new Element will be located @ 0x7FFFD403A67C
    memcpy((l->space + (l->size * l->_typeSize)), data, l->_typeSize);
    l->size++;
    return;
}

char* _get(TypeList** list, int index){
    TypeList* l = (*list);
    return l->space + (index * l->_typeSize);
}

void _remove(TypeList** list, int index){
    TypeList* l = (*list);
    
    // Set specified index to 0 if in range
    if(index < l->size){
        memset(l->space + (index * l->_typeSize), '\0', l->_typeSize);

        // Iterate over all elements after index and memcpy them to the memory address before them
        for(int i = index+1; i < l->size; ++i){
            memcpy((l->space + ((i-1) * l->_typeSize)), (l->space + (i * l->_typeSize)), l->_typeSize);
        }
        // Decrement the List size
        l->size--;


        // Allocate more memory for entire struct
        TypeList* listPointer = (TypeList*) realloc(*list, sizeof(TypeList) + (l->size * l->_typeSize));
        if(listPointer == NULL) return;
        list = &listPointer;

        // Re-allocate memory for actual char Array (List)
        char* newPointer = (char*) realloc(l->space, (l->size * l->_typeSize));
        if(newPointer == NULL) return;
        l->space = newPointer;

        // This is done to ensure, that when other parts of the Program allocate memory on the heap these Objects dont overlap with out list and accidentaly overwrite the list content
    }
}

void _pop(TypeList** list, char** buffer) {
    TypeList* l = (*list);
    printf("Copying %liB from %p -> %p\n", l->_typeSize, l->get(list, l->size-1), *buffer);
    memcpy(*buffer, l->get(list, l->size-1), l->_typeSize);
    l->remove(list, l->size-1);
    return;
}

void _shift(TypeList** list, char** buffer){
    TypeList* l = (*list);
    // Copy the content of the first element into the buffer
    memcpy(*buffer, l->get(list, 0), l->_typeSize);
    // Remove the first element and then move all following elements to n-1
    l->remove(list, 0);
    return;
}


TypeList* List(size_t typeSize){
    TypeList* a = (TypeList*) malloc(sizeof(TypeList));
    a->_typeSize = typeSize;

    /* Functions */
    a->push = &_push;
    a->get = &_get;
    a->next = &_next;
    a->remove = &_remove;
    a->rewind = &_rewind;
    a->pop = &_pop;
    a->shift = &_shift;

    /* Allocation of actual list */
    a->space = (char*) malloc(sizeof(char*));
    return a;
}


int main(int argc, char** argv){

    // Please note, that i'm not an expert at C so this may or may not be a bit inaccurate

    // Create a new TypeList* with Integers as elements
    TypeList* t = List(sizeof(int));
    // TypeList::push as well as every other TypeList::* Function takes a double pointer to the actual list as the very first parameter
    // The second parameter needs to be declared beforehand because of the way the TypeList works:
    // TypeList takes the char* and copies TypeList::_typeSize Bytes of it to the end of the list
    // TypeList can be compared to the Java ArrayList<Type>();
    
    // Example on integers:
    // int a = 44;
    // TypeList::push(&List, (char*) &a)
    // Can be abbreviated to:
    // TypeList::push(&List, &a); {throws a warning that can be ignored}
    int data = 41284124;
    t->push(&t, (char*) &data);
    int data2 = 0x847;
    t->push(&t, (char*) &data2);

    int* i;
    int indx = 0;
    // TypeList::next returns the char* Pointer to the next element in the list, each call increments the lists internal _iterator object
    while((i = (int*) t->next(&t)) != NULL){
        printf("List[%i] => %i\n", indx, *i);
        indx++;
    }
    // TypeList::remove, well... removes the specified index from the list
    t->remove(&t, 0);
    // Rewind resets the list's internal _iterator object to 0 so the TypeList::next call would return the first index
    t->rewind(&t);
    printf("Remove List[0], rewinded: \n");

    indx = 0;
    while((i = (int*) t->next(&t)) != NULL){
        printf("List[%i] => %i {%p}\n", indx, *i, i);
        indx++;
    }

    printf("Adding 3 new Elements to the %li element big list\n", t->size);
    int a = 485125;
    int b = 71805617;
    int c = 578;
    t->push(&t, (char*) &a);
    t->push(&t, (char*) &b);
    t->push(&t, (char*) &c);

    char* buffer = malloc(t->_typeSize);
    // pop expects a char** buffer as it's second argument, this has to be malloc'ed so the function can access the array on the <HEAP>, it then memcpy's <N> Bytes from the end of the list into the buffer and removes
    // the element from list 
    t->pop(&t, &buffer);
    printf("Popped of %i from the end of the list\n", *(int*)buffer);

    
    t->rewind(&t);
    indx = 0;
    while((i = (int*) t->next(&t)) != NULL){
        printf("List[%i] => %i\n", indx, *i);
        indx++;
    }

    // Shift removes the first element of the list, it works exactly the same as TypeList::pop
    t->shift(&t, &buffer);
    printf("Shifted %i from the start of the list\n", *(int*)buffer);
    t->rewind(&t);
    indx = 0;
    while((i = (int*) t->next(&t)) != NULL){
        printf("List[%i] => %i\n", indx, *i);
        indx++;
    }

    free(buffer);
    free(t);


    return 0;
}
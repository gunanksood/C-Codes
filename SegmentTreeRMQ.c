#include<stdio.h>
#include<stdlib.h>
#define MAX 999999


int min(int a, int b) {
    return a < b ? a : b;
}
void buildTree(int *array, int *tree, int index , int left, int right) {
    
    int mid = (left + right) / 2;
    if (left == right) {
        tree[index] = array[left];
        return ;
    }
 
    buildTree(array, tree, (index * 2) + 1, left , mid);
    buildTree(array, tree, (index * 2) + 2, mid + 1, right);
    tree[index] = min(tree[index*2+1], tree[index*2+2]);
}
 
void updateTree(int *tree, int indexofArray , int value, int left, int right, int indexTree) {
    
    int mid = (left + right) / 2;
    if (left == right) {
        tree[indexTree] = value;
        return;
    }
    if (indexofArray >= left && indexofArray <= mid) {
        updateTree(tree, indexofArray, value, left, mid, indexTree*2 +1);
    } 
    else {
        updateTree(tree, indexofArray, value, mid + 1, right, indexTree*2 + 2);
    }
    tree[indexTree] = min(tree[indexTree*2+1] , tree[indexTree*2+2]);
}
 
int query(int *tree, int treeNode, int left, int right, int leftInputRange, int rightInputRange) {
    
    if (leftInputRange <= left && rightInputRange >= right) {
        return tree[treeNode];
    } 
    else if (leftInputRange > right || rightInputRange < left) {
        return MAX;
    } 
    else {
        return min(query(tree, treeNode*2+1, left, (left+right)/2, leftInputRange, rightInputRange), query(tree, treeNode*2+2,(left+right)/2 + 1, right, leftInputRange, rightInputRange));
    }
}
 
void printTree(int *tree, int length) {
    
    int index;
    for (index = 0; index < length; index++) {
        printf("%d ",tree[index]);
    }
}
 
int main() {
 
    int N, queries;
    int *array, *tree;
    int index;
    char ch; // "q" for queries and "u" for updateTree
    int a, b ,answer;
    scanf("%d%d",&N,&queries);
    array = (int*) malloc(N * sizeof(int));
    tree = (int*) malloc((2*N - 1) * sizeof(int));
    
    for (index = 0; index < N; index++) {
        scanf("%d",&array[index]);
    }
    buildTree(array, tree, 0, 0, N-1);
    for (index = 0; index < queries ; index++) {
        scanf(" %c",&ch);
        scanf("%d%d",&a,&b);
        if(ch == 'q') {
            answer = query(tree, 0 , 0, N-1, a-1, b-1);
            printf("%d\n",answer);
        } 
        else {
            updateTree(tree, a-1, b, 0, N-1, 0);
        }
    }
    return 0;
}

/*
Test Case :

Sample Input:
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 3 5

Sample Output:
1
1
2
3
*/



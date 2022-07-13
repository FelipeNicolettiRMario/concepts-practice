#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int value;
   struct Node *next;

}NODE;


void addValueHead(int value, NODE** linkedList){
    NODE* newNode = malloc(sizeof(NODE));
    newNode->value = value;
    newNode->next = *linkedList;

    *linkedList = newNode;
}

void removeNodeFromValueHead(int value, NODE** linkedList){
    NODE* listCopy = malloc(sizeof(NODE));
    listCopy = *linkedList;

    while (listCopy->next->value != value)
    {
       listCopy = listCopy->next;
    }

    
    NODE* nodeToRemove = malloc(sizeof(NODE));
    nodeToRemove = listCopy->next;

    listCopy->next = listCopy->next->next;

    free(nodeToRemove);
}

void printLinkedList(NODE* linkedList){
    NODE* copyNode = malloc(sizeof(NODE));
    copyNode->value = linkedList->value;
    copyNode->next = linkedList->next;



    while (copyNode != NULL)
    {
        printf("%i\n",copyNode->value);
        copyNode = copyNode->next;
    }
    
}
int main(){

    NODE* linkedListWithoutHead = malloc(sizeof(NODE));
    linkedListWithoutHead->value = 10;
    linkedListWithoutHead->next = NULL;
    addValueHead(5,&linkedListWithoutHead);
    addValueHead(25,&linkedListWithoutHead);
    addValueHead(30,&linkedListWithoutHead);
    removeNodeFromValueHead(25,&linkedListWithoutHead);
    printLinkedList(linkedListWithoutHead);

}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

struct Node* first = NULL;
struct Node* last = NULL;

void QUEUE(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(Node)); //crea un nodo
    temp->data = x;
    temp->next= NULL;
    if(first == NULL && last == NULL){//if the queue is empty
        first = last = temp; //pone la dirección del first y last como la dirección del nuevo nodo "temp"
        return;
    }else{  //porque ya hay un puntero al nodo "last"
    last->next = temp;//primero se pondrá la dirección del "last" de hasta ese momento, como la dirección del nodo creado recien (temp)
    last = temp;//luego se cambia la dirección en la variable "last"
    }
    
}

void DEQUEUE(){
    struct Node* temp = first;
    if(first == NULL) return;
    if(first == last){
        printf("El número que fue 'dequeued'/eliminado es: %i\n",first->data);
        first = last = NULL;
    }
    else{
        printf("El número que fue 'dequeued'/eliminado es: %i\n",first->data);
        first = first->next;
    }
    free(temp);
}

void PEEK(){
    if(first != NULL){
    printf("El primer número de la lista es: %i, y es el primer número en salir de la lista.\n", first->data);
    }
    else{
    printf("Fila vacía\n");
    }
}

void ISEMPTY(){
    if(first == NULL){
        printf("Fila vacía\n");
    }
    else{
        printf("Fila no vacía\n");
    }
}

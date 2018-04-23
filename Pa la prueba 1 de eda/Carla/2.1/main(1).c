#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct node {
	int n;
	struct node *next;
} node;

node *head = NULL;

void push(char parentesis) {
	// crea un nuevo nodo vacio
	node *nuevoNodo = (node *)malloc(sizeof(node));

	// inicialización del nodo
	nuevoNodo->n = parentesis;
	nuevoNodo->next = NULL;

	// Verificando si la lista esta vacia
	if (head == NULL) {
		head = nuevoNodo;
	}
	// insertar al inicio
	else {
		nuevoNodo->next = head;
		head = nuevoNodo;
	}
}

void pop(void) {
	node *temp = head;
	if (temp != NULL) {			  // si existe una pila
		if (temp->next != NULL) { // si sigue existiendo una pila
			head = temp->next;
		} else { // si pila queda vacia
			head = NULL;
		}
		free(temp);
	} else {
		printf("Pila vacía\n");
	}
}

int isempty() {
	if (head != NULL) // si no esta vacia
	{
		return 0;
	} else { // si esta vacia
		return 1;
	}
}

char peek() {
	node *temp = head;
	if (temp != NULL) {
		return temp->n;
	} else {
		return 0;
	}
}

char tipo(){
    char ultimo = peek();
    
    char a = '(';
    char b = '{';
    char c = '[';
    char x = ')';
    char y = '}';
    char z = ']';
    if (ultimo == a){
        return x;
    }
    else if (ultimo == b){
        return y;
    }
    else if (ultimo == c){
        return z;
    }
}

bool esPar(char abre, char cierra) {
	if (abre == '(' && cierra == ')') {
		return true;
	} else if (abre == '{' && cierra == '}') {
		return true;
	} else if (abre == '[' && cierra == ']') {
		return true;
	}

	return false;
}

int parentesisBalanceados(int largo, char expresion[]) {
	int contador = 0;
	for (int i = 0; i < largo; i++) {
		if (expresion[i] == '(' || expresion[i] == '{' || expresion[i] == '[') {
			push(expresion[i]);
		} else if (expresion[i] == ')' || expresion[i] == '}' || expresion[i] == ']') {
			if (isempty() == 1 || esPar(peek(), expresion[i]) == false) {
				printf("Los paréntesis no están balanceados\n");
				printf("Sobra un paréntesis de tipo %c.\n", expresion[i]);
				contador++;
			} else {
				pop();
			}
		}
	}
	if (contador!=0 && isempty()==0){
	    return 0;
	}
	else if (contador==0 && isempty()==1){
	    return 1;
	}
	else if (contador==0 && isempty()==0){
	    return 0;
	}
	else if (contador!=0 && isempty()==1){
	    return 2;
	}
	
}

int main(int argc, char *argv[]) {
    
    //PONER EL ARGUMENTO ENTRE '' CUANDO SE USA ()
    
	if (argc < 2){
	    printf("No ingresó ninguna expresión por consola.\n");
	    return 0;
	}
	
	int l, balance;
	l = strlen(argv[1]);
	
	balance = parentesisBalanceados(l, argv[1]);
	if (balance==1) {
		printf("Los paréntesis están balanceados\n");
	} 
	else if (balance==0){
		printf("Los paréntesis no están balanceados\n");
		printf("Falta un paréntesis de tipo %c.\n", tipo());
	}
	else{
	    printf("No hay mas errores");
	}
	return 0;
}
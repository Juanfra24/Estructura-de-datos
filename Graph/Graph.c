#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge
{
    int startVertex;
    int endVertex;
    struct Edge* next;
}Edge;
typedef struct Vertex
{
	int index;
    struct Vertex* next;
}Vertex;


char ch, buffer[32];

Vertex* hd = NULL;  // Se crea la listas
Edge* head = NULL; 

Edge* crearEdge();
void insertarEdge();
Vertex* crearVertex(int index);
void insertarVertex(int index);

int main(){
	FILE *grafoArchivo;
	grafoArchivo = fopen ("grafo.txt", "r");

	int mayor = 0;
	int i = 0;


	while(1){
	    ch = fgetc(grafoArchivo);
	    
	    if(ch == EOF){
	      break;
	    }
	    
	    else if(ch == ' '){
	    	insertarEdge(); // primer edge
	       	head->startVertex = atoi(buffer);
	       	if (atoi(buffer)>mayor){mayor=atoi(buffer);}
	       	i = 0;

	      	bzero(buffer, 32);
	      	continue;
	    }
	    else if(ch == '\n'){
	    	head->endVertex = atoi(buffer);
	    	if (atoi(buffer)>mayor){mayor=atoi(buffer);}
	    	i = 0;

	    	bzero(buffer, 32);
	      	continue;

	    }
	    else{
	      buffer[i] = ch;
	      i++;
	    }
  	}
  	printf("Archivo leido\n");
  	printf("\n");
	printf("--------------\n");
	printf("\n");
	/*
	for(i = 0; i < 10; i++){
		printf("Number [%d]: %d\n", i, num[i]);
	}
	*/

	printf("Cargando elementos en ED (grafo)...\n");
	//grafo
	
	for (int i = 1; i < mayor+1; ++i)
	{
		insertarVertex(i);
		
	}
	printf("Elementos cargados en ED (grafo)...\n");
	printf("\n");
	printf("--------------\n");
	printf("\n");
	  
	//despliege de grafo
	printf("Despliege de bordes\n");
	printf("\n");

	Edge* aux = head;
	while(aux != NULL){
		printf("%i--%i\n",aux->startVertex,aux->endVertex);
		aux = aux->next;
	}
	printf("--------------\n");
	printf("Despliege de Vertices\n");
	printf("\n");

	Vertex* aux1 = hd;
	while(aux1 != NULL){
		printf("%i\n",aux1->index);
		aux1 = aux1->next;
	}

	printf("--------------\n");
	return 0;
}





Edge* crearEdge(){
    Edge* newptr = (Edge*) malloc(sizeof(Edge));
    newptr->next = NULL;
    return newptr;
}

void insertarEdge()
{
    //crea un nuevo nodo vacio
    Edge* newptr = crearEdge();

    //Verificando si la lista esta vacia
    if (head == NULL)
    {
        head = newptr;
        return;
    }
        //insertar al inicio
    else{
    	newptr->next= head;
    	head = newptr;
    }
}
Vertex* crearVertex(int index){
    Vertex* newptr = (Vertex*) malloc(sizeof(Vertex));
    newptr->next = NULL;
    newptr->index = index;
    return newptr;
}

void insertarVertex(int index)
{
    //crea un nuevo nodo vacio
    Vertex* newptr = crearVertex(index);

    //Verificando si la lista esta vacia
    if (hd == NULL)
    {
        hd = newptr;
        return;
    }
        //insertar al inicio
    else{
    	newptr->next= hd;
    	hd = newptr;
    }
}
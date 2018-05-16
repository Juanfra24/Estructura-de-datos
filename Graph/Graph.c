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
int conocerVecinos(int nodo,int si);
void chichoPopular();
void menu();

int mayor = 0;

int main(){
	menu();

	int nodo;
	scanf("%i",&nodo);

	conocerVecinos(nodo,1);
	
	chichoPopular();

	return 0;
}




void menu(){
	int i = 0;

	FILE *grafoArchivo;
	grafoArchivo = fopen ("grafo.txt", "r");
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
 	head->endVertex = atoi(buffer);
   	if (atoi(buffer)>mayor){mayor=atoi(buffer);}
   	i = 0;
	bzero(buffer, 32);

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

	printf("Escribe el cual quieras buscar a sus vecinos\n");
	fclose (grafoArchivo);
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
int conocerVecinos(int nodo,int si){
	int arregloFinal[mayor];
	int cont = 0;
	Edge* aux = head;
	int brexit = 0;
	while(aux != NULL){
		if (aux->startVertex==aux->endVertex)
		{
			aux= aux->next;

			continue;
		}
		if (aux->startVertex == nodo)
		{

			for (int i = 0; i < cont; ++i)
			{
				if (arregloFinal[i]==aux->endVertex)
				{
					brexit=1;
				}
			}
			if (brexit ==0)
			{
				arregloFinal[cont]=aux->endVertex;
				cont++;
			}
		}
		if (aux->endVertex == nodo)
		{
			for (int i = 0; i < cont; ++i)
			{
				if (arregloFinal[i]==aux->startVertex)
				{
					brexit=1;
				}
			}
			if (brexit ==0)
			{
				arregloFinal[cont]=aux->startVertex;
				cont++;
			}
		}
		brexit = 0;
		aux= aux->next;
	}
	if (si==1)
	{
		for (int i = 0; i < cont; ++i)
		{
			printf("El vertice %i es vecino de %i \n",nodo,arregloFinal[i]);
		}
		if (cont == 0){
			printf("El vertice %i no conecta cono nadie \n",nodo);
		}
	}
	return cont;

}
void chichoPopular(){
	//int cont = 0;
	Edge* aux = head;
	int mayor = -1;
	int elegido[1];
	while(aux != NULL){
		int x= conocerVecinos(aux->startVertex,0);
		if (x > mayor)
		{
			mayor= x;
			elegido[0]=aux->startVertex;
			elegido[1]=mayor;
		}
		x= conocerVecinos(aux->endVertex,0);
		if (x > mayor)
		{
			mayor= x;
			elegido[0]=aux->endVertex;
			elegido[1]=mayor;
		}
		aux= aux->next;
	}
	printf("El Verice mas polular fue el nodo %i \n",elegido[0]);
}
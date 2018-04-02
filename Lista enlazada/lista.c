#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int valor;
	struct nodo* delante;
	struct nodo* detras;


}nodo;

typedef nodo* ptrN;

void anadirElementoPrincipio();
void mostrarLista();
void displayMenu();
int elementosEnLista();
void eliminarElemento();
void clean_stdin();

ptrN HEAD = NULL; // Se crea la lista

int main(){
	
	displayMenu();

	return 0;
}


void displayMenu(){                       /// MENU SACADO DEL CODIGO DE HEADS ENLAZADAS SIMPLES POR Davif J. Malan Y MODIFICADO POR NOSOTORS
	int opcion;
	do
    {
        //imprimir instrucciones
        printf("\nMENU\n\n"
               "1 - insertar nodo\n"
               "2 - mostrar lista\n"
               "3 - borrar nodo \n"
               "4 - elementos en la lista\n"
               "0 - quit\n\n");
        
        // obtener una opción
        printf("Elija una opción: ");
        scanf("%d",&opcion);
        
        // Ejecutar la opción
        switch (opcion)
        {
            case 1: anadirElementoPrincipio(); system("clear"); break;
            case 2: system("clear"); mostrarLista(); break;
            case 3: system("clear"); eliminarElemento(); break;
            case 4: system("clear"); printf("En tu lista hay %i elementos\n",elementosEnLista()); break;
        }
    }
    while (opcion != 0);
    
    //borrando la lista al salir IMPORTANTE LIBERAR MEMORA
    ptrN aux = HEAD;
    while (aux != NULL)
    {
        ptrN auxaux = aux;
        aux = aux->delante;
        free(auxaux);
    }
}

void anadirElementoPrincipio(){
	ptrN aux = HEAD;

	int valor;
	printf("Ingrese un valor para el nodo\n");
	scanf("%i",&valor);

	if (HEAD == NULL){
		ptrN nodoNuevo= (ptrN) malloc (sizeof(nodo));
		nodoNuevo->valor = valor;
		nodoNuevo->delante = NULL;
		nodoNuevo->detras = NULL;
		HEAD = nodoNuevo;
	}

	else{
		ptrN nodoNuevo = (ptrN) malloc (sizeof(nodo));
		nodoNuevo->valor = valor;
		nodoNuevo->delante = aux;
		nodoNuevo->detras = NULL;
		aux->detras = nodoNuevo;
		HEAD = nodoNuevo;

	}

}
void mostrarLista(){

	ptrN aux = HEAD;
	if (aux == NULL){ printf("Tu lista se encuentra vacia\n"); return;}
	char sentido;
	do{
		clean_stdin();
		printf("Ingresa 1 para leer la lista de izquierda a derecha y 2 para leerla de derecha a izquierda: \n");
		scanf("%c",&sentido);
	}while(sentido !='1' && sentido != '2');

	if(sentido == '1'){
		printf("Tu lista es: \n");

		printf("NULL - ");
		while(aux->detras != NULL){
			aux = aux->detras;

		}
		while(aux != NULL){
			printf("%d - ",aux->valor);
			aux = aux->delante;
		}
		printf("NULL");


	}

	if(sentido == '2'){
		printf("Tu lista es: \n");
		printf("NULL - ");
		while(aux->delante != NULL){
			aux = aux->delante;

		}
		while(aux != NULL){
			printf("%d - ",aux->valor);
			aux = aux->detras;
		}
		printf("NULL");
	}
	printf("\n");
	
}
int elementosEnLista(){
	ptrN aux = HEAD;
	int contador = 0;

	while(aux != NULL){
		contador++;
		aux = aux->delante;
	}
	return contador;
}
void eliminarElemento(){
	int numero;
	ptrN aux = HEAD;

	if (elementosEnLista() == 0)
	{
		printf("No hay elementos para eliminar en la lista, porfavor ingrese uno\n");
		return;
	}


	do{
		printf("Ingrese el numero del elemento que desea eliminar, su lista tiene %i elementos \n",elementosEnLista());
		scanf("%i",&numero);

	}while(numero <= 0 || numero>elementosEnLista());

	if (elementosEnLista() == 1 ) // Caso en el que hay un unico elemento en la lista
	{
		free(aux);
		HEAD = NULL;
		return;
	}

	for (int i = 1; i < numero; i++)
	{
		aux = aux->delante;
	}
	if (numero == 1)
	{
		aux->delante->detras = NULL;
		HEAD = aux->delante;
		free(aux);
		return;
	}
	if (numero == elementosEnLista())
	{
		aux->detras->delante = NULL;
		free(aux);
		return;
	}
	else
	{
		aux->detras->delante = aux->delante;
		aux->delante->detras = aux->detras;
		free(aux);
	}

}
void clean_stdin(void)
{
	int c;
	do{
		c = getchar();
	} while(c != '\n' && c != EOF);

}
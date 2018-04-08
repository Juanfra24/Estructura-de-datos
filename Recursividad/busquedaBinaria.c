// Tarea 4C: Búsqueda binaria recursiva/Juegos con recursión  Paul Mardones Y Juan Ternicien


#include <stdio.h>
#include <stdlib.h>

void swap(int* n1, int* n2);
void bubble(int lista[],int n);
void printArray(int arr[], int size);
int calculoMitad(int largo);
void busquedaBinaria(int lista[],int buscado,int mitad, int mitadInicial);

int iterador= 0;


int main(){

	int lista[] = {1};
	int largo = sizeof(lista)/sizeof(lista[0]);
	int mitadInicial = calculoMitad(largo);
	int numeroBuscado = 1;


	//printArray(lista,largo);
	bubble(lista, largo);       // Ordena la lista algoritmo bubble
	//printArray(lista,largo);



	busquedaBinaria(lista,numeroBuscado,calculoMitad(largo), mitadInicial);  //Busca el elemento mediante recursividad

    return 0;

}

void busquedaBinaria(int lista[],int buscado,int mitad,int mitadInicial){
	if(buscado > lista[mitad-1]){
		iterador+=1;
		busquedaBinaria(lista, buscado, mitad + calculoMitad(mitadInicial),calculoMitad(mitadInicial));
	}
	if(buscado < lista[mitad-1]){
		iterador+=1;
		busquedaBinaria(lista, buscado, mitad - calculoMitad(mitadInicial),calculoMitad(mitadInicial));
	}

	if (buscado == lista[mitad-1])
	{
		printf("El numero %i fue encontrado en indice %i iteracion %i \n",buscado,mitad-1,iterador);
		iterador = 0;
	}
}

int calculoMitad(int largo){
	if (largo % 2 == 0){
		return (largo/2);
	}
	else{
		return((largo+1)/2);
	}

}


void swap(int* n1, int* n2){
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;

}
void bubble(int lista[],int largo){
   int i, j;
   int swapped;
   for (i = 0; i < largo-1; i++)
   {
     swapped = 0;
     for (j = 0; j < largo-1-i; j++)
     {
        if (lista[j] > lista[j+1])
        {
           swap(&lista[j], &lista[j+1]);
           swapped = 1;
        }
     }
     if (swapped == 0)
        break;
   }	


}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

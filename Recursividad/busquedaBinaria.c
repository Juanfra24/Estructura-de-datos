#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int* n1, int* n2);
void bubble(int lista[],int n);
void printArray(int arr[], int size);
int calculoMitad(int largo);
void busquedaBinaria(int lista[],int buscado,int mitad, int mitadInicial);

int iterador= 0;


int main(){

	int lista[] = {3,6,2,1,4,8,5,7,9,10,11,12,13,14,15};
	int largo = sizeof(lista)/sizeof(lista[0]);

	int mitadInicial = calculoMitad(largo);


	printArray(lista,largo);
	bubble(lista, largo);
	printArray(lista,largo);

	busquedaBinaria(lista,1,calculoMitad(largo), mitadInicial);

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
		printf("El numero %i fue encontrado en indice %i iteracion %i \n",mitad,mitad-1,iterador);
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
 
     // IF no two elements were swapped by inner loop, then break
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

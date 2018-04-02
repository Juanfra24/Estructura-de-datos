#include <stdio.h>
#include <stdlib.h>

void swap(int* n1, int* n2);
void bubble(int lista[],int n);
void printArray(int arr[], int size);

int main(){

	int lista[] = {12,3,0,53,24,17,88,36};
	int largo = 8;

	printArray(lista,largo);
	bubble(lista, largo);
	printArray(lista,largo);

    return 0;

}

void busquedaBinaria(){
	
}

void swap(int* n1, int* n2){
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;

}
void bubble(int lista[],int largo){
	for(int i = 0; i< largo;i++){
		for(int j=0; j-i-1;j++){
			if(lista[j] > lista[j+1]){
				swap(&lista[j],&lista[j+1]);
			}
		}
	}	


}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

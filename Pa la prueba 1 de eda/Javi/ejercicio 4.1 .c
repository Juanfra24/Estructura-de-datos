#include <stdio.h>
void ordenarnumeros(int numero[], int larg);
int busquedaTernaria(int arreglo[], int min, int max, int buscado);
#include<time.h>
#include <stdlib.h>


int main(void){
    
    int largo;
    
    printf("Introduzca la cantidad de elementos del arreglo \n");
    scanf(" %i", &largo);
    
    int arreglo[largo];
    srand(time(NULL));

    for(int i=0; i<largo; i++){
        arreglo[i]=rand()%20;
       
    }
    
    ordenarnumeros(arreglo, largo);
    
         for(int k=0; k<largo; k++){
        
        printf("%d ", arreglo[k]);
     
    }
    printf("\n");
   printf("Que numero buscas?\n");
    int buscado;
    scanf(" %i",&buscado);
    int encontrado=busquedaTernaria(arreglo,largo/3,(largo/3)*2,buscado);
    
    while (encontrado == -1){
     printf("el numero no se encuentra en el arreglo, ingrese otro numero:\n");
    scanf("%i", &buscado);
    encontrado=busquedaTernaria(arreglo,0,largo,buscado);
    }
    printf("el numero esta en la posicion: %i", encontrado+1);
    
}

void ordenarnumeros(int numero[], int larg){
    int aux;
    for(int i=0; i<larg; i++){

        for(int j=i+1; j<larg; j++){

            if(numero[i] > numero[j]){

                aux = numero[i];
                numero[i] = numero[j];
                numero[j] = aux;

            }
        }
    }


}

int busquedaTernaria(int arreglo[], int min, int max, int buscado){

    if(max>=1){
        
        if(min>max)
        return -1;
        
        if(arreglo[min]==buscado)
        return min;
        
         if(arreglo[max]==buscado)
        return max;
        
        if (buscado < arreglo[min])
        return busquedaTernaria(arreglo,min-1,max,buscado);
        
        if (buscado > arreglo[max])
        return busquedaTernaria(arreglo,min,max+1,buscado);
        
        return busquedaTernaria(arreglo,min+1,max-1,buscado);
    }
    
    return -1;
      
}
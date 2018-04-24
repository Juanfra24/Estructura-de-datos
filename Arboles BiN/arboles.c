#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 5;

typedef struct arbol{
    int n;
    struct arbol* left;
    struct arbol* right;
}arbol;

arbol* root = NULL;

arbol* insertar(arbol* root, int n);
arbol* crearNodo(int n);
void mostrarArbol(arbol* root, int space);
arbol* buscar(arbol* root, int n);
arbol* eliminar(arbol* root, int n);
int alturaAB(arbol* root);
arbol* minValueNode(arbol* node);
int buscarBool(arbol* root, int n);

int main(){
    root = insertar(root, 11); //Ramas principales del juego
    insertar(root, 6);
    insertar(root, 15);

    srand(time(NULL));  // ajustes inicilaes
    int puntaje = 0;

    for(int i = 0; i<4; i++){   //Se inicia el juego con 4 ramas al azar extras
            int n;
            do{
                n=rand()%21;
            }while(buscarBool(root,n)!=0);
            insertar(root, n);
    }
    for(;;){  // Ciclo del juego

        if(alturaAB(root)>5) break; // condicion para perder 


        mostrarArbol(root, 0);
        printf("\nAltura: %d\n", alturaAB(root));
        printf("\nQue parte del arbol quieres eliminar?\n"); //display del menu


        int decision;
        do {
            scanf("%d", &decision);
            if(decision==11) printf("\nNo puedes eliminar la raiz!\n");  // Se toma la jugada del usuario
        }while(decision == 11);


        if (decision == 15 || decision == 6) // Si se eliminan una de estas dos ramas, ademas se eleminaran dos extra al azar
        {
            eliminar(root, decision);
            int n;
            for (int i = 0; i < 2; ++i)
            {
                do{
                    n=rand()%21;
                }while(buscarBool(root,n)==0 || n == 11);
                eliminar(root,n);
            }
        }
        else{
            eliminar(root, decision);  // Si no se elimina la decidida
        }


        for(int i=0; i<2; i++){       //Ciclo que hace crecer dos ramas al azar
            int n;
            do{
                n=rand()%21;
            }while(buscarBool(root,n)!=0);
            insertar(root, n);
        }
        printf("\n\n\n");
        puntaje++;
    }
    mostrarArbol(root, 0);
    printf("\nAltura: %d\n", alturaAB(root)); // Display Game over :(
    printf("\nPerdiste :c\n");
    printf("Tu puntaje fue de : %i\n", puntaje);
}

arbol* crearNodo(int n){
    arbol* ptrnew = (arbol*)malloc(sizeof(arbol));
    ptrnew->n = n;
    ptrnew->right = NULL;
    ptrnew->left = NULL;
    return ptrnew;
}
arbol* insertar(arbol* root, int n){

    if(root == NULL){
        return crearNodo(n);
    }
    if(n <= root->n) root->left = insertar(root->left, n);
    else
    if(n > root->n)  root->right = insertar(root->right, n);
    return root;
}

void mostrarArbol(arbol* root, int space){
    if(root == NULL) return;
    space+= COUNT;
    mostrarArbol(root->right, space);
    printf("\n");
    int i = COUNT;
    while(i<space){
        printf(" ");
        i++;
    }
    printf("%d\n", root->n);

    mostrarArbol(root->left, space);
}

arbol* buscar(arbol* root, int n){
    if(root == NULL || root->n == n) return root;

    if(root->n <= n) return buscar(root->right, n);

    return buscar(root->left, n);
}
int buscarBool(arbol* root, int n){
    if(root == NULL) return 0; 
    if(root->n == n) return 1; // 0 falso - 1 verdadero

    if(root->n <= n) return buscarBool(root->right, n);

    return buscarBool(root->left, n);
}

arbol* eliminar(arbol* root, int n){
    if(root == NULL) return root; //caso base

    if(n < root->n) root->left = eliminar(root->left, n); //si es n es menor que root
    else
    if(n > root->n) root->right = eliminar(root->right, n);// si n es mayor que root
    else{ //si no se cumple lo anterior es el que hay que eliminar
        if(root->left == NULL){
            arbol* tmp = root->right;
            free(root);
            return tmp;
        }
        else
        if(root->right == NULL){
            arbol* tmp = root->left;
            free(root);
            return tmp;
        }

        arbol* tmp = minValueNode(root->right);
        root->n = tmp->n;
        root->right=eliminar(root->right, tmp->n);
    }
    return root;
}


int alturaAB(arbol* root)
{
    int AltIzq, AltDer;

    if(root==NULL)
        return 0;
    else
    {
        AltIzq = alturaAB(root->left);
        AltDer = alturaAB(root->right);

        if(AltIzq>AltDer)
            return AltIzq+1;
        else
            return AltDer+1;
    }
}

arbol* minValueNode(arbol* node){
    arbol* current = node;
    while(current->left != NULL)
        current = current->left;
    return current;
}
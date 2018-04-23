#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct arbol
{
    int n;
    struct arbol* left;
    struct arbol* right;
}arbol;

arbol * instertar(arbol * root, int numero);
arbol* crearNodo(int x);
void verArbol(arbol * root, int n);
int alturaAB(arbol * root);

int main(int argc, char const *argv[])
{
	arbol * root = NULL;
	root = instertar(root, 22);
	root = instertar(root, 14);
	root = instertar(root, 12);
	root = instertar(root, 36);
	root = instertar(root, 25);
	root = instertar(root, 66);
	root = instertar(root, 16);
	root = instertar(root, 255);
	verArbol(root,2);
	printf("%i\n",alturaAB(root));


	
	return 0;
}


arbol * instertar(arbol * root, int numero){
	arbol * temp = root;
	arbol * newN = crearNodo(numero);
	if(temp == NULL){
		return newN;
	}
	if(numero <= root->n){
		root->left = instertar(root->left,numero);
	}
	if(numero > root->n){
		root->right = instertar(root->right,numero);
	}
	return root;


}

arbol* crearNodo(int x){
    arbol* newptr = (arbol*) malloc(sizeof(arbol));
    newptr->right = NULL;
    newptr->left = NULL;
    newptr->n = x;
    return newptr;
}

void verArbol(arbol * root, int n)
{

     if(root==NULL)
          return;
     verArbol(root->right, n+1);

     for(int i=0; i<n; i++)
         printf("   ");

     printf("%i\n",root->n);

     verArbol(root->left, n+1);
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
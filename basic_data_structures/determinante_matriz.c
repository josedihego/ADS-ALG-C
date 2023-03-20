#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void preencheMatriz(int** , int, int);
int determinante(int **,int,int);

int main(){
    int **matriz;
    int m,n;
     int i,j;
     printf("digite as dimensoes da matriz:\n");
     scanf("%d %d",&m,&n);
     if (m!=n){
         printf("nao e possivel calcular o determinante da matriz\n");
         printf("dimensoes \"m\" e \"n\" da matriz sao diferentes.\n");
     }   
     else{
          //---------PONTO CORRIGIDO-----------------
           // primeiro aloca-se espações para os ponteiros
           //atente para o size of
           matriz = (int **) malloc(m* sizeof(int*));
          // depois para cada linha(ponteiro para ponteiro) aloca-se 
          //as posições para o número de inteiros na coluna
          // atente para o for
          // atente para o sizeof
           for(i=0; i<m; i++) 
                   matriz[i] = (int*)malloc(m *sizeof(int));
           //---------FIM ONTO CORRIGIDO-----------------
           preencheMatriz(matriz,m,n);
           printf("\nmatriz:\n");
           for (i=0;i<m;i++){
	          for (j=0;j<n;j++){
                  printf("%d\t",matriz[i][j]);
              }
               printf("\n");
           }
            free(matriz);
         
     }
    
     system("pause");   
     return 0;


}
void preencheMatriz(int **matriz,int m,int n){
    int i,j;

    for (i=0;i<m;i++){
	   for (j=0;j<n;j++){
           printf("digite o elemento %d %d da matriz:\n",(i+1),(j+1));
           scanf("%d",&matriz[i][j]);
       }
    }
}
           

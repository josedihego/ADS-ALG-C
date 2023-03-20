#include <stdio.h>
#include <stdlib.h>

int ehPalindromo(char * c)
{
 int tam = strlen(c);
 int j;
 
 if(!(tam%2))
 {
     for(j=0; j < tam/2; j++)
     {
         if(c[j]!= c[tam-1-j])
         {
          return 0;         
         }
     }
    return 1;         
 }   
 else{
      return 0;
 }
}
//
//int main(void)
//{
//  printf("%d\n",ehPalindromo("Ola")); //0  
//  printf("%d\n",ehPalindromo("olaalo"));//1
//  printf("%d\n",ehPalindromo("oooo"));   //1
//  printf("%d\n",ehPalindromo("abc"));   //0
//  printf("%d\n",ehPalindromo("abccba"));   //1
//  printf("%d\n",ehPalindromo("A"));   //0
//  system("pause");
//}

void escrever(FILE * p)
{
     char *s;
     int fim= 0;
     int tam;
     while(!fim){
     printf("digite o tamanho da string\n");
     scanf("%d", &tam);
     s = (char *) malloc(tam* sizeof(char));            
     printf("digite a string\n");
     getchar();
     gets(s);
         if(!ehPalindromo(s))
         {
            fputs(s,p);                 
            fputs("\n",p);
         }
         else
         {
             fim= 1;
         }
      free(s); 
     }
   fclose(p);  
}

void ler(FILE* p)
{
     char c;
     while(!feof(p))
     {
       printf("%c",getc(p));            
     }
}

//int main(void)
//{
//    FILE* p = fopen("OUT.tex","a+t");
//    //escrever(p);
//    ler(p);
//    system("pause");
//}


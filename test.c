#include <stdio.h>
#include <stdlib.h>
#include "structs.c"

int main(){
    agMedico lucas;
    int fim;

    preencheMedicos(&lucas);


    for(int i = 0; lucas.nome[i] != '\0'; i++){
        printf("%c", lucas.nome[i]);
    }

    printf("\n");

    for(int i = 0; lucas.especialidade[i] != '\0'; i++){
        printf("%c", lucas.especialidade[i]);
    }

    
    //Aparentemente é necessário por esse expoço para evitar
    //a exibição de "lixo" que esta na memoria
    printf("\n");
   /* printf("tortona\n");

    printf("\n");

   
    for(int i = 0; i < dim; i++){
        scanf("%c", &lucas.nome[i]);

        if(lucas.nome[i] == '.'){
            fim = i;
            i = dim;
            lucas.nome[i] = ' ';
        }
    }

    printf("\n");

    
    
 
    for(int i; i < dim; i++){
        printf("%c", lucas.nome[i]);
    }

    
    */

    return 0;
}
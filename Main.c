#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "procuraMedicos.c"


void finalDeArquivo(FILE *);


int main(){
    agMedico lucas;
    char str[dim];
    FILE *arqSaida, *arqEntrada, *arqLista;

    if (!(arqEntrada = fopen ("entrada/dadosMedicos.txt", "r"))){
        printf("ERRO \n");
        exit(1);
    }

     if (!(arqLista = fopen ("entrada/listaPacientes­Semana2.txt", "r"))){
        printf("ERRO \n");
        exit(1);
    }


    preencheMedico(&lucas, arqEntrada, arqLista);
    //preencheMedico(&lucas, arqEntrada, arqLista);
    //preencheMedico(&lucas, arqEntrada, arqLista);

    //aleatorio(&lucas);


    //nomesListas(arqEntrada &lucas);
    


    //procuraMedico(&lucas);

    //finalDeArquivo(arqEntrada);

    return 0;
}

void finalDeArquivo(FILE *arqEntrada){
  char test[dim];

  if (!(arqEntrada = fopen("entrada/dadosMedicos.txt", "r"))){
      exit(1);
  }



  while(!feof(arqEntrada)){
    fgets(test, 30, arqEntrada);
    printf("%s \n", test);
  }
}


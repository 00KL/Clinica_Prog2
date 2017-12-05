#include <stdio.h>
#include <stdlib.h>
#include "procuraMedicos.c"

void finalDeArquivo(FILE *);


int main(){
    agMedico lucas;

    FILE *arqSaida, *arqEntrada;

    procuraMedico(&lucas);

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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//arquivos com funções necessárias
#include "preenche.c"

//Funções usadas nesse arquivo
void finalDeArquivo(FILE *);


int main(){
    //Criação de objeto medico
    agMedico medico;
    cliente paciente;

    //variaveis necessárias
    FILE *arqSaida, *arqEntrada, *arqLista;



    preencheMedi(&medico, arqEntrada, arqLista, &paciente);
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

//Bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>

//Aquivos necessarios
#include "structs.c"

void linhaEspecifica(FILE *medico, int linha, char *str){
  int contador = 0;
  char lixo[50];
  while(!feof(medico)){
    contador++;
    if(contador == linha){
      fgets(str, 30, medico);
    }
    else{
      fgets(lixo,50, medico);
    }

    exibeStr(str);
  }

}


void pedirLinha(FILE *medico, char *str){
  scanf("%d", linha);
  linhaEspecifica(medico, linha, str);
}

//funcao para criar a tabela de horarios
void leitura(){
  //variaveis
  FILE *medico;
  char str[dim], str1[dim+7] = "dados/";

  //leitura dos dados do medicos
  medico = fopen ("dados/dadosMedicos.txt","r" );

  pedirLinha(medico, str);
  //fgets(str, 30, medico);

  //strcat(str1, str);

  //medico = fopen (str1, "w+");

  //exibeStr(str1);

}
